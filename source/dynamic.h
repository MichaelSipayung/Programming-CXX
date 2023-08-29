// dynamic memory and smart pointer
#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace refactor {
// modification of binary search tree using smart pointer
struct my_tree
{
	my_tree() : left(nullptr), right(nullptr) {}
	std::string isbn;
	std::shared_ptr<my_tree> left;
	std::shared_ptr<my_tree> right;
};
// modification of linked list using smart pointer
template <typename  Object>
struct my_linked_list
{
	Object item;
	std::shared_ptr<my_linked_list> next;
	my_linked_list():item(),next(nullptr){}
	my_linked_list(const Object &val, std::shared_ptr<my_linked_list> &next_it):
		item(val), next(next_it){}
};
//str_blob class
class str_blob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	str_blob();
	str_blob(std::initializer_list<std::string> il);
	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	//add and remove element
	void push_back(const std::string& t)const { data->push_back(t); }
	void pop_back() const;
	//element access
	std::string& front() const;
	std::string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	//throw msg if data[i] is not valid
	void check(size_type i, const std::string &msg) const;
};
//pointer initialization
void init_pointer();
//copy on a smart_pointer
void copy_pointer();
//test smart pointer on binary search tree
void tree_application();
//test smart pointer on linked_list
void linked_application();
//traverse all element on binary tree
template<typename Object>
void tree_traverse(const std::shared_ptr<my_tree> tr)
{
	if(tr)
	{
		tree_traverse<Object>(tr->left); //left first
		std::cout << tr->isbn <<" ";
		tree_traverse<Object>(tr->right); //go right
	}
}
//reference count, track how many object pointed to the current pointer
void reference_count();
//automatically free the associated memory
std::shared_ptr<int> factory();
//test automatically free memory
void use_factory();
//searching on a using smart pointer
std::shared_ptr<my_tree> search_my_tree(std::shared_ptr<my_tree> tr, const std::string &val);
}
