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
using std::end;
using std::find;
namespace Refac {
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
  auto result = find(cbegin(x), cend(x), val); //return iterator to the pos of val
  cout << "template version (the value) : "
       << (result == cend(x) ? "is not present" : "is present") << endl;
}
} // namespace Refac
#endif