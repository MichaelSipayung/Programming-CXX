/*templates : foundation for generic programming in c++
 * function template
 * class template
 */
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <algorithm>
#include <vector>
using std::vector;
#include <cstring>
#include <memory>
#include <sstream>
using std::ostringstream;
class Test_Template {
public:
  Test_Template() = default;
  Test_Template(const int &arg1, const double &arg2, const std::string &arg3)
      : x{arg1}, y{arg2}, z{arg3} {}
  void compare_test() const;
  void compare_str() const;

private:
  int x;
  double y;
  std::string z;
};
template <typename T> int compare(const T &v1, const T &v2) {
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return 1;
  return 0;
}
template <typename T> T foo(T *p) {
  T tmp = *p; // tmp will have the type to which p points
  return tmp;
}
// nontype template parameters
template <unsigned N, unsigned M>
int compare_s(const char (&p1)[N], const char (&p2)[M]) {
  return strcmp(p1, p2);
}
inline void sigma() {
  auto temp = 0.0;
  cout << "optimize small .." << endl;
}
// inline function template
template <typename T> inline T min(const T &str_1, const T &str_2) {
  T tmp = str_1;
  return tmp;
}
// writing type-independent code
// allowing compare two pointer
// minimize the operator requirement for template
template <typename T> int compare_ind(const T &v1, const T &v2) {
  if (std::less<T>()(v1, v2))
    return -1;
  if (std::less<T>()(v2, v1))
    return 1;
}

template <typename T> class Blob_T {
  friend void templ_cl_test();

public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;
  typedef typename std::vector<T>::iterator iterator;
  // type dependent using typedef to tell the compiler what the type that
  // we will use
  // ctor
  Blob_T();
  Blob_T(std::initializer_list<T> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const T &t) { data->push_back(t); }
  void push_back(T &&t) { data->push_back(std::move(t)); }
  void pop_back();
  T &back();
  iterator begin(); //{return data->begin();}
  iterator end();   //{return data->end();}
  T &operator[](size_type i);

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};
// begin with typename followed with the type for
// members that are types
template <typename T> typename Blob_T<T>::iterator Blob_T<T>::begin() {
  return data->begin();
}
template <typename T> typename Blob_T<T>::iterator Blob_T<T>::end() {
  return data->end();
}
inline void templ_cl_test() {
  Blob_T<int> num_version = {1, 2, 3, 4, 5};
  num_version.push_back(12);
  cout << "begin(int) : " << *num_version.begin() << endl;
  Blob_T<string> str_version = {"jack", "miller", "thomas"};
  str_version.push_back("walker");
  cout << "end (str): " << *(str_version.end() - 1) << endl;
  // instantiation of class template member function
  // instantiates blob_t<int> and init_list<int> ctor
  Blob_T<int> nat_num = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  // ins.. blob<int>::size()const
  for (size_t i = 0; i != nat_num.size(); ++i)
    nat_num[i] = i * i; // ins .. blob<int>::operator[](size t)
}
// ctor defenition
template <typename T>
Blob_T<T>::Blob_T() : data{std::make_shared<vector<T>>()} {}

template <typename T>
Blob_T<T>::Blob_T(std::initializer_list<T> il)
    : data{std::make_shared<vector<T>>(il)} {}

