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
using std::back_inserter;  // insert element on a container at the end
using std::front_inserter; // insert on the front
using std::inserter;       // insert val with specific location
#include <functional>
using std::bind; // binding argumens
typedef vector<string>::size_type size_type;
namespace Refactor {
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
// implicit capture, lambda expression
void implicitCapLamda(const vector<string> &_x, const int &_sz) {
  // capture by value using = and by reference using &
  // find_if the items size is greater than _sz
  auto wc = find_if(_x.begin(), _x.end(),
                    [=](const string &_word) { return _x.size() >= _sz; });
}
// mutable lambda: by default lamda can't change the capture list which
// is capture by value
void mutableLamda(size_t &_sz) {
  // increase value inside lambda expression using mutable keyword
  auto f = [_sz]() mutable { return ++_sz; };
  cout << "current value : " << f() << endl;
}
// specifying the lambda return type for
// the problem involve more than one statement
void explicRet(vector<int> &_x) {
  using std::transform;
  // using library transform to transform each item to its absolute value
  transform(_x.begin(), _x.end(), _x.begin(), [](const int &_val) -> int {
    if (_val < 0)
      return -_val;
    else
      return _val;
  });
}
// checkSize: check the size of given string
bool checkSizeBnd(const string &_x, size_type _sz) { return _x.size() >= _sz; }
// bind function: general purpose function adaptor
// solve the limited version of lambda expression
void bindArgs(const string &_x) {
  using std::placeholders::_1;
  auto check = bind(checkSizeBnd, _1, 6);
  bool test = check(_x);
  cout << "binding arguments : " << test << endl;
}
// test on algorithm: using bind
// showing the first match item which has size greater than _sz
void showMatchWord(const vector<string> &_x, const int &_sz) {
  // binding arguments using bind
  using std::bind;             // for binding the arguments
  using std::placeholders::_1; // stand for the first arguments
  // store the match items
  auto matchIterator =
      find_if(_x.cbegin(), _x.cend(), bind(checkSizeBnd, _1, _sz));
  // show it to standart output
  for_each(matchIterator, _x.cend(),
           [](const string &_a) { cout << _a << "|"; });
  std::cout << "------" << std::endl;
}
// arguments to bind, callable object
// reorder parameter using bind
void argsToBind(vector<string> &_x) {
  using namespace std::placeholders;
  // reorder arguments, isShorterAlg(B,A) != isShorterAlg(A,B);
  sort(_x.begin(), _x.end(), bind(isShorterAlg, _2, _1));
  for (const auto &item : _x)
    cout << item << " | ";
  cout << endl;
}
// explicitly think about bind arguments
void argsArrage(const string &_x, const int &_y) {
  cout << "x value : " << _x << endl;
  cout << "y value : " << _y << endl;
}
// test using arguments on bind
void testArrArgs() {
  using namespace std::placeholders;
  auto temp = bind(argsArrage, _2, _1);
  temp(14, "miller");
}
// iterator: back_inserter, front_inserter and inserter
void iterWork(const list<string> &_x) {
  list<string> _y, _z;
  // copy element and put on the front
  //_y containt last el, last el-1, the first of the _x
  copy(_x.begin(), _x.end(), front_inserter(_y));
  // specify the element we want to insert
  //_z contain first el, next, and the end of _x element
  copy(_x.begin(), _x.end(), inserter(_z, _z.begin()));
  // debugging for front inserter
  cout << "front inserter version : ";
  for (const auto &item : _y)
    cout << item << " | ";
  cout << endl;
  // debugging for inserter
  cout << "inserter version : ";
  for (const auto &item : _z)
    cout << item << " | ";
  cout << endl;
}
// stream iterator: istream_iterator, ostream_iterator<T>
void istIterator() {
  using std::istream_iterator;
  using std::ostream_iterator;
  // define istream_iterator
  cout << "input number : ";
  // assign _eof from _in which read from standard input
  istream_iterator<int> in(cin), eof;
  // using accumulate
  cout << "result: " << accumulate(in, eof, 0) << endl;
}
// ostream iterator, operator = is use to assign val to the ostream
void ostIterator(const vector<int> &_x) {
  // define ostream_iterator
  ostream_iterator<int> out_iter(cout, " ");
  // assign and then show to standard output
  for (const auto &item : _x)
    *out_iter++ = item; // assign all item on _x to ostream
  cout << endl;
}
// reverse iterator:crbegin, crend, rbegin and rend
// traverse element from right to left
template <typename Container> void reversIterator(const Container &_x) {
  auto begin = _x.rbegin(); // pos right, non const version
  auto end = _x.rend();     // pos left
  // show on standard output
  while (begin != end)
    cout << *begin++ << " | ";
  cout << endl;
}
// application: sort in reverse, the small element located on the last
template <typename Container> void reverSort(Container &_x) {
  sort(_x.rbegin(), _x.rend()); // calling sort function
}
// algorithm naming conventions
// using two version of reverse
template <typename Container>
void reverseElement(Container &_x, Container &_y) {
  using std::reverse;
  using std::reverse_copy;
  // reverse element _x
  reverse(_x.begin(), _x.end());
  // copy element in reverse order
  // assume destinaton is large enough to hold _x
  if (_y.size() >= _x.size())
    reverse_copy(_x.begin(), _x.end(), _y.begin());
  else {
    std::cerr << "reverse element failed, check destination size!" << endl;
    return;
  }
}
// using two version of remove_if
// remove odd element
void removeElement(vector<int> &_x, vector<int> &_y) {
  using std::remove_copy_if;
  using std::remove_if;
  // remove from _x, not change the size of the container
  auto point = remove_if(_x.begin(), _x.end(), [](int i) { return i % 2; });
  // clean the first non odd element , end)
  _x.erase(point, _x.end());
  // assume add odd element
  _x.push_back(13);
  // copies only the even elements from _x to dest
  remove_copy_if(_x.begin(), _x.end(), std::back_inserter(_y),
                 [](int i) { return i % 2; });
}
// container specify operation for list and forward list
// generic version has cost in performance
// case 1: sort element
template <typename Object> void sortList_m(list<Object> &_x) {
  _x.sort(); // calling sort member version
}
// case 2:merge element from _y to _x
template <typename Object>
void mergeList_m(list<Object> &_x, list<Object> &_y) {
  _x.merge(_y); // calling merge mem version
}
// case 3:reverse the order of element
template <typename Object> void reverseList_m(list<Object> &_x) {
  _x.reverse();
}
} // namespace Refactor
#endif