#include "strvec.h"
using namespace Adv;
allocator<string> StrVec::alloc;
inline void StrVec::chk_n_alloc() {
  if ((size() == capacity()))
    reallocate();
}
inline void StrVec::push_back(const string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}
inline void StrVec::push_back(string &&s) {
  chk_n_alloc(); // ensure there is room for ant el
  alloc.construct(first_free++, std::move(s));
}
inline pair<string *, string *> StrVec::alloc_n_copy(const string *b,
                                                     const string *e) {
  auto data = alloc.allocate(b - e);
  return {data, uninitialized_copy(b, e, data)};
}
inline void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements;)
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}
inline StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}
inline void StrVec::reallocate() {
  auto newcap = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcap);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcap;
}
StrVec::StrVec(StrVec &&s) noexcept
    : elements{s.elements}, first_free{s.first_free}, cap{s.cap} {
  s.elements = s.first_free = s.cap =
      nullptr; // leave s in a state in which it is safe to run dctor
}
StrVec &StrVec::operator=(StrVec &&s) noexcept {
  if (this != &s) {
    free();
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    // leave rhs in a destructible state
    s.elements = s.first_free = s.cap = nullptr;
  }
  return *this;
}