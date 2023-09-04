#ifndef SALES_REFACTOR_H
#define SALES_REFACTOR_H
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
#include <vector>
using std::vector;
namespace refactor {
class Sales_Data {
  // friend declarations for nonmember sales_data operations added
  friend Sales_Data add(const Sales_Data &, const Sales_Data &);
  friend ostream &print(ostream &, const Sales_Data &);
  friend istream &read(istream &, Sales_Data &);

public:
  // constructor added
  Sales_Data() = default;
  // declaring the ctor as explicit, prevent implicit conversion
  explicit Sales_Data(const string &s) : bookNo{s} {}
  Sales_Data(const string &s, unsigned n, double p)
      : bookNo{s}, unit_sold{n}, reveneu{p * n} {}
  explicit Sales_Data(istream &); // useful for single arguments
  string isbn() const { return bookNo; }
  Sales_Data &combine(const Sales_Data &);
  // delegate ctor
  // Sales_Data():Sales_Data("",0,0){}
private:
  double avg_price() const;
  string bookNo;
  unsigned unit_sold = 0;
  double reveneu = 0.0;
};
// declaration for nonmember parts of the sales_data interface
Sales_Data add(const Sales_Data &, const Sales_Data &);
ostream &print(ostream &, const Sales_Data &);
istream &read(istream &, Sales_Data &);
// forward declaration for friendship
class Window_mgr;
class Screen {
  friend class Window_mgr;

public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height{ht}, width{wd}, contents{static_cast<char>(ht * wd), c},
        access_ctr(0) {}
  ~Screen(){};
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;
  Screen &set(char);
  Screen &set(pos, pos, char);
  // overload base on constness
  Screen &display(ostream &os) {
    do_display(os);
    return *this;
  }
  const Screen &display(ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;
  // adding mutable data member
  mutable size_t access_ctr;
  void do_display(ostream &os) const { os << contents; }
};
inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}
// get: const f that return to specific location of the screen
char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}
// some_member: making data member mutable even if const member f
inline void Screen::some_member() const { ++access_ctr; }
inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this; // ret as lval
}
inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}
class Window_mgr {
public:
  typedef vector<Screen>::size_type ScreenIndex; // location id for each screen
  void clear(ScreenIndex); // reset the screen at given position
  ScreenIndex
  addScreen(const Screen &); // add a screen to the window and return its index
private:
  vector<Screen> screens{Screen{24, 80, ' '}};
};

class ConstRef {
public:
  ConstRef(int);
  // constexpr on non aggregate class
  constexpr bool nonLiteral() { return i > 0; };

private:
  int i;
  const int ci;
  int &ri;
};
// explicitly intialize reference and const member
inline ConstRef::ConstRef(int ii) : i{ii}, ci{ii}, ri{i} {}
// constexpr ctor for literal class, all member is default initialize
class Debug {
public:
  constexpr Debug(bool b = true) : hw{b}, io{b}, other{b} {}
  constexpr Debug(bool h, bool i, bool o) : hw{h}, io{i}, other{o} {}
  constexpr bool any() { return hw || io || other; }
  void set_io(bool b) { io = b; }
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { hw = b; }

private:
  bool hw;    // hardware errors
  bool io;    // io errors
  bool other; // other errors
};
class Account {
public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);

private:
  string owner;
  double amount;
  static double interestRate;
  static double initRate();
  // in-class initialization of static data member
  static constexpr int period = 30; // period is a constant expr
  double daily_tbl[period];
};
inline void Account::rate(double newRate) { interestRate = newRate; }
inline double Account::initRate() { return 0.008; }
} // namespace refactor
#endif