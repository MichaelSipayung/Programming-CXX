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
namespace Refac {
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
/*avg_price: get the average*/
double Sales_Data::avg_price() const {
  if (unit_sold)
    return reveneu / unit_sold;
  else
    return 0;
}
/*combine: combine the other sales to the current sales*/
Sales_Data &Sales_Data::combine(const Sales_Data &rhs) {
  unit_sold += rhs.unit_sold;
  reveneu += rhs.reveneu;
  return *this;
}
/*read: input transaction contain isbn, num of copies ..*/
istream &read(istream &is, Sales_Data &item) {
  double price = 0;
  is >> item.bookNo >> item.unit_sold >> price;
  item.reveneu = price * item.unit_sold;
  return is;
}
/*print: print content to standart output*/
ostream &print(ostream &os, const Sales_Data &item) {
  os << item.isbn() << " " << item.unit_sold << " " << item.reveneu << " "
     << item.avg_price();
  return os;
}
/*add: sum two sales data*/
Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs) {
  Sales_Data sum = lhs;
  sum.combine(rhs);
  return sum;
}
/*define ctor outside the class body*/
// read will read a transaction from is into this object
// no return type for ctor
// using this to access object as a whole
Sales_Data::Sales_Data(istream &is) { read(is, *this); }
// forward declaration for friendship
class Window_mgr;
class Screen {
  friend class Window_mgr;

public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height{ht}, width{wd}, contents{static_cast<char>(ht * wd), c} {}
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
// some_member: making data member mutable even if const const member f
void Screen::some_member() const { ++access_ctr; }
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
void Window_mgr::clear(ScreenIndex i) {
  // reference to the screen we want to clear
  Screen &s = screens[i];
  // reset the contents of that screen
  s.contents = string(s.height * s.width, ' ');
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
  screens.push_back(s);
  return screens.size() - 1;
}
class ConstRef {
public:
  ConstRef(int);
  // constexpr on nonaggregate class
  constexpr bool nonLiteral() { return i > 0; };

private:
  int i;
  const int ci;
  int &ri;
};
// explicitly intialize reference and const member
ConstRef::ConstRef(int ii) : i{ii}, ci{ii}, ri{i} {}
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
void Account::rate(double newRate) { interestRate = newRate; }
// define and initialize a static class member
double Account::interestRate = initRate();
double Account::initRate() { return 0.008; }

} // namespace Refac
#endif