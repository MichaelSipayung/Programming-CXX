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
// contructor to initialize stack class, no default constructor
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
// for search operation, we assume that item is comparable
// first we look that tree is not null, and check item is is equal
// otherwise, we recursively look to left or right, depend on item size
template <class Item>
tree<Item> *search_tree(tree<Item> *tr, const Item &item) {
  if (tr == nullptr) // base case
    return nullptr;
  if (tr->item == item) // next case after pass base case
    return tr;
  if (tr->item < item) // traverse to left of node
    return search_tree(tr->left, item);
  return search_tree(tr->right, item); // otherwise traverse to right of node
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
list_node *add_two_numbers_m(list_node *, list_node *);
void test_add_two_number();
void traverse_liked_list(list_node *);
long fast_exp(const int &, const int &);
std::string remove_k_digits(const string &, int &);
// searching on linked list
linked_list *search_list(linked_list *, const string &);
void insert_list(linked_list **, const string &);
linked_list *item_head(linked_list *, linked_list *);
void delete_list(linked_list **, linked_list **);
linked_list *successor(const linked_list *, linked_list *);
string pangram(const string &);
int power_sum(int, int);
} // namespace problem
#endif