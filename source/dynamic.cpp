#include "dynamic.h"
#include <iostream>
using std::string;
#include <memory>
#include <string>
#include <vector>
using std::vector;
using std::make_shared;
using std::shared_ptr;
//allocate an empty vector
refactor::str_blob::str_blob():data(make_shared<vector<std::string>>()) {}
//contructor initializes the vector's elements by copying the values in the list
refactor::str_blob::str_blob(std::initializer_list<std::string> il)
	:data(make_shared<vector<std::string>>(il))
{
}

void refactor::str_blob::pop_back() const
{
    check(0, "pop_back on empty str_blob");
    data->pop_back();
}

std::string& refactor::str_blob::front() const
{
    check(0, "front on empty str_blob");
    return data->front(); 
}

std::string& refactor::str_blob::back() const
{
    check(0, "back on empty str_blob");
    return data->back();
}

//private member to ensure that access the valid range
void refactor::str_blob::check(const size_type i, const std::string& msg) const
{
    if (i > data->size())
        throw std::out_of_range(msg);
}

void refactor::init_pointer() {
	const std::string auth_name = "Miller";
	// shared ptr that can point to string
	const auto p1 = std::make_shared<std::string>();
	if (p1 && p1->empty())
		*p1 = auth_name; // dereference operator to access element
	std::cout << *p1;
}

void refactor::copy_pointer()
{
    const auto x = std::make_shared<std::string>("Miller");
    const auto& y = x;
    if (y)
        std::cout << *y;
}

void refactor::tree_application()
{
    my_tree name;
    name.isbn = "John";
    name.left = std::make_shared<my_tree>();
    name.right = std::make_shared<my_tree>();
    name.left->isbn = "Michael";
    name.right->isbn = "Thomas";
    std::cout << name.isbn << " - " << name.left->isbn << " - " << name.right->isbn;
}

void refactor::linked_application()
{
	const auto age = std::make_shared<my_linked_list<int>>();
    age->item = 12;
    age->next = std::make_shared<my_linked_list<int>>();
    age->next->item = 34;
    auto point(age);
	while (point)
	{
        std::cout << point->item << " ";
        point = point->next;
	}
}

void refactor::reference_count()
{
	const auto x = std::make_shared<int>(12);
	const auto& y(x);
    std::cout << "count : " << x.use_count() << std::endl;
    std::cout << "count : " << y.use_count() << std::endl;
    auto z(y);
    *z = 14;
    //use count may slow operation and it's used only for debugging
    std::cout << "count : " << y.use_count()<<" val : " <<*y<< std::endl;
    std::cout << "count : " << z.use_count() << " val : "<<*z<<std::endl;
    std::cout << "count : " << x.use_count() << " val : " <<*x<<std::endl;
	const auto xy = std::make_shared<int>(15);
    z = xy; //decrements z reference count, increments xy count
    std::cout << "count : " << z.use_count() << " val : " << *z << std::endl;
    std::cout << "count : " << xy.use_count() << " val : " << *xy << std::endl;
    //check if use_count is one
    if (xy.unique())
        std::cout << "use count 1" << std::endl;
    else
	    std::cout << "not unique" << std::endl;
	const std::shared_ptr<int> uniq; //point to nothing, use count to zero
    std::cout << "unique : " << uniq.use_count() << std::endl;
    z = uniq;
	std::cout << "use count for z after point to null pointer : " << z.use_count() << std::endl;
}

std::shared_ptr<int> refactor::factory(){
    return std::make_shared<int>(12);
}

void refactor::use_factory(){
    std::shared_ptr<int>  p = factory();
} //when p goes out of scope, the memory to which p points is automatically freed
std::shared_ptr<refactor::my_tree> refactor::search_my_tree(std::shared_ptr<my_tree> tr, const std::string& val)
{
    if (!tr)
        return nullptr;
    if (tr->isbn == val)
        return tr;
    if (tr->isbn < val)
	    return search_my_tree(tr->left, val);
    return search_my_tree(tr->right, val);
}
