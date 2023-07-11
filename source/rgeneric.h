#ifndef GENERIC_REFACTOR_H
#define GENERIC_REFACTOR_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
using std::begin;
using std::cbegin;
using std::cend;
using std::copy;
using std::end;
using std::equal;
using std::fill;
using std::find;
#include <numeric>
using std::accumulate;
#include <iterator>
using std::back_inserter; // insert element on a container at the end
namespace Refac {
// read only algorithm
void useFind(const vector<int> &x, const int &val) {
  auto result = find(x.cbegin(), x.cend(), val);
  cout << "the value " << val
       << (result == x.cend() ? " is not present" : " is present") << endl;
}
void useFind(const list<string> &x, const string &val) {
  auto result = find(x.cbegin(), x.cend(), val);
  cout << "the value " << val
       << (result == x.cend() ? " is not present" : " is present") << endl;
}
template <typename Container, typename Object>
void useFindAl(const Container &x, const Object &val) {
  auto result =
      find(cbegin(x), cend(x), val); // return iterator to the pos of val
  cout << "template version (the value) : "
       << (result == cend(x) ? "is not present" : "is present") << endl;
}
template <typename Object>
Object &totalAlg(const vector<Object> &x, Object &init) {
  init = accumulate(x.cbegin(), x.cend(), init);
  return init;
}
template <typename Object>
bool equalAlg(const vector<Object> &x, const vector<Object> &y) {
  return (equal(x.cbegin(), x.cend(), y.cbegin()));
}
// write to the element
template <typename Object>
void fillAlg(vector<Object> &_x, const Object &_val) {
  fill(_x.begin(), _x.end(), _val);
}
// insert element using back_inserter
// place on the end of container
template <typename Object>
void fillAtTheEnd(vector<Object> &_x, const Object &_val) {
  auto it = back_inserter(_x);
  *it = _val;
}
// copy from container
// fill the element on other container
template <typename Object>
void copyAlg(const vector<Object> &_x, vector<Object> &_y) {
  if (_x.size() > _y.size()) {
    cout << "check the size of vector !!!!!" << endl;
    return;
  }
  copy(_x.begin(), _x.end(), _y.begin());
}
// replace each element on a container
// calling replace copy to avoid rewrite the element
// the second arg is value to replace with the third arg
template <typename Object>
void replaceAlg(vector<Object> &_x, const Object &_curr, const Object &_val) {
  replace(_x.begin(), _x.end(), _curr, _val);
}
} // namespace Refac
#endif