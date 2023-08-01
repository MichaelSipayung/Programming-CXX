#include "problem.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <cmath>
namespace Problem {
// result must store on global scope, since we want to use it on
// showResult function
vector<int> result;
// combinationUtil: generate all combination given arr store
// the result on data[], total element we want to combine
void combinationUtil(int arr[], int data[], int start, int end, int index,
                     int r) {
  // Current combination is ready to be printed, print it
  if (index == r) {
    for (int j = 0; j < r; j++) {
      result.push_back(data[j]);
    }
    // printf("\n");
    return;
  }
  // replace index with all possible elements. The condition
  // "end-i+1 >= r-index" makes sure that including one element
  // at index will make a combination with remaining elements
  // at remaining positions
  for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
    data[index] = arr[i];
    combinationUtil(arr, data, i + 1, end, index + 1, r);
  }
}
// show combination result, return void
void showResult() {
  for (const auto &item : result)
    cout << item << " | ";
}
// 3sum problem, leetcode.com problem
vector<vector<int>> threeSum(const vector<int> &nums) {
  int arr[3];
  std::copy(nums.begin(), nums.end(), arr+0);
  int data[3];
  combinationUtil(arr, data, 0, (int)nums.size() - 1, 0, 3);
  long int total_com =
      fact((int)nums.size()) / (6 * (fact((int)nums.size() - 3)));
  int temp_obj[4][3];
  vector<vector<int>> temp;
  int total;
  for (int i = 0; i < total_com; ++i) {
    total = 0;
    for (int j = 0; j < 3; ++j) {
      temp_obj[i][j] = result[i * 3 + j];
      total += temp_obj[i][j];
    }
    if (total == 0) {
      temp.push_back({temp_obj[i][0], temp_obj[i][1], temp_obj[i][2]});
    }
  }
  return temp;
}
long int fact(long int n) {
  if (n < 1)
    return 1;
  return n * fact(n - 1);
}
// leetcode problem, linked list
// two numbers problem, given singly-linked list1 and list2
// find the sum of link1 and link2 reverse order and return that number
ListNode *addTwoNumbers_r(ListNode *link1, ListNode *link2, int carry) {
  // special case, when we add each number one by one
  // but there is remaining element, for example 999 + 99 = 8901
  // forgetting carry can happen during each node added
  if (!link1 && !link2) {
    // there is still carry result or remaining number
    if (carry) {
      auto temp = new ListNode(carry); // example 999 + 99 = 8901
      return temp; // return carry in the right most place, carry is one
    }
    // stop the recursive operation, since carry is 0, link1 and link2
    // point to nothing or there are no node is still exist
    return nullptr;
  }
  // store addition result to link1,if there are exist link1 & link2
  // element to add, general case: have equal digit
  else if (link1 && link2) {
    link1->val += link2->val + carry;
    carry = link1->val / 10; // contain zero or one as a value
    link1->val = link1->val % 10;
    link1->next =
        addTwoNumbers_r(link1->next, link2->next,
                        carry); // recursive call to link1 and link2 next
  }
  // there are still exist number to add on link1 even link2 is nullptr
  //  we must do addition,  special case, link1 contain more digit
  else if (link1) {
    link1->val += carry;
    carry = link1->val / 10;
    link1->val = link1->val % 10;
    link1->next = addTwoNumbers_r(link1->next, nullptr,
                                  carry); // recursive call to link1->next
    return link1;
  }
  // link2 still contain number to add, even if link1 is nullptr
  // we must do addition, special case, link2 contain more digit
  else {
    link2->val += carry;
    carry = link2->val / 10;
    link2->val = link2->val % 10;
    link2->next = addTwoNumbers_r(nullptr, link2->next,
                                  carry); // recursive call to link2->next
    return link2;
  }
  return link1;
}
// adding two singly linked list, non-recursive version
// stopping condition : l1 and l2 and carry is null
ListNode *addTwoNumbers_m(ListNode *list1, ListNode *list2) {
  // adding dummy node
  auto *dummyHead = new ListNode(0);
  // remember the current node
  ListNode *curr = dummyHead;
  // carry is the remainder, since we only have one digit! 2+9 =11
  // since sum / 10 = 1, store that value as  to carry
  int carry = 0;
  // condition to satisfy
  // list1 or list2 not null and carry is still not 0
  while (list1 != nullptr || list2 != nullptr || carry != 0) {
    int x = list1 ? list1->val : 0; // if there is existed to add
    int y = list2 ? list2->val : 0; // same as condition list1
    int sum = carry + x + y;        // store the total number
    carry = sum / 10;               // only contain o or 1 as a value
    // store the solution on curr->next node
    // if sum less than ten, store sum to the
    // current node, otherwise store remainder of sum with ten
    curr->next = new ListNode(sum % 10);
    // make curr point to curr->next
    curr = curr->next;
    // check the condition, if not null, move to next node
    // if list1 is point to nothing, assign as nullptr
    list1 = list1 ? list1->next : nullptr;
    list2 = list2 ? list2->next : nullptr;
  }
  return dummyHead->next; // return the result one pass after dummyHead
}
// demonstration of adding two number from singly linked list A and B
// number are store in reverse order
// the result also in reverse order
void testAddTwoNumber() {
  // store number reverse order
  ListNode left_one(9);
  ListNode left_nextOne(9, &left_one);
  ListNode left_end(9, &left_nextOne);
  // ListNode left_most(1, &left_end);
  ListNode right_one(9);
  ListNode right_nextOne(9, &right_one);
  ListNode right_end(9, &right_nextOne);
  auto resultLinked = addTwoNumbers_r(&left_end, &right_end);
  traverseLikedList(resultLinked);
}
// show all number one by one from singly linked list
void traverseLikedList(ListNode *ls) {
  cout << " result [";
  while (ls) { // where there is a number
    cout << ls->val << " , ";
    ls = ls->next; // move to next element
  }
  cout << " ]" << endl;
}
// recursive fast exponential function with time complexity O(log n)
long fastExp(const int &_base, const int &_power) {
  if (_power == 0)
    return 1;
  auto x = fastExp(_base, _power / 2);
  if (_power % 2 == 0)
    return (long)std::pow(x, 2);
  else
    return _base * (long)std::pow(x, 2);
}
// remove k digits from string and find the smallest substring
//_x is a string that contain non-negative number and k is number
// of digit we will remove from _x, return the smallest number0
std::string removeKDigits(const string &_x, int &_k) {
  // special case, if there are _k digits to remove
  //  and _k==len(_x) and k=0, and nothing to do
  if (_x.empty() || _x.size() == _k || _k < 0)
    return {"0"};
  vector<char> stack; // store the object
  for (const auto &item : _x) {
    // remove element, removing must meet the condition
    // where the k times is limit for removing a number from stack
    while (_k > 0 && !stack.empty() && stack.back() > item) {
      stack.pop_back();
      --_k;
    }
    stack.push_back(item);
  }
  // while there is an element to pop, until the k times
  // meet, the top conditional statement that not guarantee
  // we remove k times, so pop_back() means remove last element
  // k times, consistently using prefix operator for reduce k value
  while (_k > 0) {
    stack.pop_back();
    --_k;
  }
  // store the minimum number, if there is a leading zero, skip it
  // using conditional statement to make sure leading zero is passed
  string store;
  auto find_zero = std::find(std::begin(stack), std::end(stack), '0');
  if (find_zero != std::begin(stack)) {
    for (const auto &item : stack)
      store += item;
  } else {
    auto begin = stack.begin();
    // ok contain any leading zero, remove it before return
    while (*begin == '0') {
      ++begin;
    }
    // after not meet any leading zero, put all to variable store
    while (begin != std::cend(stack)) {
      store += *begin;
      ++begin;
    }
    // all element on stack is zero, return 0
    if (stack.empty())
      return {"0"};
  }
  return store;
}
// definition of searchList, for searching an item on linked list
linkedList *searchList(linkedList *_ls, const string &_data) {
  if (_ls == nullptr)
    return nullptr;
  if (_ls->item == _data) // first searching on head
    return _ls;
  else // traverse recursively on next
    return (searchList(_ls->next, _data));
}
} // namespace Problem