#ifndef PROBLEM_CODE
#define PROBLEM_CODE
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <string>
namespace problem {
typedef struct linked_list linked_list;
typedef struct list_node list_node;
typedef struct node node;
typedef struct node_q node_q;

// definition for singly-linked list
struct list_node {
  int val;
  list_node *next;
  list_node() : val(0), next(nullptr) {}
  explicit list_node(const int x) : val{x}, next{nullptr} {}
  list_node(const int x, list_node *next) : val{x}, next{next} {}
  bool operator==(const list_node &other) const {
    return val == other.val && next == other.next;
  }
};
// single linked list declaration
struct linked_list {
  string item;
  linked_list *next;
  // item pass by value and calling std::move for every ctor
  linked_list(string item, linked_list *next)
      : item(std::move(item)), next(next) {}
  linked_list() : item(string(" ")), next(nullptr) {}
  explicit linked_list(string s) : item(std::move(s)), next(nullptr) {}
  bool operator==(const linked_list &other) const {
    return item == other.item && next == other.next;
  }
};
// stack declaration based on array implementation
template <class Item> class stack_array_base {
public:
  explicit stack_array_base(const size_t &max);
  bool empty() const;
  void push(const Item &item);
  void pop();
  void top();
  size_t size() const;

private:
  Item *s_;    // pointer
  size_t n_;   // maximum
  size_t idx_; // index
  bool check_size() const;
};
// constructor to initialize stack class, no default constructor
template <class Item>
stack_array_base<Item>::stack_array_base(const size_t &max) : n_(max) {
  s_ = new Item[max];
  idx_ = 0;
}
// check if stack is empty
template <class Item> bool stack_array_base<Item>::empty() const {
  return idx_ == 0;
}
// push an element to stack
template <class Item> void stack_array_base<Item>::push(const Item &item) {
  if (check_size()) {
    std::cerr << "error: push fail";
    return;
  }
  s_[idx_++] = item;
}
// pop an element from stack
template <class Item> void stack_array_base<Item>::pop() {
  if (idx_ == 0) {
    std::cerr << "error: pop fail";
    return;
  }
  --idx_;
}
// show an element in top of the stack
template <class Item> void stack_array_base<Item>::top() {
  if (idx_ == 0)
    return;
  cout << s_[idx_ - 1];
}
// check the current size of stack
template <class Item> size_t stack_array_base<Item>::size() const { return n_; }
// check if the index  exceed from maximum capacity of stack
template <class Item> bool stack_array_base<Item>::check_size() const {
  return idx_ >= n_ ? true : false;
}
// stack based on linked-list, all method is equal in array based
template <class Item> class stack_linked_based {
public:
  stack_linked_based() : head_(nullptr), sz_(0) {}
  bool empty() const { return head_ == nullptr; }
  void push(Item x) {
    head_ = new node(x, head_);
    ++sz_; // increase size of linked list
  }
  Item pop();
  size_t size() const { return sz_; }

private:
  struct node {
    node(Item x, node *t);
    Item item;
    node *next;
  };
  node *head_; // head node
  size_t sz_;  // counter for total linked list element
};
// pop method to remove last element
template <class Item> Item stack_linked_based<Item>::pop() {
  if (head_ == nullptr) {
    std::cerr << "error while pop";
    return Item{};
  }
  Item v = head_->item;  // copy item
  node *t = head_->next; // point to next
  delete head_;          // delete from memory
  head_ = t;             // move next to head
  --sz_;                 // increase size of stack
  return v;              // return pop element
}
// constructor for node class
template <class Item> stack_linked_based<Item>::node::node(Item x, node *t) {
  item = x;
  next = t;
}
// fifo queue ADT interface, first in, first out
// non analog version of vector
template <class Item> class queue_linked {
public:
  queue_linked();
  queue_linked(node_q *head, node_q *tail);
  // check if no element on queue
  int empty();
  void put(const Item &);
  Item get();

private:
  struct node_q {
    explicit node_q(Item x);
    Item item;
    node_q *next;
  };
  node_q *head_; // pointer to the head of queue
  node_q *tail_; // to the tail of queue
};
// constructor for node in a queue class
template <class Item> queue_linked<Item>::node_q::node_q(Item x) {
  item = x;
  next = nullptr;
}

template <class Item>
queue_linked<Item>::queue_linked() : head_(nullptr), tail_(nullptr) {}

template <class Item>
queue_linked<Item>::queue_linked(problem::node_q *head, problem::node_q *tail)
    : head_(head), tail_(tail) {}

template <class Item> int queue_linked<Item>::empty() {
  return head_ == nullptr;
}

// put : public member function which is used
// to add element to the queue, put new element to the tail
template <class Item> void queue_linked<Item>::put(const Item &it) {
  node_q *t = tail_;      // temporary variable to store where is the tail
  tail_ = new node_q(it); // request new storage
  if (head_ == nullptr)   // no element
    head_ = tail_;        // head point to tail
  else // otherwise, set tail to proper place, which is t->next is the tail
    t->next = tail_;
}
// get : public member function which is used to pop element
// the first added element will pop
template <class Item> Item queue_linked<Item>::get() {
  // error handling for empty queue to pop
  if (empty()) {
    std::cerr << "error, no element on a queue";
    return Item{};
  }
  Item v = head_->item;    // copy the information, what will be removed
  node_q *t = head_->next; // temporary variable, store next element
  delete head_;            // remove from memory
  head_ = t; // copy t to head, all element on next will move to head
  return v;  // return what i remove
}

// FIFO queue array implementation, the contents of the queue
// are all the elements in the array between head and tail, when
// the end of array encountered, it will back to 0, and if tail==head
// the queue is empty, but if put make it equal we consider the queue to be-full
template <class Item> class queue_array {
public:
  explicit queue_array(const int &max);
  int empty() const;
  void put(const Item &item);
  Item get();

private:
  Item *q_;
  int n_;
  int head_;
  int tail_;
};

// constructor for queue based on array implementation
template <class Item> queue_array<Item>::queue_array(const int &max) {
  q_ = new Item[max + 1];
  n_ = max + 1;
  head_ = n_;
  tail_ = 0;
}

// check if the queue is an empty queue
template <class Item> int queue_array<Item>::empty() const {
  return head_ % n_ == tail_;
}

// insert an element to the end, after element 0,1, ..., n-1
//  using postfix operator, to make sure that tail_ not greater than max+1
template <class Item> void queue_array<Item>::put(const Item &item) {
  q_[tail_++] = item;
  // if tail == _n or maximum element + 1, tail will point to first element
  tail_ = tail_ % n_; // otherwise, insert element to proper place before n_
}

// remove first element, equal to pop front
//  using postfix operator, to make sure that head not greater than max+1
template <class Item> Item queue_array<Item>::get() {
  // first case: head==n, then remove q[0]
  head_ = head_ % n_; // if head < n, remove _q[head], but if head == n
  return q_[head_++]; // get element on the front and pop it or erase it
  // increase the position of head one step to the end
}
// binary search tree implementations, left pointer, right pointer
// parent pointer (an optional pointer)
template <class Item> struct tree {
  Item item;              // data item
  tree *parent = nullptr; // pointer to parent
  tree *left = nullptr;   // pointer to left child
  tree *right = nullptr;  // pointer to right child
};
// we assume that item is comparable, time complexity O(h), h is height of tree
// first we look that tree is not null, and check the root first
// otherwise, we recursively look to left or right, depend on is 
// less or greater than root, and find the suitable position
template <class Item>
tree<Item> *search_tree(tree<Item> *tr, const Item &item) {
  if (tr == nullptr) // base case
    return nullptr;
  if (tr->item == item) // start at the root
    return tr;
  if (tr->item < item) // traverse to left if item less than root
    return search_tree(tr->left, item);
  return search_tree(tr->right, item); // otherwise traverse to right of node
}
// finding minimum element, the minimum element must be the left of subtree
template <class Item> tree<Item> *find_minimum(tree<Item> *tr) {
  if (tr == nullptr)
    return nullptr;
  tree<Item> *min = tr; // pointer to minimum, tou don't need to change the tree
  // look for the left node until left point to nothing
  while (min->left != nullptr)
    min = min->left;
  return min;
}
// find maximum element on a tree, focus on right node of the root
template <class Item> tree<Item> *find_maximum(tree<Item> *t) {
  if (t == nullptr)
    return nullptr;
  tree<Item> *max = t; //temporary variable, you don't need change the tree
  while (max->right != nullptr)
    max = max->right;
  return max;
}
// empty method: check if the tree is null, additional function for error handling
template <class Item> bool empty_tree(tree<Item>* t) {
  return t == nullptr;
}
// traversal in a tree, running time O(n), n is number of node
// recursively look to left and right of subtree, until t is point
// to nothing in binary search tree, processing the item first yield
// pre-order traversals, while processing it last gives a post-order traversal
template <class Item> void traverse_tree(tree<Item> *t) {
  if (t != nullptr) {
    traverse_tree(t->left);  // recursively move to left of tree
    cout << t->item << " | "; // assume t is work well with std::cout
    traverse_tree(t->right); // recursively move to right of tree
  }
}
// insertion in a tree, there is exactly one place to insert an item x
// into a binary search tree T so we can be certain where to find it again.
// we must replace the null pointer found in T after unsuccessful query for the
// key of x, arguments (a pointer to the pointer linking the search subtree
// to the rest of the tree, the key x to be inserted and a parent pointer to
// the parent node containing l, the node is allocated and linked
// in after hitting the null pointer, this implementation combine search and
// node insertion stages of key insertion
template <class Item>
void insert_tree(tree<Item> **dest, const Item &val, tree<Item> *parent) {
  // allocating the node and linking it into the tree is a constant time
  // operation, after the search has been performed in O(h) time
  // height of search tree h denotes the
  if (*dest == nullptr) //allocated the node and linked in after hit nullptr
  {
    tree<Item> *temp = new tree<Item>;  // allocate temporary object
    temp->item = val;                     // put x to temporary variable
    temp->left = temp->right = nullptr; // set left and right point to nothing
    temp->parent = parent;              // copy parent to temporary parent
    *dest = temp;                          // then copy temp to tree
    return; //insertion happen only one time
  }
  //insert to left or right of the node
  if (val < (*dest)->item)
    insert_tree(&((*dest)->left), val, *dest);
  else
    insert_tree(&((*dest)->right), val, *dest);
}
//finding the successor from the deleted node, left is less than right
template<class Item> tree<Item>* successor_descendant(tree<Item>* node_delete)
{
  if (!node_delete->right) //there is no leaf from the deleted node
    return nullptr;
  // other case : contain any or some leaf, look to right
  tree<Item>* successor = node_delete->right;
  // right is also still consist of any node, look to left since it's the successor 
  while (successor->left)
    successor = successor->left;
  return successor;
}
//finding the predecessor from  the deleted node, left is less than right
template<class Item> tree<Item>* predecessor_descendant(tree<Item>* node_delete)
{
  if (!node_delete->left) // look to left of the deleted node
    return nullptr;
  // there is an or some leaf, look to left
  tree<Item>* predecessor = node_delete->left;
  // left is also still consist of any node, look to right
  while (predecessor->right)
    predecessor = predecessor->right;
  return predecessor;
}
// deleted operation on binary search tree, val is value which node will be delete
template<class Item> tree<Item> *delete_node(tree<Item> *tr, const Item &val)
{
  tree<Item> *del_node = search_tree(tr, val); // node with key to delete
  tree<Item>* p_node; //node to be physically deleted
  tree<Item>* child; //d's only child, if any
  if (!del_node){
	  std::cerr << "error : " << val<<" not exist";
    return tr;
  }
  if(!del_node->parent) //del_node is root as a simple case
  {
	  if(!del_node->left && !del_node->right){ //left and right is nullptr
      delete del_node; //no need extra work, just delete the node
      return nullptr; //root only tree
	  }
    // maybe, left or right has a node or child, find node to physically delete
    if (del_node->left) //find the predecessor
      p_node = predecessor_descendant(del_node);
    else //otherwise find the successor
      p_node = successor_descendant(del_node);
  }
  else
  {
    if ((!del_node->left) || (!del_node->right))
    {
      //if deleted node has <= 1 child, so try to find non-null child
      if (del_node->left)
        child = del_node->left;
      else
        child = del_node->right;
      if (del_node->parent->left == del_node) //fill null pointer
        del_node->parent->left = child;
      else
        del_node->parent->right = child;  
      if (child)
        child->parent = del_node->parent;
      delete del_node;
      return tr;
    }
    p_node = successor_descendant(del_node); //p has two children
  }
  Item new_key = p_node->item; //deal with simple case of deletion
  delete_node(tr, p_node->item); 
  del_node->item = new_key;
  return tr;
}
// performing binary search algorithm using template
// with running time O(lg n), note for halving range
// begin + (end-begin)/2; the present of begin on the front is
// adding the current left range to traverse [left, right]
// [right, left] !
vector<vector<int>> three_sum(const vector<int> &);
template <typename Object>
void binary_search(vector<Object> &x, const Object &data) {
  if (x.empty()) // performing nothing because consist no element
    return;
  std::sort(x.begin(), x.end());
  size_t begin = 0;
  size_t end = x.size();
  while (begin <= end) // accept the same range but not the outside
  {
    size_t middle = begin + (end - begin) / 2; // begin + (half)
    if (data < x[middle]) {
      end = middle - 1; // move left [begin, middle-1]
    } else if (data > x[middle]) {
      begin = middle + 1; // move right [middle+1, end]
    } else {
      cout << "result : " << x[middle] << endl;
      return;
    }
  }
  std::cerr << "no instance of : " << data << " found " << endl;
}
void combination_util(int arr[], int data[], int start, int end, int index,
                      int r);
void show_result();
long int fact(long int);
auto add_two_numbers_r(list_node *, list_node *, int carry = 0) -> list_node *;
list_node *add_two_numbers_m(const list_node *, const list_node *);
void test_add_two_number();
void traverse_liked_list(const list_node *);
long fast_exp(const int &, const int &);
std::string remove_k_digits(const string &, int &);
// searching on linked list
linked_list *search_list(linked_list *, const string &);
void insert_list(linked_list **, const string &);
linked_list *item_head(linked_list *, linked_list *);
void delete_list(linked_list **, linked_list **);
linked_list *successor(const linked_list *, linked_list *);
string pangram(const string &);
int power_sum(int, int, int);
long fib_r(int n);
long fib_c(int n);
long cache_fib(int n);
long fib_dynamic(int n);
long fib_ultimate(int n);
long binomial_coefficient(int n, int k);
} // namespace problem
#endif