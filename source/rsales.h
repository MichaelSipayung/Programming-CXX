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
namespace Ref {
struct Sales_Data {
  string isbn() const { return bookNo; }
  Sales_Data &combine(const Sales_Data &);
  double avg_price() const;
  string bookNo;
  unsigned unit_sold = 0;
  double reveneu = 0.0;
};
// nonmember sales_data interface f
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
} // namespace Ref
#endif