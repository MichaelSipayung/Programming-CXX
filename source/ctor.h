#pragma once
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::size_t;
using std::string;
namespace Adv {
class Sales_data {
public:
  Sales_data() = default;         // default ctor
  Sales_data(const Sales_data &); // copy ctor
  ~Sales_data(){};

private:
  std::string bookNo;
  int unit_sold = 0;
  double revenue = 0.0;
};
class Foo {
public:
  Foo() = default;
  Foo(const Foo &) : isbn{" "}, x{0}, y{0} {} // copy ctor
  Foo &operator=(const Foo &);                // ass op
  ~Foo() {}                                   // destructor
private:
  string isbn;
  int x = 0;
  double y = 0.0;
};
// we use dctor together with cp ctor, cp assignment
class HashPtr {
public:
  HashPtr() = default;
  HashPtr(const HashPtr &);            // cp ctor
  HashPtr &operator=(const HashPtr &); // cp asignment
  HashPtr(const string &s = string()) : ps{new string(s)}, xPoint{0} {}
  void test_dctor();
  ~HashPtr() { delete ps; }

private:
  string *ps; // need dctor
  double xPoint = 0.0;
};
class Default_Sales {
public:
  // copy control; use default
  Default_Sales() = default;
  Default_Sales(const Default_Sales &) = default;
  Default_Sales &operator=(const Default_Sales &);
  ~Default_Sales() = default;

private:
  string isbn;
  double revenue;
};
// prevent copy ctror and assignment
class PrevCopy {
public:
  PrevCopy() = default;                           // use synthesized version
  PrevCopy(const PrevCopy &) = delete;            // no cp
  PrevCopy &operator=(const PrevCopy &) = delete; // no assignment
  ~PrevCopy() = default;                          // use synthesized dest
private:
  string isbn;
  double xPoint;
};
// classes that act like value
class HasPtr {
public:
  HasPtr(const string &s = string()) : ps{new string(s)}, i{0} {}
  HasPtr(const HasPtr &p)
      : ps{new string(*p.ps)}, i{p.i} {} // each HasPtr has it's own cp
  HasPtr &operator=(const HasPtr &);
  void test_safe_assign() const;
  ~HasPtr() { delete ps; }

private:
  string *ps;
  int i;
};
// class act like pointer
class has_ptr_1 {
public:
  friend void swap(has_ptr_1 &, has_ptr_1 &);
  // ctor allocates a new str and a new counter, which it set to 1
  explicit has_ptr_1(const string &s = string())
      : ps_{new string(s)}, i_{0}, use_{new size_t(1)} {}
  // cp ctor copies all three data members and increment the counter
  has_ptr_1(const has_ptr_1 &p) : ps_{p.ps_}, i_{p.i_}, use_{p.use_} { ++*use_; }
  has_ptr_1 &operator=(const has_ptr_1 &);
  size_t count() const;
  ~has_ptr_1();

private:
  string *ps_;
  int i_;
  size_t *use_; // member to keep track of how many obj share *ps
};
inline void swap(has_ptr_1 &lhs, has_ptr_1 &rhs) {
  using std::swap;
  swap(lhs.ps_, rhs.ps_); // swap the pointer, not the str data
  swap(lhs.i_, rhs.i_);   // swap the int members
}
} // namespace Adv
