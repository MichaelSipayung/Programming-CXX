#include "dynamic.h"
#include <iostream>
#include <memory>
#include <string>

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

