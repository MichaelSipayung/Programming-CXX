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
} // namespace refactor
