#pragma once
#include <iostream>
#include <string>
#include <vector>
class Sales_Cl {
  friend std::ostream &operator<<(std::ostream &, const Sales_Cl &);

public:
  Sales_Cl() = default;
  explicit Sales_Cl(const std::string &s) : bookNo{s} {}
  Sales_Cl(std::string s, unsigned n, double p)
      : bookNo{std::move(s)}, units_sold{n}, revenue{p * n} {}
  // overload
  Sales_Cl &operator+=(const Sales_Cl &);

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
std::ostream &operator<<(std::ostream &, const Sales_Cl &);

class Mat {
  friend void show_data(const Mat &);

public:
  Mat() = default;
  Mat(const std::vector<double> temp) : data{temp} {}
  Mat(const Mat &rhs) : data{rhs.data} {}
  Mat &operator=(const Mat &);
  Mat &operator+(const Mat &);

private:
  bool chk_size(const Mat &) const;
  std::vector<double> data;
};
void show_data(const Mat &);

class IncDec_Operator {
public:
  IncDec_Operator() = default;
  IncDec_Operator(const std::vector<std::string> &);
  IncDec_Operator(const std::vector<int> &);
  IncDec_Operator(const IncDec_Operator &rh);
  IncDec_Operator &operator++(); // prefix op
  IncDec_Operator &operator--();
  IncDec_Operator
  operator++(int); // postfix, an extra arg supply to distinguishes
  IncDec_Operator operator--(int);
  std::string &operator*() const; // we intended not to change the state
  std::string *operator->() const;
  ~IncDec_Operator() = default;
  void show_curr() const;
  void show_str() const;

private:
  std::vector<int> data;
  std::vector<std::string> *str_data;
  size_t pos;
};

// function call operator
struct absInt {
  int operator()(int val) const { return val < 0 ? -val : val; }
  std::ostream &operator()(std::ostream &, const std::string &);
  static void test_funObj();
};
inline void absInt::test_funObj() {
  absInt test_x;
  std::cout << test_x(-12);
}
inline std::ostream &absInt::operator()(std::ostream &os,
                                        const std::string &str) {
  os << str;
  return os;
}
// function obj classes with state
class PrintString {
public:
  explicit PrintString(std::ostream &o = std::cout, char c = ' ')
      : os{o}, sep{c} {}
  void operator()(const std::string &s) const { os << s << sep; }

private:
  std::ostream &os;
  char sep;
};
// replace the lambda version
// has same meaning, demo overload f call op
// function objects : lambda
class Shorter_Str {
public:
  bool operator()(const std::string &x, const std::string &y) {
    return x.size() < y.size();
  }
};
// classes representing lambda with captures
class SizeComp {
public:
  explicit SizeComp(size_t n) : sz{n} {} // param for each cap lambda
  bool operator()(const std::string &s) const {
    return s.size() >= sz;
  } // cal op as th lambda did
private:
  size_t sz;
};
