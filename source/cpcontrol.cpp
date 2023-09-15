#include "cpcontrol.h"
using namespace refactor;
foo_copy::foo_copy(const foo_copy& x){
	revenue_ = x.revenue_;
}
foo_copy::foo_copy() = default;
// demonstrate how copy assignment work
foo_copy &foo_copy::operator=(const foo_copy &rhs) = default;
// destructor takes no parameter
foo_copy::~foo_copy() = default;
//definition of copy constructor required since we use constructor to destroy member
hash_ptr_copy::hash_ptr_copy(const hash_ptr_copy& rhs)
{
	node_name_ = rhs.node_name_;
	node_ = rhs.node_;
}
//the copy assignment also required to avoid some bug,deleting memory twice
hash_ptr_copy& hash_ptr_copy::operator=(const hash_ptr_copy& rhs)
{
	if(this!=&rhs) //ensure that we properly check self assignment
	{
		//deallocate the old memory
		delete node_;
		//do assignment from the right to left
		node_name_ = rhs.node_name_;
		node_ = rhs.node_;
	}
	return *this;
}
//the destructor definition, the way we destroy member of a class
hash_ptr_copy::~hash_ptr_copy(){
	delete node_;
}
//the second rule, we apply when we design a class, if a cp ctor needed
//the assignment must define or declare in a the class
serial_copy::serial_copy(const serial_copy& rh){
	serial_ = rh.serial_;
}
//define a copy assignment, since the we need a copy constructor
serial_copy& serial_copy::operator=(const serial_copy& rh){
	if(this!=&rh)
		serial_ = rh.serial_;
	return *this;
}
