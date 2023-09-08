#include "dynamic.h"
#include <iostream>
using std::string;
#include <memory>
#include <string>
#include <utility>
#include <vector>
using std::make_shared;
using std::shared_ptr;
using std::vector;
#include <new>
using std::nothrow;
// allocate an empty vector
refactor::str_blob::str_blob() : data_(make_shared<vector<std::string>>()) {}
// constructor initializes the vector's elements by copying the values in the
// list
refactor::str_blob::str_blob(std::initializer_list<std::string> il)
    : data_(make_shared<vector<std::string>>(il)) {}
//remove the last element
void refactor::str_blob::pop_back() const {
  check(0, "pop_back on empty str_blob");
  data_->pop_back();
}
//return the first element
std::string &refactor::str_blob::front() const {
  check(0, "front on empty str_blob");
  return data_->front();
}
//return the last element
std::string &refactor::str_blob::back() const {
  check(0, "back on empty str_blob");
  return data_->back();
}
// private member to ensure that access the valid range
void refactor::str_blob::check(const size_type i,
                               const std::string &msg) const {
  if (i > data_->size())
    throw std::out_of_range(msg);
}
//initialize the pointer
void refactor::init_pointer() {
  const std::string auth_name = "Miller";
  // shared ptr that can point to string
  const auto p1 = std::make_shared<std::string>();
  if (p1 && p1->empty())
    *p1 = auth_name; // dereference operator to access element
  std::cout << *p1;
}
//copy on smart pointer
void refactor::copy_pointer() {
  const auto x = std::make_shared<std::string>("Miller");
  const auto &y = x;
  if (y)
    std::cout << *y;
}
//smart pointer application on tree
void refactor::tree_application() {
  my_tree name;
  name.isbn = "John";
  name.left = std::make_shared<my_tree>();
  name.right = std::make_shared<my_tree>();
  name.left->isbn = "Michael";
  name.right->isbn = "Thomas";
  std::cout << name.isbn << " - " << name.left->isbn << " - "
            << name.right->isbn;
}
//smart pointer application on linked_list
void refactor::linked_application() {
  const auto age = std::make_shared<my_linked_list<int>>();
  age->item = 12;
  age->next = std::make_shared<my_linked_list<int>>();
  age->next->item = 34;
  auto point(age);
  while (point) {
    std::cout << point->item << " ";
    point = point->next;
  }
}
//smart pointer, reference count
void refactor::reference_count() {
  const auto x = std::make_shared<int>(12);
  const auto &y(x);
  std::cout << "count : " << x.use_count() << std::endl;
  std::cout << "count : " << y.use_count() << std::endl;
  auto z(y);
  *z = 14;
  // use count may slow operation and it's used only for debugging
  std::cout << "count : " << y.use_count() << " val : " << *y << std::endl;
  std::cout << "count : " << z.use_count() << " val : " << *z << std::endl;
  std::cout << "count : " << x.use_count() << " val : " << *x << std::endl;
  const auto xy = std::make_shared<int>(15);
  z = xy; // decrements z reference count, increments xy count
  std::cout << "count : " << z.use_count() << " val : " << *z << std::endl;
  std::cout << "count : " << xy.use_count() << " val : " << *xy << std::endl;
  // check if use_count is one
  if (xy.unique())
    std::cout << "use count 1" << std::endl;
  else
    std::cout << "not unique" << std::endl;
  const std::shared_ptr<int> uniq; // point to nothing, use count to zero
  std::cout << "unique : " << uniq.use_count() << std::endl;
  z = uniq;
  std::cout << "use count for z after point to null pointer : " << z.use_count()
            << std::endl;
}
//demonstrate how smart pointer automatically free resource
std::shared_ptr<int> refactor::factory() { return std::make_shared<int>(12); }

void refactor::use_factory() {
  std::shared_ptr<int> p = factory();
} // when p goes out of scope, the memory to which p points is automatically
  // freed
