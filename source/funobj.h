/* Operator call
 * library defined function
 * plus, negate class
 */
#ifndef FUNCTION_OBJ
#define FUNCTION_OBJ
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <functional> //library defined func
using std::function;
#include <algorithm>
using std::sort;
#include <map>
using std::map;

void base_fCallOp() {
  std::plus<int> add;
  std::negate<int> neg;
  cout << "f call operator " << add(10, 12) << endl;
  cout << "f call operator " << neg(13) << endl;
}
void fObj_onAlg() {
  vector<int> data = {1, 3, 2, 4, 6, 5, 7, 8, 0, 9};
  sort(data.begin(), data.end(), std::greater<int>()); // the third arg call op
                                                       // >
  for (auto i : data)
    cout << i << " ";
  cout << endl;
}
void lib_fType() {
  function<int(int, int)> f1 = std::plus<int>(); // function pointer
  function<int(int, int)> f2 = std::divides<int>();
  cout << "add : " << f1(3, 2) << endl;
  cout << "div : " << f2(4, 2) << endl;
  function<int(int, int)> f3 = [](int i, int j) { return i * j; }; // lamda
  cout << "mult : " << f3(12, 3) << endl;
}
// function table
void f_table() {
  function<int(int, int)> f1 = std::plus<int>(); // function pointer
  function<int(int, int)> f2 = std::divides<int>();
  function<int(int, int)> f3 = [](int i, int j) { return i * j; }; // lamda
  function<int(int, int)> f4 = std::minus<int>();
  function<int(int, int)> f5 = std::modulus<int>();
  map<std::string, function<int(int, int)>> binops = {
      {"+", f1}, {"-", f4}, {"/", f2}, {"*", f3}, {"%", f5}};
  // test
  cout << binops["+"](12, 3) << endl;
  cout << binops["-"](12, 5) << endl;
  cout << binops["/"](12, 5) << endl;
  cout << binops["%"](121, 25) << endl;
  cout << binops["*"](12, 121) << endl;
}
// conversion operator
class SmallInt {
public:
  SmallInt(int i = 0) : val{i} {
    if (i < 0 || i > 255)
      throw std::out_of_range("Bad SmallInt value");
  }
  explicit operator int() const { return val; } // need not the ret val and arg
  // prevent implicit conv
  void show_conv() const { cout << val << endl; }

private:
  int val;
};
#endif