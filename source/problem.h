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
namespace Problem {
typedef struct linkedList linkedList;
typedef struct ListNode ListNode;
// definition for singly-linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {}
  bool operator==(const ListNode &other) const {
    return val == other.val && next == other.next;
  }
};
// single linked list declaration
struct linkedList {
  string item;
  linkedList *next;
  linkedList(const string &item, linkedList *next) : item(item), next(next) {}
  linkedList() : item(string(" ")), next(nullptr) {}
  explicit linkedList(const string &_s) : item(_s), next(nullptr) {}
  bool operator==(const linkedList &other) const {
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
  size_t middle;
  while (begin <= end) // accept the same range but not the outside
  {
    middle = begin + (end - begin) / 2; // begin + (half)
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
void showResult();
long int fact(long int);
ListNode *addTwoNumbers_r(ListNode *, ListNode *, int carry = 0);
ListNode *addTwoNumbers_m(ListNode *, ListNode *);
void testAddTwoNumber();
void traverseLikedList(ListNode *);
long fastExp(const int &, const int &);
std::string removeKDigits(const string &, int &);
// searching on linked list
linkedList *searchList(linkedList *, const string &);
void insert_list(linkedList **, const string &);
linkedList *item_head(linkedList *, linkedList *);
void delete_list(linkedList **, linkedList **);
linkedList *successor(linkedList *, linkedList *);
} // namespace Problem
#endif