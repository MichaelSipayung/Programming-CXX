/*algorithm source code, this my private experiment using modern c++
 *some implementation may not really follow best design, but
 *I do really try to improve piece by piece of the routine
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
  explicit binary_tree(Item val_root)
      : item(std::move(val_root)), parent(make_shared<binary_tree>()),
        left(make_shared<binary_tree>()), right(make_shared<binary_tree>()) {}
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
                                       // otherwise move right
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
// finding minimum of the element on a tree, the minimum element is
// always place in the left of the tree, just look to left most
template <typename Item>
shared_ptr<binary_tree<Item>>
find_min_tree(const shared_ptr<binary_tree<Item>> &tr) {
  if (!tr) // there is no element, just show nothing
    return nullptr;
  if (!tr->left)
    return tr;
  return find_min_tree(tr->left);
}
// finding maximum of the element on a tree, the maximum element is
// always place in the right of the tree, just look to right most
template <typename Item>
shared_ptr<binary_tree<Item>>
find_max_tree(const shared_ptr<binary_tree<Item>> &tr) {
  if (!tr)
    return nullptr;
  auto temp = tr;
  while (temp->right)
    temp = temp->right;
  return temp;
}
// insertion a binary tree, insertion happen while we meet nullptr
// placing a node is according to the item is less than put on the right
template <typename Item>
void insert_node_tree(const Item &item, shared_ptr<binary_tree<Item>> &parent,
                      shared_ptr<binary_tree<Item>> &tr) {
  if (!tr) {                                      // meet nullptr
    auto temp = make_shared<binary_tree<Item>>(); // allocate new object
    temp->item = item;     // place the fresh item to temporary object
    temp->parent = parent; // since the parent is optional, we need not worry
    tr = temp;             // just move all temporary assignment above
    return;                // don't forget to stop after insertion
  }
  if (item < tr->item)                    // less than, focus on the left
    insert_node_tree(item, tr, tr->left); // move to left until nullptr
                                          // encounter
  else                                    // otherwise move to right of subtree
    insert_node_tree(item, tr, tr->right);
}
// test case for insertion on a binary tree
void test_insertion_tree();
// testing purpose for binary tree implementation
void test_binaryTree_implement();
// double linked list declaration
template <typename Object> struct double_list {
  Object item;
  shared_ptr<double_list> prev;
  shared_ptr<double_list> next;
};
// show all node in a double linked list recursive version
void show_doubly_list(const shared_ptr<double_list<string>> &);
// testing purpose for double linked list method
void test_double_list_implement();
// searching operation on double linked list
shared_ptr<double_list<string>>
search_db_list(const string &, const shared_ptr<double_list<string>> &);
// insertion on double linked list
void push_back_db_list(const string &, shared_ptr<double_list<string>> &);
// insertion on double linked list, push front
void push_front_dbList(const string &, shared_ptr<double_list<string>> &);
// successor descendant, finding successor of the given node
template <typename Item>
shared_ptr<binary_tree<Item>>
successor_node(const shared_ptr<binary_tree<Item>> &tr) {
  if (!tr) // node is null, return null
    return nullptr;
  auto temp = tr->right; // successor of tr is placed on the right
  while (temp->left)     // traverse, if there is a sub node, focus to the left
    temp = temp->left;   // assign the current left node
  return temp;           // return the successor of tr
}
// deletion on a binary tree, the challenge task is delete node with to children
template <typename Item>
void delete_node_tree(const Item &del, shared_ptr<binary_tree<Item>> &tr) {
  if (!tr) // null pointer, do nothing, as base case
    return;
  // begin operation, look the destination
  if (del < tr->item) // look left if it's less than
    delete_node_tree(del, tr->left);
  else if (tr->item < del) // look right if it's greater than
    delete_node_tree(del, tr->right);
  else if ((tr->left) && (tr->right)) // contain two child, pay attention
  {
    tr->item = find_min_tree(tr->right)->item; // look the minimum
    delete_node_tree(tr->item, tr->right);
  } else {
    // since we are using smart pointer, we care not to delete it explicitly
    // auto temp = tr; //store in temporary object
    tr = (tr->left) ? tr->left : tr->right; // replace the destination
    // temp.reset(); //clear the old memory
  }
}
// testing for deletion in binary search tree
void delete_node_test();
// predecessor descendant, finding predecessor of the given node
template <typename Item>
shared_ptr<binary_tree<Item>>
predecessor_node(const shared_ptr<binary_tree<Item>> &tr) {
  if (!tr)
    return nullptr;     // node node
  auto temp = tr->left; // the predecessor is located on the left
  while (temp->right)   // look to right of the left node
    temp = temp->right;
  return temp;
}
// test predecessor and successor function on a binary search tree
template <typename Item>
void test_pred_succ(const shared_ptr<binary_tree<Item>> &tr) {
  auto succ = successor_node(tr);
  cout << endl;
  if (succ)
    cout << "successor_node : " << succ->item << endl;
  auto pred = predecessor_node(tr);
  if (pred)
    cout << "predecessor_node : " << pred->item << endl;
}
// modification of binary search tree, design using class
template <typename Comparable> class binary_search_tree_m {
public:
  binary_search_tree_m();
  binary_search_tree_m(const binary_search_tree_m &rhs);     // copy ctor
  binary_search_tree_m(binary_search_tree_m &&rhs) noexcept; // move ctor
  ~binary_search_tree_m() {                                  // destructor
    clear();
  }
  // finding minimum element
  const Comparable &min() const { return min(root_); }
  // finding maximum element
  const Comparable &max() const { return max(root_); }
  bool contain(const Comparable &x) const; // is x in the binary tree
  // test if there is at least one element or none
  bool empty() const { return !root_; }
  // show all element
  void show(std::ostream &out = cout) const;
  // show all item
  void clear();                     // clear all item
  void insert(const Comparable &);  // insert item
  void insert(const Comparable &&); // insert item  move operation
  void remove(const Comparable &x); // remove item
private:
  struct binary_tree_node {
    Comparable element;
    shared_ptr<binary_tree_node> left;
    shared_ptr<binary_tree_node> right;
    binary_tree_node(const Comparable &x, shared_ptr<binary_tree_node> lh,
                     shared_ptr<binary_tree_node> rh)
        : element(x), left(lh), right(rh) {}
    binary_tree_node(Comparable &&x, shared_ptr<binary_tree_node> lh,
                     shared_ptr<binary_tree_node> rh)
        : element(std::move(x)), left(lh), right(rh) {}
  };
  shared_ptr<binary_tree_node> root_;
  // internal method for binary search tree
  void insert(const Comparable &x,
              shared_ptr<binary_tree_node> &tr); // insertion
  void insert(Comparable &&x, shared_ptr<binary_tree_node> &tr);
  void remove(const Comparable &x,
              shared_ptr<binary_tree_node> &tr); // removing
  shared_ptr<binary_tree_node>
  min(const shared_ptr<binary_tree_node> &tr) const; // min element
  shared_ptr<binary_tree_node>
  max(const shared_ptr<binary_tree_node> &tr) const; // max element
  bool contain(const Comparable &x,
               const shared_ptr<binary_tree_node> &tr) const; // exist
  void clear(shared_ptr<binary_tree_node> &tr);         // clear element
  void show(const shared_ptr<binary_tree_node> &tr,
            std::ostream &out) const; // show all
  // clone current tree, for copy ctor demonstration
  shared_ptr<binary_tree_node> clone(const shared_ptr<binary_tree_node> &tr) const;
};
// default constructor for binary search tree class
template <typename Comparable>
binary_search_tree_m<Comparable>::binary_search_tree_m() = default;
// copy constructor for binary search tree
template <typename Comparable>
binary_search_tree_m<Comparable>::binary_search_tree_m(
    const binary_search_tree_m &rhs)
    : root_(nullptr) {
  root_ = clone(rhs.root_);
}
// move constructor
template <typename Comparable>
binary_search_tree_m<Comparable>::binary_search_tree_m(
    binary_search_tree_m &&rhs) noexcept
    : root_(nullptr) {
  root_ = clone(std::move(rhs.root_));
}
// return true if x is in the tree
template <typename Comparable>
bool binary_search_tree_m<Comparable>::contain(const Comparable &x) const {
  return contain(x, root_);
}
// show all node
template <typename Comparable>
void binary_search_tree_m<Comparable>::show(std::ostream &out) const {
  show(root_, out);
}

// clear all node or item in binary tree
template <typename Comparable> void binary_search_tree_m<Comparable>::clear() {
  clear(root_);
}
// insertion method, insert item x to binary tree
template <typename Comparable>
void binary_search_tree_m<Comparable>::insert(const Comparable &x) {
  insert(x, root_);
}
// insertion, the second version using move
template <typename Comparable>
void binary_search_tree_m<Comparable>::insert(const Comparable &&x) {
  insert(std::move(x), root_);
}
// removing an item, x
template <typename Comparable>
void binary_search_tree_m<Comparable>::remove(const Comparable &x) {
  remove(x, root_);
}
// private member function for node operation, contain: test if x inside the
// tree
template <typename Comparable>
bool binary_search_tree_m<Comparable>::contain(
    const Comparable &x, const shared_ptr<binary_tree_node> &tr) const {
  if (!tr)
    return false;
  if (tr->element < x)
    return contain(x, tr->right);
  if (tr->element > x)
    return contain(x, tr->left);
  return true;
}
// clear all node, clear all item in binary tree
template <typename Comparable>
void binary_search_tree_m<Comparable>::clear(shared_ptr<binary_tree_node> &tr) {
  if (tr) {
    clear(tr->left);  // clear left of the tree
    clear(tr->right); // then clear right of the tree
    tr.reset();       // free the resource
  }
  tr = nullptr; // additional improvements
}

// show current item on a tree
template <typename Comparable>
void binary_search_tree_m<Comparable>::show(
    const shared_ptr<binary_tree_node> &tr, std::ostream &out) const {
  if (tr) { // the tree is not null
    show(tr->left, out);
    out << tr->element << " - ";
    show(tr->right, out);
  }
}
// clone all node to new tree
template <typename Comparable>
shared_ptr<typename binary_search_tree_m<Comparable>::binary_tree_node>
binary_search_tree_m<Comparable>::clone(
    const shared_ptr<binary_tree_node> &tr) const {
  if (!tr)
    return nullptr;
  return make_shared<binary_tree_node>(tr->element, clone(tr->left),
                                       clone(tr->right));
}
// insert an element non-move version
template <typename Comparable>
void binary_search_tree_m<Comparable>::insert(
    const Comparable &x, shared_ptr<binary_tree_node> &tr) {
  // insert x to specific location, constraint is left or right
  if (!tr) // if tr is null pointer
    tr = make_shared<binary_tree_node>(x, nullptr, nullptr);
  else if (tr->element < x)
    insert(x, tr->right); // x is greater, put to right
  else if (tr->element > x)
    insert(x, tr->left); // x is smaller, insert to left
  else
    ; // duplicate element
}
// insertion, by moving the element, the second version
template <typename Comparable>
void binary_search_tree_m<Comparable>::insert(
    Comparable &&x, shared_ptr<binary_tree_node> &tr) {
  if (!tr)
    tr = make_shared<binary_tree_node>(std::move(x), nullptr, nullptr);
  else if (tr->element < x)
    insert(std::move(x), tr->right);
  else if (tr->element > x)
    insert(std::move(x), tr->left);
  else
    ; // duplicate, just return
}
// remove a node or an item from binary search tree
template <typename Comparable>
void binary_search_tree_m<Comparable>::remove(
    const Comparable &x, shared_ptr<binary_tree_node> &tr) {
  if (!tr)
    return; // do nothing there is no item
  if (tr->element < x)
    remove(x, tr->right);
  else if (tr->element > x)
    remove(x, tr->left);
  else if (tr->left && tr->right) { // two children, the special case
    tr->element =
        min(tr->right)->element; // replace the deleted node with pred descent
    remove(tr->element, tr->right); // then move right
  } else // otherwise, replace the new element
  {
    auto temp = tr;
    tr = (tr->left) ? tr->left
                    : tr->right; // there is at least one child? left or right
    temp.reset();                // free the resource
  }
}
// finding minimum element, destination on the left
template <typename Comparable>
shared_ptr<typename binary_search_tree_m<Comparable>::binary_tree_node>
binary_search_tree_m<Comparable>::min(
    const shared_ptr<binary_tree_node> &tr) const {
  if (!tr || !tr->left)
    return tr;          // base case left null, terminate min is tr
  return min(tr->left); // otherwise
}
// finding maximum element, note destination on the right
template <typename Comparable>
shared_ptr<typename binary_search_tree_m<Comparable>::binary_tree_node>
binary_search_tree_m<Comparable>::max(
    const shared_ptr<binary_tree_node> &tr) const {
  if (!tr || !tr->right)
    return tr;
  return max(tr->right); // move right
}
} // namespace algorithm
