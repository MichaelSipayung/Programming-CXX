// dynamic memory and smart pointer
#pragma once
#include <iostream>
#include <memory>
#include <string>
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
}
