/*algorithm source code, this my private experiment using modern c++
 *some implementation may not really follow best design but
 *i do really try to improve piece by piece of the routine
 */
#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
namespace algorithm
{
	template<typename Item>
	struct list_data
	{
		Item item;
		shared_ptr<list_data> next;
	};
	//searching operation using smart pointer
	template <typename Item>
	shared_ptr<list_data<Item>> search_list(const Item& src, const shared_ptr<list_data<Item>> &ls)
	{
		if (!ls) //base case, no data
			return nullptr;
		if (ls->item == src)
			return ls;
		return search_list(src, ls->next);//move to next
	}
	//show all item in a linked list
	template<typename Item>
	void show_list(const shared_ptr<list_data<Item>> &ls)
	{
		if(!ls) //base case, no data
			return;
		cout << ls->item<<" ";
		show_list(ls->next);
	}
	//insertion into a list, simple case: insert on the front
	template<typename Item>
	void insert_list(const Item& item, shared_ptr<list_data<Item>> &ls)
	{
		auto temp = make_shared<list_data<Item>>();
		temp->item = item;
		temp->next = ls;
		ls = temp;
	}
	//deletion on the list, delete on the front
	//first we need to determine which the predecessor_list of the dest/ deleted list from source/ list
	//the predecessor_list is needed because it's point to the doomed node	
	template<typename Item>
	shared_ptr<list_data<Item>> predecessor_list(const shared_ptr<list_data<Item>> &dest, 
		const shared_ptr<list_data<Item>>&source)
	{
		if (!source || !source->next) //the list must contain item
			return nullptr;
		return source->next == dest ? source: predecessor_list(dest, source->next);
	}
	//deletion routine, using predecessor as a helper
	template<typename Item>
	void delete_list(const shared_ptr<list_data<Item>> &dest, shared_ptr<list_data<Item>> &source)
	{
		if(!dest) //no destination, or nullptr
			return;
		cout << "\nitem to be deleted : " << dest->item << endl;
		const auto temp = source;
		auto pred = predecessor_list(dest, source);
		if (!pred) //if predecessor is null, may be dest is head or no item
			source = temp->next; //just move list to next
		else //otherwise there is a predicate from dest or there are at least two item
			pred->next = dest->next;
	}
	void test_list_implement();
}

