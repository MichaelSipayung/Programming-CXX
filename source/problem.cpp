#include "problem.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <cmath>
#include <set>
namespace problem {
// result must store on global scope, since we want to use it on
// showResult function
vector<int> result;
// combinationUtil: generate all combination given arr store
// the result on data[], total element we want to combine
void combination_util(int arr[], int data[], int start, int end, int index,
                      int r) {
  // Current combination is ready to be printed, print it
  if (index == r) {
    for (int j = 0; j < r; j++) {
      result.push_back(data[j]);
    }
    return;
  }
  // replace index with all possible elements. The condition
  // "end-i+1 >= r-index" makes sure that including one element
  // at index will make a combination with remaining elements
  // at remaining positions
  for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
    data[index] = arr[i];
    combination_util(arr, data, i + 1, end, index + 1, r);
  }
}
// show combination result, return void
void show_result() {
  for (const auto &item : result)
    cout << item << " | ";
}
// 3sum problem, leetcode.com problem
vector<vector<int>> three_sum(const vector<int> &nums) {
  int arr[3];
  std::copy(nums.begin(), nums.end(), arr + 0);
  int data[3];
  combination_util(arr, data, 0, static_cast<int>(nums.size()) - 1, 0, 3);
  const long int total_com = fact(static_cast<int>(nums.size())) /
                             (6 * (fact(static_cast<int>(nums.size()) - 3)));
  int temp_obj[4][3];
  vector<vector<int>> temp;
  for (int i = 0; i < total_com; ++i) {
    int total = 0;
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
list_node *add_two_numbers_r(list_node *link1, list_node *link2, int carry) {
  // special case, when we add each number one by one
  // but there is remaining element, for example 999 + 99 = 8901
  // forgetting carry can happen during each node added
  if (!link1 && !link2) {
    // there is still carry result or remaining number
    if (carry) {
      const auto temp = new list_node(carry); // example 999 + 99 = 8901
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
        add_two_numbers_r(link1->next, link2->next,
                          carry); // recursive call to link1 and link2 next
  }
  // there are still exist number to add on link1 even link2 is nullptr
  //  we must do addition,  special case, link1 contain more digit
  else if (link1) {
    link1->val += carry;
    carry = link1->val / 10;
    link1->val = link1->val % 10;
    link1->next = add_two_numbers_r(link1->next, nullptr,
                                    carry); // recursive call to link1->next
    return link1;
  }
  // link2 still contain number to add, even if link1 is nullptr
  // we must do addition, special case, link2 contain more digit
  else {
    link2->val += carry;
    carry = link2->val / 10;
    link2->val = link2->val % 10;
    link2->next = add_two_numbers_r(nullptr, link2->next,
                                    carry); // recursive call to link2->next
    return link2;
  }
  return link1;
}
// adding two singly linked list, non-recursive version
// stopping condition : l1 and l2 and carry is null
list_node *add_two_numbers_m(list_node *list1, list_node *list2) {
  // adding dummy node
  auto *dummyHead = new list_node(0);
  // remember the current node
  list_node *curr = dummyHead;
  // carry is the remainder, since we only have one digit! 2+9 =11
  // since sum / 10 = 1, store that value as  to carry
  int carry = 0;
  // condition to satisfy
  // list1 or list2 not null and carry is still not 0
  while (list1 != nullptr || list2 != nullptr || carry != 0) {
    const int x = list1 ? list1->val : 0; // if there is existed to add
    const int y = list2 ? list2->val : 0; // same as condition list1
    const int sum = carry + x + y;        // store the total number
    carry = sum / 10;                     // only contain o or 1 as a value
    // store the solution on curr->next node
    // if sum less than ten, store sum to the
    // current node, otherwise store remainder of sum with ten
    curr->next = new list_node(sum % 10);
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
void test_add_two_number() {
  // store number reverse order
  list_node left_one(9);
  list_node left_nextOne(9, &left_one);
  list_node left_end(9, &left_nextOne);
  // ListNode left_most(1, &left_end);
  list_node right_one(9);
  list_node right_nextOne(9, &right_one);
  list_node right_end(9, &right_nextOne);
  const auto resultLinked = add_two_numbers_r(&left_end, &right_end);
  traverse_liked_list(resultLinked);
}
// show all number one by one from singly linked list
void traverse_liked_list(list_node *ls) {
  cout << " result [";
  while (ls) { // where there is a number
    cout << ls->val << " , ";
    ls = ls->next; // move to next element
  }
  cout << " ]" << endl;
}
// recursive fast exponential function with time complexity O(log n)
long fast_exp(const int &_base, const int &_power) {
  if (_power == 0)
    return 1;
  auto x = fast_exp(_base, _power / 2);
  // recursively doing exponentiation
  return _power % 2 == 0 ? static_cast<long>(std::pow(x, 2))
                         : _base * static_cast<long>(std::pow(x, 2));
}
// remove k digits from string and find the smallest substring
//_x is a string that contain non-negative number and k is number
// of digit we will remove from _x, return the smallest number0
std::string remove_k_digits(const string &_x, int &_k) {
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
  const auto find_zero = std::find(std::begin(stack), std::end(stack), '0');
  if (find_zero != std::begin(stack))
    for (const auto &item : stack)
      store += item;
  else {
    auto begin = stack.begin();
    // ok contain any leading zero, remove it before return
    while (*begin == '0')
      ++begin;
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
linked_list *search_list(linked_list *ls, const string &data) {
  if (ls == nullptr) // if ls is nullptr, return nullptr
    return nullptr;
  return ls->item == data ? ls : search_list(ls->next, data);
}
// insert an element on singly linked list
// update head of data structure using temporary variable
void insert_list(linked_list **ls, const string &item) {
  linked_list *temp = nullptr; // temporary variable
  temp = new linked_list();    // allocate new object
  temp->item = item;           // assign item to temporary object
                               // tem->item = thomas, ls point to jack
  // example : current linked-list : knuth -> jack -> miller
  temp->next = *ls; // temporary.next point to *ls, remember the head
                    // temp->next = jack ->miller
  *ls = temp;       // copy temp to the place pointed by *ls
  // last linked-list : knuth -> thomas ->jack -> miller
}

// find the predecessor because it points to the doomed node
// so its next pointer must be changed, predecessor is element
// before linked-list _rh on _lh, look successor for further explanation
// example : knuth -> miller -> jack, item_head of miller is knuth
linked_list *item_head(linked_list *lh, linked_list *rh) {
  // check if lh point to something
  if ((lh == nullptr) || (lh->next == nullptr))
    return nullptr;
  // traverse the next linked list
  // if it's, return head otherwise look recursively to next
  return lh->next == rh ? lh : item_head(lh->next, rh);
}
// delete linked-list from given position del from lh
// if del point to first linked list or front/ begin
// head = lh.next otherwise predecessor.next = (*del).next
void delete_list(linked_list **lh, linked_list **del) {
  linked_list *predecessor = nullptr; // predecessor pointer
  const linked_list *temp = *lh;      // temporary variable
  // find the predecessor of _rh
  predecessor = item_head(*lh, *del); // find head or linked list before del
  // if predecessor is null, take all lh.next to head or move all next element
  // otherwise lh.next contain the linked-list del next
  // if we remove beginning of linked list, move next to head
  predecessor == nullptr ? *lh = temp->next : predecessor->next = (*del)->next;
  free(*del); // free memory used by node
}
// auxiliary function to tell the successor of the linked-list
//_ls is the linked-list which consist of some pointer to it
//_rh is the given list we want to know its successor
linked_list *successor(const linked_list *lh, linked_list *rh) {
  if ((lh == nullptr) ||
      (lh->next == nullptr)) // if given linked-list point to nothing
    return nullptr;          // point to nothing return null pointer
  // recursively look for the successor
  return (lh == rh ? lh->next : successor(lh->next, rh));
}
// pangram problem : A pangram is a string that contains every letter of the
// alphabet. Given a sentence determine whether it is a pangram in the English
// alphabet. Ignore case. Return either pangram or not pangram as appropriate.
string pangram(const string &s) {
  std::set<char> temp;
  if (s.size() < 26)
    return {"not pangram"};
  if (!s.empty() && s.size() <= static_cast<unsigned>(1e3))
    for (const char i : s) {
      if (isalpha(i) || isspace(i)) {
        if (isspace(i))
          continue;
        temp.insert(static_cast<char>(tolower(i)));
      } else
        return {"not pangram"};
    }
  else
    return {"not pangram"};
  return (temp.size() == 26 ? "pangram" : "not pangram");
}
// power sum definition
int power_sum(const int x, const int n) {
  const auto max = static_cast<int>(std::pow(x, (1.0 / n)));
  return max;
}
} // namespace problem