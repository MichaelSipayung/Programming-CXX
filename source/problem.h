#ifndef PROBLEM_CODE
#define PROBLEM_CODE
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <stack>
#include <string>
namespace problem {
typedef struct linked_list linkedList;
typedef struct list_node ListNode;
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
  //item pass by value and calling std::move for every ctor
  linked_list(string item, linked_list *next) : item(std::move(item)), next(next) {}
  linked_list() : item(string(" ")), next(nullptr) {}
  explicit linked_list(string s) : item(std::move(s)), next(nullptr) {}
  bool operator==(const linked_list &other) const {
    return item == other.item && next == other.next;
  }
};
// performing binary search algorithm using template
// with running time O(lg n), note for halving range
// begin + (end-begin)/2; the present of begin on the front is
// adding the current left range to traverse [left, right]
// [right, left] !
vector<vector<int>> threeSum(const vector<int> &);
template <typename Object>
void binarySearch(vector<Object> &_x, const Object &_data) {
  if (_x.empty()) // performing nothing because consist no element
    return;
  std::sort(_x.begin(), _x.end());
  size_t begin = 0;
  size_t end = _x.size();
  while (begin <= end) // accept the same range but not the outside
  {
    size_t middle = begin + (end - begin) / 2; // begin + (half)
    if (_data < _x[middle]) {
      end = middle - 1; // move left [begin, middle-1]
    } else if (_data > _x[middle]) {
      begin = middle + 1; // move right [middle+1, end]
    } else {
      cout << "result : " << _x[middle] << endl;
      return;
    }
  }
  std::cerr << "no instance of : " << _data << " found " << endl;
}
void combinationUtil(int arr[], int data[], int start, int end, int index,
                     int r);
void show_result();
long int fact(long int);
auto addTwoNumbers_r(ListNode*, ListNode*, int carry = 0) -> ListNode*;
ListNode *add_two_numbers_m(ListNode *, ListNode *);
void test_add_two_number();
void traverse_liked_list(ListNode *);
long fast_exp(const int &, const int &);
std::string remove_k_digits(const string &, int &);
// searching on linked list
linkedList *search_list(linkedList *, const string &);
void insert_list(linkedList **, const string &);
linkedList *item_head(linkedList *, linkedList *);
void delete_list(linkedList **, linkedList **);
linkedList *successor(const linkedList *, linkedList *);
string pangram(const string&);
int power_sum(int, int);
} // namespace Problem
#endif