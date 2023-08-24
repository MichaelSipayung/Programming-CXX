// dynamic memory and smart pointer
#pragma once
#include <memory>
#include <memory>
#include <string>
namespace refactor {
struct my_tree
{
	my_tree() : left(nullptr), right(nullptr) {}
	std::string isbn;
	std::shared_ptr<my_tree> left;
	std::shared_ptr<my_tree> right;
};
template <typename  Object>
struct my_linked_list
{
	Object item;
	std::shared_ptr<my_linked_list> next;
	my_linked_list():item(),next(nullptr){}
	my_linked_list(const Object &val, std::shared_ptr<my_linked_list> &next_it):
		item(val), next(next_it){}
};
void init_pointer();
void copy_pointer();
void tree_application();
void linked_application();
}
