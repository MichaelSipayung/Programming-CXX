#include "m_sales.h"
void M_Sales_data::show_data() {
  std::cout << "call the data must be indirectly" << std::endl;
  std::cout << " isbn : " << bookNo << std::endl;
  std::cout << " unit sold : " << unit_sold << std::endl;
  std::cout << " revenue : " << revenue << std::endl;
  std::cout << "average price : " << avg_price() << std::endl;
}
M_Sales_data &M_Sales_data::combine(const M_Sales_data &rh) {
  unit_sold += rh.unit_sold;
  revenue += rh.revenue;
  return *this;
}
// friend function, access the sales_data member
M_Sales_data add(const M_Sales_data &first, const M_Sales_data &right) {
  M_Sales_data sum = first;
  sum.combine(right);
  return sum;
}
std::istream &read(std::istream &is, M_Sales_data &item) {
  double price = 0.0;
  // demo read defenition as friend function
  is >> price;
  return is;
}
std::ostream &print(std::ostream &os, const M_Sales_data &item) {
  // demo print defenition as friend
  os << item.isbn();
  return os;
}