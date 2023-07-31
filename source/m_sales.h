#ifndef M_SALES_C
#define M_SALES_C
#include <iostream>
class M_Sales_data {
  // friend declarations for nonmember m_sales_data operation added
  friend M_Sales_data add(const M_Sales_data &, const M_Sales_data &);
  friend std::istream &read(std::istream &, M_Sales_data &);
  friend std::ostream &print(std::ostream &, const M_Sales_data &);

public: // access specifier added
  M_Sales_data() = default;
  // default arguments and constructors
  /*M_Sales_data(std::string s=""):bookNo(s){}*/
  explicit M_Sales_data(const std::string s) : bookNo(s) {}
  M_Sales_data(const std::string s, unsigned int n, double p)
      : bookNo(s), unit_sold(n), revenue(p * n) {}
  explicit M_Sales_data(std::istream &);
  std::string isbn() const { return bookNo; }
  M_Sales_data &combine(const M_Sales_data &);
  // prevent implicit conversion
  // explicit M_Sales_data(const std::string &s):bookNo(s){}
  void show_data();
  //needed for sales_data as a key
  static bool equalOperator(const M_Sales_data&, const M_Sales_data&);

private: // access specifier added
  double avg_price() const { return unit_sold ? revenue / unit_sold : 0; }
  std::string bookNo;
  unsigned unit_sold = 0;
  double revenue = 0.0;
};
// declaration for nonmember parts of the sales_data interface
M_Sales_data add(const M_Sales_data &, const M_Sales_data &);
std::istream &read(std::istream &, M_Sales_data &);
std::ostream &print(std::ostream &, const M_Sales_data &);
#endif