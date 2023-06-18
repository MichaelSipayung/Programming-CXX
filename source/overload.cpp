#include "overload.h"
#include <string>
using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

double Sales_Cl::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}
Sales_Cl &Sales_Cl::operator+=(const Sales_Cl &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
ostream &operator<<(ostream &os, const Sales_Cl &rhs) {
  os << rhs.bookNo << " " << rhs.units_sold << " " << rhs.revenue << " "
     << rhs.avg_price();
  return os;
}
void show_data(const Mat &rhs) { cout << *rhs.data.begin(); }
// test
bool Mat::chk_size(const Mat &rhs) {
  if (data.size() != rhs.data.size())
    return false;
  return true;
}
Mat &Mat::operator=(const Mat &rhs) {
  auto temp = chk_size(rhs);
  if (temp)
    this->data = rhs.data;
  return *this;
}
Mat &Mat::operator+(const Mat &rhs) {
  auto temp = this;
  if (!chk_size(rhs))
    return *this;
  for (int i = 0; i < data.size(); ++i)
    data[i] += rhs.data[i];
  return *this;
}

IncDec_Operator::IncDec_Operator(const IncDec_Operator &rh) {
  data = rh.data;
  pos = rh.pos;
}
IncDec_Operator &IncDec_Operator::operator++() {
  if (pos < this->data.size())
    ++pos;
  return *this;
}
void IncDec_Operator::show_curr() { std::cout << data[pos]; }
IncDec_Operator &IncDec_Operator::operator--() {
  if (pos < 1)
    throw std::out_of_range("index out of range");
  else
    --pos;
  return *this;
}
IncDec_Operator IncDec_Operator::operator++(int) {
  IncDec_Operator temp = *this;
  ++*this;     // advance the el; prefix chk the incr
  return temp; // return the saved state
}
IncDec_Operator IncDec_Operator::operator--(int) {
  // no check needed here, the call to prefix dec will do check
  IncDec_Operator temp = *this; // save the curr state
  --*this; // move backward one el; prefix --check the decrement
  return temp;
}
IncDec_Operator::IncDec_Operator(const vector<int> &tmp) : data{tmp}, pos{0} {}

string &IncDec_Operator::operator*() const { return (*str_data)[pos]; }
string *IncDec_Operator::operator->() const {
  return &this->operator*(); // delegate the real work to the deref op
}
IncDec_Operator::IncDec_Operator(const vector<string> &x)
    : str_data{new vector<string>(x.begin(), x.end())} {}

void IncDec_Operator::show_str() const {
  auto begin = str_data->begin();
  auto end = str_data->end();
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
}