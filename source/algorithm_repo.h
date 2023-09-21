/*algorithm source code, this my private experiment using modern c++
 *some implementation may not really follow best design but
 *i do really try to improve piece by piece of the routine
 */
#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::make_shared;
using std::shared_ptr;
namespace algorithm {
template <typename Item> struct list_data {
  Item item;
  shared_ptr<list_data> next;
};
// searching operation using smart pointer
template <typename Item>
shared_ptr<list_data<Item>> search_list(const Item &src,
                                        const shared_ptr<list_data<Item>> &ls) {
  if (!ls) // base case, no data
    return nullptr;
  if (ls->item == src)
    return ls;
  return search_list(src, ls->next); // move to next
}
// show all item in a linked list
template <typename Item> void show_list(const shared_ptr<list_data<Item>> &ls) {
  if (!ls) // base case, no data
    return;
  cout << ls->item << " ";
  show_list(ls->next);
}
// insertion into a list, simple case: insert on the front
template <typename Item>
void insert_list(const Item &item, shared_ptr<list_data<Item>> &ls) {
  auto temp = make_shared<list_data<Item>>();
  temp->item = item;
  temp->next = ls;
  ls = temp;
}
// deletion on the list, delete on the front
// first we need to determine which the predecessor_list of the dest/ deleted
// list from source/ list the predecessor_list is needed because it's point to
// the doomed node
template <typename Item>
shared_ptr<list_data<Item>>
predecessor_list(const shared_ptr<list_data<Item>> &dest,
                 const shared_ptr<list_data<Item>> &source) {
  if (!source || !source->next) // the list must contain item
    return nullptr;
  return source->next == dest ? source : predecessor_list(dest, source->next);
}
// deletion routine, using predecessor as a helper, note: deleted only occur
// while we supply the right pointer or pointer to source not pointer that point
// to other
template <typename Item>
void delete_list(const shared_ptr<list_data<Item>> &dest,
                 shared_ptr<list_data<Item>> &source) {
  if (!dest) // no destination, or nullptr
    return;
  cout << "\nitem to be deleted : " << dest->item << endl;
  const auto temp = source;
  auto pred = predecessor_list(dest, source);
  if (!pred) // if predecessor is null, may be dest is head or no item
    source = temp->next; // just move list to next
  else // otherwise there is a predicate from dest or there are at least two
       // item
    pred->next = dest->next;
}
void test_list_implement();
// binary search tree declaration
template <typename Item> struct binary_tree {
  Item item;                      // data item
  shared_ptr<binary_tree> parent; // pointer to parent
  shared_ptr<binary_tree> left;   // pointer to left child
  shared_ptr<binary_tree> right;  // pointer to right child
  // ctor for single argument, initialize all node with default value for member
  // item
  explicit binary_tree(const Item &val_root)
      : item(val_root), left(make_shared<binary_tree>()),
        right(make_shared<binary_tree>()), parent(make_shared<binary_tree>()) {}
  binary_tree() = default; // fix bug, consider to modify default behavior
};
// searching operation on a binary search tree
template <typename Item>
shared_ptr<binary_tree<Item>>
search_tree(const Item &src, const shared_ptr<binary_tree<Item>> &tr) {
  // searching operation begin on root, then compare if less move to
  // left otherwise move to right until we traverse all node on a tree
  if (!tr) // there is no element to traverse
    return nullptr;
  if (tr->item == src) // destination
    return tr;
  cout << tr->item << " -- ";
  if (src < tr->item) // compare given string to current item not vice versa
    return search_tree(src, tr->left); // move left if the case is src<tr->item
  else                                 // otherwise move right
    return search_tree(src, tr->right);
}
// show all node and it's value
template <typename Item>
void show_tree(const shared_ptr<binary_tree<Item>> &tr) {
  if (tr) // the traversal only happen if there is a node inside a binary tree
  {
    show_tree(tr->left);
    cout << tr->item << " ";
    show_tree(tr->right);
  }
}
//testing purpose for binary tree implementation
void test_binaryTree_implement();
//double linked list declaration
template <typename Object> struct double_list {
  Object item;
  shared_ptr<double_list> prev;
  shared_ptr<double_list> next;
};
//show all node in a double linked list recursive version
void show_doublyList(const shared_ptr<double_list<string>> &);
//testing purpose for double linked list method
void test_doubleList_implement();
//searching operation on double linked list
shared_ptr<double_list<string>> search_dbList(const string &,
		const shared_ptr<double_list<string>>&);
//insertion on double linked list
void push_back_dbList(const string&, shared_ptr<double_list<string>>&);
//insertion on double linked list, push front
void push_front_dbList(const string&, shared_ptr<double_list<string>>&);
} // namespace algorithm
