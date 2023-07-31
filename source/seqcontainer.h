#ifndef SEQUENTIAL_CON_H
#define SEQUENTIAL_CON_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <array>
using std::array;
#include "rsales.h"
#include <forward_list>
using std::forward_list;
#include <string>
using std::stod;      // convert str to floating-point
using std::to_string; // convert int to str
#include <stack>
using std::stack;
#include <queue>
using std::priority_queue;
using std::queue;
namespace Refactor {
void vecWork() {
  vector<int> basic = {0, 12, 3, 12, 4, 5, 6};
  vector<int>::iterator begin, end;
  begin = basic.begin();
  end = basic.end();
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << endl;
  // using reverse version
  vector<double> rev_basic = {0.5, 0, 6, 0.7, 0.8, 0.78};
  vector<double>::reverse_iterator begin_r;
  vector<double>::reverse_iterator end_r;
  begin_r = rev_basic.rbegin();
  end_r = rev_basic.rend();
  while (begin_r != end_r) {
    cout << *begin_r << " ";
    ++begin_r;
  }
  cout << endl;
  // constant version
  const vector<double> cn_basic = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
  vector<double>::const_iterator cn_begin, cn_end;
  cn_begin = cn_basic.cbegin();
  cn_end = cn_basic.cend();
  while (cn_begin != cn_end) {
    cout << *cn_begin << " ";
    ++cn_begin;
  }
  cout << endl;
}
void listWork() {
  list<double> basic = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7};
  list<double>::iterator begin, end;
  begin = basic.begin();
  end = basic.end();
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << endl;
  // const version for iterator
  list<string> str_basic = {"bas", "ic", "hello", "world"};
  list<string>::const_iterator cn_begin, cn_end;
  cn_begin = str_basic.cbegin();
  cn_end = str_basic.cend();
  while (cn_begin != cn_end) {
    cout << *cn_begin << " ";
    ++cn_begin;
  }
  cout << endl;
}
void init_container() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  // using iterator, copy from v to v_init
  std::vector<int> v_init(v.begin(), v.end());
  // using = to copy
  std::vector<int> v_sum;
  v_sum = v;
  vector<int>::iterator begin, end;
  begin = v_sum.begin();
  end = v_sum.end();
  cout << "copy assignment : ";
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << endl;
  // list initialize
  vector<const char *> articles = {"a", "an", "the"};
}
// container that can't remove or add
void fix_container() {
  array<int, 5> nat_num = {0, 1, 2, 3, 4};
  array<int, 5>::iterator begin, end;
  begin = nat_num.begin();
  end = nat_num.end();
  cout << "fix container : ";
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << endl;
  // no restriction for copy
  array<int, 5> source = {0, 1, 2, 3, 4};
  array<int, 5> dest = source;
  if (source == dest)
    cout << "equal element" << endl;
}
// diff but compatible type
void diff_type() {
  list<string> names;
  vector<const char *> oldstyle = {"style 1", "style 2", "style 2", "style 3"};
  // no assignment op, using assign for diff
  names.assign(oldstyle.begin(), oldstyle.end());
  for (auto x : oldstyle)
    cout << x << " ";
  cout << endl;
}
void exchange_container() {
  std::vector<string> x = {"jack",    "miller", "solve",
                           "problem", "right",  "now"};
  std::vector<string> y = {"miller", "jack", "solve", "now", "right"};
  std::swap(x, y);
  for (auto &tempx : x)
    cout << tempx << " ";
  cout << endl;
}
void exhangeStr_container() {
  string x = "miller";
  string y = "jack";
  swap(x, y); // contant time operation
  cout << "x result : " << x << endl;
  cout << "y result : " << y << endl;
}
void sizeOp_container() {
  vector<int> nat_num = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> integer_num = {-1, -2, -3, 0, 1, 2, 3, 4};
  if (nat_num.size() > 5)
    cout << "container consist of more than 5 value" << endl;
  else
    cout << "less than or equals to 5" << endl;
  cout << "return max element that container can hold : " << nat_num.max_size()
       << endl;
  if (!nat_num.empty())
    cout << "container contain no element" << endl;
}
void compare_container() {
  std::vector<char> vowel_word = {'a', 'e', 'i', 'o', 'u'};
  std::vector<char> v_short = {'a', 'e', 'i', 'u'};
  if (vowel_word < v_short)
    cout << "i am less than" << endl;
  else
    cout << "i am greater than" << endl;
}
// sequential container operation
void makePluralize(size_t cnt, string &word) {
  if (cnt > 1)
    word.push_back('s');
}
void addFront(size_t cnt, const string &word) {
  list<string> autname;
  for (size_t i = 0; i != cnt; ++i)
    autname.push_front(word);
  for (const auto &item : autname)
    cout << item << " ";
  cout << endl;
}
void addSpecLoc(void) {
  vector<double> phinum = {3.1401, 3.145, 3.1452, 3.14529};
  phinum.insert(phinum.begin(), 3.140);
  cout << "list of phi number (vector version): ";
  for (auto item : phinum)
    cout << item << " | ";
  cout << endl;
  list<double> phinumlist = {3.142, 3.1325, 3.14252, 3.14259};
  phinumlist.insert(phinumlist.begin(), 3.14);
  cout << "list of phi number (list version): ";
  for (auto item : phinumlist)
    cout << item << "|";
  cout << endl;
}
void useRet(void) {
  list<string> lst;
  auto iter = lst.begin();
  cout << "using return value from insert function : ";
  string word;
  while (cin >> word)
    iter = lst.insert(iter, word); // some as calling push_front
}
void constructEmplace(void) {
  list<Sales_Data> sales_work;
  sales_work.emplace_back("math-000x", 12, 13.55);
  sales_work.emplace_back("physics-111x", 12, 13.55);
}
void accessTheEl(const vector<double> &x) {
  cout << "first value : " << x.front() << endl;
  cout << "the last element : " << x.back() << endl;
  cout << "using iterator : " << *(x.begin()) << endl;
}
void safeIndexing(const vector<double> &x, const size_t _pos) {
  cout << "without throw exception : " << x[0] << endl;
  cout << "throw any exception : " << x.at(_pos) << endl;
}
void eraseContainer() {
  list<string> auth_name = {"jack", "miller", "doss", "furry"};
  cout << "before erase : ";
  for (auto &item : auth_name)
    cout << item << " | ";
  cout << endl;
  cout << "after erase the element : ";
  auth_name.pop_front();
  cout << "current front value : " << auth_name.front() << endl;
  cout << "vector version : ";
  vector<double> phinum = {3.1425, 3.14252, 3.1425290};
  for (auto item : phinum)
    cout << item << " | ";
  cout << endl;
  phinum.pop_back();
  cout << "calling pop_back() : " << phinum.back() << endl;
}
void eraseContainer_sec() {
  vector<double> curr_num = {12.3, 12.34, 12.345, 12.321};
  auto begin = curr_num.begin();
  auto end = curr_num.end();
  curr_num.erase(begin, end);
  cout << "after calling erase  (size)-> " << curr_num.size() << endl;
  list<string> autname = {"furry", "miller", "jackie", "smith"};
  auto beginLs = autname.begin();
  auto endLs = autname.end();
  autname.erase(beginLs, endLs);
  cout << "erase list version : (size ->) " << autname.size() << endl;
}
void clearAllElem() {
  vector<int> nat_num = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  list<string> authname = {"miller", "bruce", "scheiner"};
  nat_num.clear();
  authname.clear();
  cout << "size vector after call clear : " << nat_num.size() << endl;
  cout << "size of list after call clear : " << authname.size() << endl;
}
void clearOddNum() {
  vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  cout << " remove odds number program : ";
  auto begin = num.begin();
  auto end = num.end();
  while (begin != end) {
    if (*begin % 2 != 0) // odd element, erase it
      begin = num.erase(begin);
    else // move forward
      ++begin;
  }
  for (const auto &item : num)
    cout << item << " | ";
  cout << endl;
}
void clearEvenNum() {
  list<int> num_ls = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  cout << "clear even number : ";
  auto begin = num_ls.begin();
  auto end = num_ls.end();
  while (begin != end) {
    if (*begin % 2 == 0)
      begin = num_ls.erase(
          begin); // erase this element, begin point to the next elem
    else
      ++begin;
  }
  for (const auto &item : num_ls)
    cout << item << " |";
  cout << endl;
}
// singly linked list forward list container
void containerFwdLst() {
  forward_list<int> nat_num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto begin = nat_num.begin();
  cout << "before using any method : ";
  for (const auto &item : nat_num)
    cout << item << " | ";
  cout << endl;
  cout << "insert operation : ";
  nat_num.insert_after(begin, 12);
  for (const auto &item : nat_num)
    cout << item << " | ";
  cout << endl;
}
void singlyLinkedList() {
  forward_list<string> lst = {"element 1", "element 2", "element 3",
                              "element 4"};
  // demo to remove the third element
  auto thrd = lst.begin();
  ++thrd;
  lst.erase_after(thrd);
  cout << "demo, remove the third element on singly linked list : ";
  for (const auto &item : lst)
    cout << item << " | ";
  cout << endl;
}
// safely remove element from singly linked list
// remove odd number
void safeRemove() {
  forward_list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  auto prevEL = lst.before_begin(); // the off element or nonexistent
  auto begin = lst.begin();
  while (begin != lst.end()) {
    if (*begin % 2)
      begin = lst.erase_after(prevEL); // if odd, erase it add move curr
    else {
      prevEL = begin; // move iterator to the next
      ++begin;
    }
  }
}
void resize_container() {
  vector<double> phi_num = {3.14, 3.142, 3.14252, 3.1425229};
  cout << "current size : " << phi_num.size() << endl;
  phi_num.resize(12);
  cout << "after resize : " << phi_num.size() << endl;
}
// loops that change a container
// remove odds number then duplicate each even number
void dynChange_container() {
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      // insert : return iterator before inserted elemen
      iter = vi.insert(iter, *iter); // duplicate the current value
      iter += 2; // advance past this element and one inserted before it
    } else
      iter = vi.erase(
          iter); // rm even element, return the next iterator afer iter iterator
  }
  for (const auto &item : vi)
    cout << item << " | ";
  cout << endl;
}
void manageCap_container() {
  vector<double> num = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  cout << "the capacity : " << num.capacity() << endl;
}
// additional string operation
void addtStrOp() {
  // construct the other variable
  string authx = "jack miller";
  string authy = authx.substr(0, 5);
  cout << "using substr : " << authy << endl;
  string singleArg = authx.substr(4);
  cout << "pass single arguments : " << singleArg << endl;
  // insert element: five exclamation points at the end
  authy.insert(authy.size(), 5, '!');
  cout << "result after calling insert : " << authy << endl;
  // erase the last five chars from s
  authy.erase(authy.size() - 5, 5);
  cout << "calling erase : " << authy << endl;
  // assign : replace the content
  const char *cp = "Stately, plump back";
  string sname;
  // calling assign to change the content from cp
  sname.assign(cp, 7);
  cout << "after calling assign : " << sname << endl;
  // append : inserting at the end
  sname.append(" miller");
  cout << "calling append : " << sname << endl;
  // replace : calling erase and insert
  sname.replace(5, 3, "the"); // start from pos 5, remove 3 char and insert str
  cout << "calling replace : " << sname << endl;
}
// string search operation
void searchStrOp() {
  // forward search
  string curr_word = "michael walk by faith today";
  string::size_type pos = curr_word.find('f');
  cout << "find char 'f' on curr_word -> " << pos << endl;
  pos = curr_word.find("by");
  cout << "find word 'by' on curr_word : " << pos << endl;
  // backward search
  string::size_type cpos = curr_word.rfind("by");
  cout << "find word 'yb' -> " << cpos << endl;
}
// compare string
void compStr() {
  string _source = "michael";
  string _dest = "sipayung";
  cout << "compare src to dest : " << _source.compare(_dest) << endl;
}
// conversion char, double, str and int
void conversionStr() {
  string date_b = "15051998";
  int convert = stoi(date_b); // convert str to int
  cout << "conversion result : " << convert << endl;
  date_b = to_string(convert); // convert int to str
  cout << "int to str -> " << date_b << endl;
  string m_date_b = "15.05";
  double convert_m_date = stod(m_date_b);
  cout << "conversion result : " << convert_m_date << endl;
}
// container adaptor
void conAdaptor() {
  stack<int> stk; // empty ctor
  if (stk.empty())
    cout << "stack is empty" << endl;
}
// stack program
void stackTest() {
  // create empty stack
  stack<int> intStack;
  // fill up the stack
  for (size_t ix = 0; ix != 10; ++ix)
    intStack.push(ix);        // hold 0,1,....,9 inclusive
  while (!intStack.empty()) { // while there are still values in instack
    int value = intStack.top();
    cout << "current value to pop : " << value << endl;
    intStack.pop(); // pop the top element and repeat
  }
}
// queue adaptors
void testQueue() {
  queue<string> singer_name;
  singer_name.push("miller");
  singer_name.push("davis");
  singer_name.push("john");
  unsigned int i = 0;
  cout << "first singer : " << singer_name.front() << endl;
  singer_name.pop();
  cout << "remove using fifo policy (first singer) -> " << singer_name.front()
       << endl;
}
// priority queue
void prioQueTest() {
  priority_queue<string> order_name;
  order_name.push("jack");
  order_name.push("miller");
  order_name.push("steve");
  cout << "low priority : " << order_name.top() << endl;
}
} // namespace Refactor
#endif
