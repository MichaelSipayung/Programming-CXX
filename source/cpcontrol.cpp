#include "cpcontrol.h"
using namespace refactor;
foo_copy::foo_copy(const foo_copy &x) { revenue_ = x.revenue_; }
foo_copy::foo_copy() = default;
// demonstrate how copy assignment work
foo_copy &foo_copy::operator=(const foo_copy &rhs) = default;
// destructor takes no parameter
foo_copy::~foo_copy() = default;
// definition of copy constructor required since we use constructor to destroy
// member
hash_ptr_copy::hash_ptr_copy(const hash_ptr_copy &rhs) {
  node_name_ = rhs.node_name_;
  node_ = rhs.node_;
}
// the copy assignment also required to avoid some bug,deleting memory twice
hash_ptr_copy &hash_ptr_copy::operator=(const hash_ptr_copy &rhs) {
  if (this != &rhs) // ensure that we properly check self assignment
  {
    // deallocate the old memory
    delete node_;
    // do assignment from the right to left, this is the simple case
    node_name_ = rhs.node_name_;
    node_ = rhs.node_;
  }
  return *this; // return to this object
}
// the destructor definition, the way we destroy member of a class
hash_ptr_copy::~hash_ptr_copy() { delete node_; }
// the second rule, we apply when we design a class, if a cp ctor needed
// the assignment must define or declare in a the class
serial_copy::serial_copy(const serial_copy &rh) { serial_ = rh.serial_; }
// define a copy assignment, since the we need a copy constructor
serial_copy &serial_copy::operator=(const serial_copy &rh) {
  if (this != &rh)
    serial_ = rh.serial_;
  return *this;
}
// value-like copy assignment operator, if an exception occurs during assignment
// we already make assignment procedure safely by copying right hand side
hash_ptr_value &hash_ptr_value::operator=(const hash_ptr_value &rhs) {
  if (this != &rhs) // handle self assignment
  {
    const auto temp = new string(*rhs.ps_); // copy the underlying str
    delete ps_;                             // free the old memory
    ps_ = temp; // copy data from rhs into this object
    i_ = rhs.i_;
  }
  return *this;
}
// assingment operator: first increment the counter in the right-hand operand
// then decrement the counter of the left-hand operand, deleting the memory
hash_ptr_pointer &hash_ptr_pointer::operator=(const hash_ptr_pointer &rhs) {
  if (this != &rhs) {
    ++*rhs.use;      // increment the use count of the right-hand operand
    if (--*use == 0) // decrement the counter of the left hand operand
    {
      delete ps; // ok no other user, just free the underlying object
      delete use;
    }
    ps = rhs.ps; // copy data from right-hand operand
    i = rhs.i;
    use = rhs.use;
  }
  return *this; // return this object
}

// the destructor cannot unconditionally delete ps, there might be other object
// pointing to that memory, instead destructor decrements the reference count
hash_ptr_pointer::~hash_ptr_pointer() {
  if (--*use == 0) // if the reference count goes to zero
  {
    delete ps;  // delete the string
    delete use; // and the counter
  }
}
