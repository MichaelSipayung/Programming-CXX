/*this file is part of c++ primer, subject covered all about copy control.
 *Design a class must be consistent with some rule to avoid serious bug,
 *this example is part of good c++ design, but it's far from perfect.
 */
#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <random>
namespace refactor {
class foo_copy {
public:
  foo_copy(const foo_copy &); // copy ctor
  // the copy ctor should not define explicit
  foo_copy(); // default ctor : the first parameter must be reference type
  // assignment operator ordinarily should return a reference to their
  // left hand operand
  foo_copy &operator=(const foo_copy &); // assignment operator
  ~foo_copy();

private:
  string isbn_;
  double revenue_;
};
// If a class needs a destructor, it almost surely also needs the
// copy-assignment operator and a copy constructor. Best practice for applying
// destructor
class hash_ptr_copy {
public:
  hash_ptr_copy(const hash_ptr_copy &rhs);         // declare copy ctor
  hash_ptr_copy &operator=(const hash_ptr_copy &); // declare copy assignment
  ~hash_ptr_copy();                                // declare destructor
private:
  string node_name_;
  int *node_;
};
// serial_copy class is an experiment class to demonstrate the behavior of
// a unique serial number each time it's generate
class serial_copy {
  // if a class need copy it also need assignment, and vice versa but it
  // doesn't necessary to define a destructor
public:
  serial_copy(const serial_copy &); // declare copy constructor
  serial_copy &
  operator=(const serial_copy &); // required since it's contain cp ctor
private:
  std::uniform_int<> serial_;
};
//generate synthesized version of the copy control members by defining them as =default
class default_version
{
public:
  default_version() = default;
  default_version(const default_version&) = default;
  default_version& operator=(const default_version&) = default;
  ~default_version() = default;
private:
  string isbn_;
  double revenue_;
};
//prevent copies by defining the copy constructor and copy assignment as del functions
class no_copy
{
public:
  no_copy() = default;
  no_copy(const no_copy&) = delete; //prevent copy ctor
  no_copy& operator=(const no_copy&) = delete;//prevent copy assignment
  ~no_copy() = default; //use the synthesized destructor
private:
  string temp_;
};
//demonstrate class that act like values, this version is modification of hash_ptr
class hash_ptr_value
{
public:
	explicit hash_ptr_value(const string &s=string()):ps_(new string(s)), i_(0){}
  //each hash_ptr has it's own copy of the string to which ps points
  hash_ptr_value(const hash_ptr_value &p): ps_(new string(*p.ps_)),i_(p.i_){}
  hash_ptr_value& operator=(const hash_ptr_value&);
  ~hash_ptr_value() { delete ps_; }
private:
  string* ps_;
  int i_;
};
//defining classes that act like pointer
class hash_ptr_pointer
{
public:
  //ctor allocate a new string and new counter, which it sets to 1
  explicit hash_ptr_pointer(const string &s =string()):ps(new string(s)),
		i(0),use(new std::size_t(1)){}
  //copy constructor copies all three data members and increment the counter
  hash_ptr_pointer(const hash_ptr_pointer&p): ps(p.ps), i(p.i),use(p.use)
  {
    ++*use;//increment the counter
  }
  hash_ptr_pointer& operator=(const hash_ptr_pointer&);
  ~hash_ptr_pointer();
private:
  string* ps;
  int i;
  std::size_t* use; //member to keep track of how many objects share *ps
};
} // namespace refactor