// definition of member class template
template <typename T>
void Blob_T<T>::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}
template <typename T> T &Blob_T<T>::back() {
  check(0, "back on empty blob");
  return data->back();
}
template <typename T> inline T &Blob_T<T>::operator[](size_type i) {
  check(i, "subscript out of range");
  return (*data)[i];
}
template <typename T> inline void Blob_T<T>::pop_back() {
  check(0, "pop_back on empty blob");
  data->pop_back();
}
// thrown an exception on attempts to acc nonexistent element
template <typename T> class BlobPtr_T {
public:
  BlobPtr_T() : curr{0} {}
  BlobPtr_T(Blob_T<T> &a, size_t sz = 0) : wptr{a.data}, curr{sz} {}
  T &operator*() const {
    auto p = check(curr, "dereference past the end");
    return (*p)[curr]; //(*p) is the vector to which this obj points
  }
  BlobPtr_T &operator++(); // prefix op
  BlobPtr_T &operator--();
  BlobPtr_T &operator++(int);
  BlobPtr_T &operator--(int);

private:
  // check returns a shared_ptr to the vec if check succeeds
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
  // store a weak_ptr, which means the underlying vec might be destroy
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr; // current position within the array
};
// using  a class template name outside the class template body
// postfix op
template <typename T> BlobPtr_T<T> &BlobPtr_T<T>::operator++(int) {
  BlobPtr_T ret = *this; // save the current val
  ++*this;               // advance one element; pref ++check the inc
  return ret;            // ret the saved state
}
template <typename T> BlobPtr_T<T> &BlobPtr_T<T>::operator--(int) {
  BlobPtr_T ret = *this;
  --*this;
  return ret;
}
template <typename T> BlobPtr_T<T> &BlobPtr_T<T>::operator++() {
  return ++*this;
}
template <typename T> BlobPtr_T<T> &BlobPtr_T<T>::operator--() {
  return --*this;
}
// one to one friendship
template <typename> class BlobPtr_N;
template <typename> class Blob_N; // needed for param in op ==
template <typename T> bool operator==(const Blob_N<T>, const Blob_N<T> &);
template <typename T> class Blob_N {
  // each instantiation of blob grant access to version of
  // Blobptr and equality operator instantianted with the same type
  friend class BlobPtr_N<T>;
  friend bool operator==<T>(const Blob_N<T> &, const Blob_N<T> &);
};
// template static member
template <typename t> class Foo_St {
public:
  Foo_St() {}
  static std::size_t count(); //{return ctr;}
                              // other interface members
private:
  static std::size_t ctr;
  // other implementation members
};
// defenition of static member on template class
template <typename T>
std::size_t Foo_St<T>::ctr = 0; // define and initialize ctr
template <typename T> std::size_t Foo_St<T>::count() { return ++ctr; }
// more than one param
template <typename T, typename Obj> class Book_Str {
public:
  Book_Str() {}
  // using class member that are types
  typedef std::string::size_type type;
  // tell the compiler that we use this member as type
  typedef typename std::vector<T>::iterator iterator;
  iterator begin();
  type show_all();
  typedef T name;
  // ctor
  Book_Str(const std::vector<T> &val) : data{val} {}
  name show_curr() const;

private:
  unsigned t_buy;
  std::string initial_name;
  std::vector<double> data;
};
// inform compiler that a name represents a type
// using keyword typename
template <typename T, typename Obj>
typename Book_Str<T, Obj>::iterator Book_Str<T, Obj>::begin() {
  return data.begin();
}
template <typename T, typename Obj>
typename Book_Str<T, Obj>::type Book_Str<T, Obj>::show_all() {
  return typename Book_Str::type();
}

template <unsigned M, unsigned N> class MatD {
public:
  MatD() {}
  void resize(unsigned row, unsigned cols) const;

private:
  int aux_mem;
};
// using default argument
// comp has default template argument, less<t>
template <typename T, typename F = std::less<T>>
int compare_Def(const T &v1, const T &v2, F f = F()) {
  if (f(v1, v2))
    return -1;
  if (f(v2, v1))
    return 1;
  return 0;
}
template <typename T> T great(const T &x = T()) { return x; }
// default arguments and class template
template <typename T = int> class Numbers { // by default T is int
public:
  Numbers(T v = 0) : val(v) {}

private:
  T val;
};
// member template of ordinary class
class DebugDelete_T {
public:
  DebugDelete_T(std::ostream &s = std::cerr) : os{s} {}
  // as with any function template, the type of T is deduced by the compiler
  template <typename T> void operator()(T *p) const {
    os << "deleting uniquie ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};
// member template of class templates
template <typename T> class Blob_Mem_T {
public:
  Blob_Mem_T() {}
  template <typename It>
  Blob_Mem_T(It beg, It end)
      : data{std::make_shared<std::vector<T>>(beg, end)} {}
  void show_mem() const {
    auto begin = data->begin();
    auto end = data->end();
    while (begin != end) {
      cout << *begin << " ";
      ++begin;
    }
  }

private:
  std::shared_ptr<std::vector<T>> data;
};
// allowing conversion on the arguments
template <typename A, typename B> int compare_T(const A &v1, const B &v2) {
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return 1;
  return 0;
}
// rvalue arguments on template
template <typename T> void rval_T(T &&val) {
  T t = val; // copy or binding a reference
  if (val == t)
    cout << "always true if t is reference type .. " << endl;
}
// writting overload templates
template <typename T> string debug_rep(const T &t) {
  ostringstream ret;
  ret << t;         // uses T's out op to print a representation of t
  return ret.str(); // return a cp of the str which ret is bound
}
// the second version
template <typename T> string debug_rep(T *p) {
  ostringstream ret;
  ret << "pointer: " << p; // print the pointer's own value
  if (p)
    ret << " " << debug_rep(*p); // print the value to which p points
  else
    ret << " null pointer"; // or indicate that the p is null
  return ret.str();         // return a cp of the str to which ret is bound
}
// variadic templates
template <typename T, typename... Args>
void varia_temp(const T &, const Args... rest) {
  cout << "variadic template" << endl;
}
// the sizeof operator example
template <typename... Args> void g_temp(Args... args) {
  cout << "using sizeof : " << endl;
  cout << sizeof...(Args) << endl; // number of type parameters
  cout << sizeof...(args) << endl; // number of function parameters
}
#endif