std::shared_ptr<refactor::my_tree>
refactor::search_my_tree(std::shared_ptr<my_tree> tr, const std::string &val) {
  if (!tr)
    return nullptr;
  if (tr->isbn == val)
    return tr;
  if (tr->isbn < val)
    return search_my_tree(tr->left, val);
  return search_my_tree(tr->right, val);
}
//demonstrate how to directly initialize a pointer
void refactor::initialize_direct()
{
	auto pi = new int;// pi point to a dynamically allocated, unnamed, uninitialized int
    auto ps = new string; //ps points to empty string
	//using direct initialization
	std::cout << pi << ps;
    auto pt = new int(12); //object to which pt points has value 12
}
//dynamically allocated const objects
void refactor::initialize_const_direct()
{
    //return pointer to const
    auto pi = new const int(12); //allocate and initialize a const int
    auto ps = new const string; //allocate a default-initialized const empty string
}
//if new is unable to allocate the requested storage, it throws an exception
//of type bad_alloc, prevent it using different form of new
void refactor::memory_exhaust()
{
    auto pi = new int; //should throw if allocate fail
    auto* ps = new (nothrow)string; //if allocation fails, new return a null pointer
}
//freeing dynamic memory using delete
void refactor::freeing_direct()
{
	const auto pi = new int(12);
	const auto ps = new string("hello world");
    std::cout << "pi :"<<*pi << std::endl;
    std::cout << "ps :" << *ps << std::endl;
    delete pi;
    delete ps;
}
//demonstrate how to deal with built in pointer
int* refactor::factory_md(const int &val){
    return new int(val);//caller is responsible for deleting this memory
}
//fix some bug through call delete inside caller
void refactor::use_factory_md(){
	const auto p = factory_md(12);
    delete p;
    if(p)
	    std::cout << "fixing bug on built in pointer";
}
//resetting a value on a built in pointer
void refactor::reset_pointer_val()
{
    auto x = new int(12);
    delete x;
    //after delete, if we need the pointer, we must set to nullptr
    x = nullptr;
    if(!x)
	    std::cout << "ok, safely reset pointer to null";
}
//using shared_ptr with new, note: must use direct initialization
void refactor::smart_ptr_new(){
    shared_ptr<int> x(new int(12)); //x point to an int with value 12
}
//another operation on smart pointer
void refactor::reset_smart_ptr()
{
    auto p = make_shared<int>(12);
    p.reset(new int(13)); //p point to new object
    //control changes to the object
    if (!p.unique())
        p.reset(new int(*p));//we are not alone, allocate new copy
    *p += 13; //we're the only pointer, change this object
}
//using smart pointer when there is a possibility an exception will occur
//avoid using built in pointer, when the exception occurs the variable will not freed
void refactor::handle_exception(){
    shared_ptr<int> x(new int(12));
    //code that throw an exception that is not caught inside function
    //shared_ptr will automatically freed when the function end
}
//this demonstration will be bad practice to deal with exception
void refactor::bad_ptr(){
	const auto x = new int(12); //ok, if exception occurs before we freed resource!
    //resource used by x will not be freed
	delete x; //freed the resource
}
//unique_ptr does not support copy and assignment
void refactor::init_unique_ptr()
{
    std::unique_ptr<int> x; //x point to int
    //it must be using direct form to initialize unique_ptr
    std::unique_ptr<string> y(new string("hello world"));
    std::cout << *y;
    //even if we can't copy, we can transfer ownership from one non const
    //unique_ptr to another by calling release or reset
    const std::unique_ptr<string> p1(y.release()); //transfer ownership from y
    std::cout << std::endl<<*p1;
    std::unique_ptr<string> p2(new string("the c++"));
    const std::unique_ptr<string> p3 = std::move(p2); //prefer move rather than reset
    std::cout << *p3;
}
//copy and assignment in unique_ptr in object is about to destroyed
std::unique_ptr<int> refactor::clone(int p){
    return std::make_unique<int>(p); //compiler know that the object is about to destroyed
}
