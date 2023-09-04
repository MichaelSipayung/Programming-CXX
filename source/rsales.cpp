#include "rsales.h"
// using namespace Refactor;
namespace refactor {
// define and initialize a static class member
double Account::interestRate = initRate();
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
} // namespace refactor
