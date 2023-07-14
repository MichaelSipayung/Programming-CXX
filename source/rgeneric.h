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
using std::begin; // using independent begin
using std::cbegin;
using std::cend;
using std::copy;
using std::end;
using std::equal; // compare algorithm
using std::fill;  // fill the element with new val
using std::find;
using std::sort;        // sort algorithm
using std::stable_sort; // keep the order alphabetically
using std::unique;      // find unique element
#include <numeric>
using std::accumulate;
#include <iterator>
using std::back_inserter; // insert element on a container at the end
typedef vector<string>::size_type size_type;
namespace Refac {
// read only algorithm
void useFind(const vector<int> &x, const int &val) {
  auto result = find(x.cbegin(), x.cend(), val);
  cout << "the value " << val
       << (result == x.cend() ? " is not present" : " is present") << endl;
}
// find algorithm, overload version for handle string
void useFind(const list<string> &x, const string &val) {
  auto result = find(x.cbegin(), x.cend(), val);
  cout << "the value " << val
       << (result == x.cend() ? " is not present" : " is present") << endl;
}
// find algorithm : return iterator to the element if it found
// otherwise return one past the last element
template <typename Container, typename Object>
void useFindAl(const Container &x, const Object &val) {
  auto result =
      find(cbegin(x), cend(x), val); // return iterator to the pos of val
  cout << "template version (the value) : "
       << (result == cend(x) ? "is not present" : "is present") << endl;
}
// find total number of element on a container
template <typename Object>
Object &totalAlg(const vector<Object> &x, Object &init) {
  init = accumulate(x.cbegin(), x.cend(), init);
  return init;
}
// compare algorithm, return is equal or not
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
// eliminate duplicate element, first call sort then call unique
// then use erase function to actually remove nonunique element
template <typename Container> void elimDupsAlg(Container &_x) {
  sort(_x.begin(), _x.end());
  // reorder the element so that each word appears once
  // return an iterator one past the unique range
  auto end_unique = unique(_x.begin(), _x.end());
  // remove the nonunique elements
  _x.erase(end_unique, _x.end());
}
// passing a function to an algorithm
// predicates
// comparison function to be used to sort by word length
bool isShorterAlg(const string &_x, const string &_y) {
  return _x.size() < _y.size();
}
// calling sort with predicate, in this case we use binary predicate
// for vector<string> and list<string>
void sortElPredicate(vector<string> &_x) {
  sort(_x.begin(), _x.end(), isShorterAlg);
}
// stable sort: keep the order alphabetically
void stableSortAlgPred(vector<string> &_x) {
  // eliminate the duplicate first
  elimDupsAlg(_x);
  // the calling stable sort with predicate to maintain the order of item
  stable_sort(_x.begin(), _x.end(), isShorterAlg);
}
// lambda expression
void defineLambda() {
  auto f = [] { return 42; };
  cout << "show f() value which defined by lambda expression : " << f() << endl;
}
// test stable_sort using lamda expression
void stableTestLambda(vector<string> &_x) {
  stable_sort(_x.begin(), _x.end(), [](const string &_a, const string &_b) {
    return _a.size() < _b.size();
  });
}
// using capture list in a lambda
void capListLambda(const int &_sz) {
  auto f = [_sz](const string &_x) { return _x.size() >= _sz; };
  cout << "test capture list on a lambda : " << f("michael") << endl;
}
// problem solving using lambda expression on algorithm
// finding the string which has a size greater than _sz on a container
void solveUsingCapList(vector<string> &_x, const int &_sz) {
  // using find if with the third arg as predicate or lambda expression
  // return an iterator to the first element whose size > _sz
  stable_sort(_x.begin(), _x.end());
  // remove the nonunique element
  auto end_unique = unique(_x.begin(), _x.end());
  _x.erase(end_unique, _x.end());
  cout << "total element after calling erase : " << _x.size() << endl;
  // then find the element
  auto wc = find_if(_x.begin(), _x.end(),
                    [_sz](const string &_wd) { return _wd.size() >= _sz; });
  // count the difference or total element greater than _sz
  auto count = _x.end() - wc;
  cout << "total difference  : " << count << " and the value : " << endl;
  // show all the difference using for_each
  using std::for_each;
  for_each(wc, _x.end(), [](const string &word) { cout << word << " |"; });
  cout << endl;
}
// using std::for_each algorithm to show all element on a container
template <typename Object> void testForeachAlg(const vector<Object> &_x) {
  using std::for_each;
  for_each(_x.begin(), _x.end(),
           [](const Object &_word) { std::cout << _word << std::endl; });
}
// bigges: find the element whose size is greater than _sz
// using lamda expression and show the all value using for_each
void biggesAlg(vector<string> &_x, size_type _sz) {
  // first put the words in alphabetical order
  // then remove the nonunique elements
  elimDupsAlg(_x);
  // sort word by size, but maintain alphabetical order for word of
  // the same size
  stable_sort(_x.begin(), _x.end(), [_sz](const string &_a, const string &_b) {
    return _a.size() < _b.size();
  });
  // get an iterator to the first element whose size is >=size
  // debugging for _sz: passing
  auto wc = find_if(_x.begin(), _x.end(),
                    [_sz](const string &_a) { return _a.size() >= _sz; });
  // compare the number of elements with size>=_sz
  auto count = _x.end() - wc;
  cout << "found total element : " << count << endl;
  // print words given size or longer, followed by space
  for_each(wc, _x.end(), [](const string &_a) { cout << _a << " "; });
  std::cout << "----" << std::endl;
}
// capture by value lambda expression
void capByVaLambda(const size_t _val) {
  // copies _val into the callable object
  auto f = [_val] { return _val; };
  // show the value after capture to the lambda
  cout << "value : " << f() << endl;
}
// capture by reference lambda expression
void capByRefLambda(std::ostream &os) {
  // capture list contain ostream which can't be copy
  auto f = [&os] {
    os << "hello wordl: tested for capture by reference" << endl;
  };
  // call the lambda with capture list as a reference
  f();
}
} // namespace Refac
#endif
