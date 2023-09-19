#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
class DemoEmplace {
public:
  DemoEmplace() = default;
  // using explicit to avoid cast
  explicit DemoEmplace(std::string isbn, unsigned total_sold, double price_b)
      : x(isbn), sold(total_sold), price(price_b) {}

public:
  std::string x;
  unsigned sold;
  double price;
};
class DemoVector {
public:
  DemoVector() = default;
  DemoVector(std::string isbn, unsigned total_sold, double price_b)
      : x(isbn), sold(total_sold), price(price_b) {}

public:
  std::string x;
  unsigned sold;
  double price;
};
void max_vec_hold();
void iterat_el();
void const_iter_el();
void rev_iter_el();
void init_con();
void init_con_arr();
void copy_con();
void swap_con();
void check_size();
void relat_op();
void add_el();
void demo_emplace();
void acc_el();
void err_el();
void demo_err_el();
void rem_by_pair();
void forw_list_it();
void resize_con();
void safe_it();
void manage_cap();
#endif