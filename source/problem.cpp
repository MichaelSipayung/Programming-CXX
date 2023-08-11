#include "problem.h"
#include <iostream>
#include <valarray>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <cmath>
#include <set>
constexpr int max_fib = 92; // assume maximum n
constexpr int unknown = -1;
long f[max_fib + 1]; // array of caching fib values
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
vector<vector<int>> three_sum(const vector<int> &num) {
  int arr[3];
  std::copy(num.begin(), num.end(), arr + 0);
  int data[3];
  combination_util(arr, data, 0, static_cast<int>(num.size()) - 1, 0, 3);
  const long int total_com = fact(static_cast<int>(num.size())) /
                             (6 * (fact(static_cast<int>(num.size()) - 3)));
  int temp_obj[4][3];
  vector<vector<int>> temp;
  for (int i = 0; i < total_com; ++i) {
    int total = 0;
    for (int j = 0; j < 3; ++j) {
      temp_obj[i][j] = result[static_cast<std::vector<int>::size_type>(
                                  static_cast<long>(i)) *
                                  3 +
                              j];
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
list_node *add_two_numbers_m(const list_node *list1, const list_node *list2) {
  // adding dummy node
  auto *dummy_head = new list_node(0);
  // remember the current node
  list_node *cur = dummy_head;
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
    cur->next = new list_node(sum % 10);
    // make curr point to curr->next
    cur = cur->next;
    // check the condition, if not null, move to next node
    // if list1 is point to nothing, assign as nullptr
    list1 = list1 ? list1->next : nullptr;
    list2 = list2 ? list2->next : nullptr;
  }
  return dummy_head->next; // return the result one pass after dummyHead
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
void traverse_liked_list(const list_node *ls) {
  cout << " result [";
  while (ls) { // where there is a number
    cout << ls->val << " , ";
    ls = ls->next; // move to next element
  }
  cout << " ]" << endl;
}
// recursive fast exponential function with time complexity O(log n)
long fast_exp(const int &base, const int &power) {
  if (power == 0)
    return 1;
  const auto x = fast_exp(base, power / 2);
  // recursively doing exponentiation
  return power % 2 == 0 ? static_cast<long>(std::pow(x, 2))
                        : base * static_cast<long>(std::pow(x, 2));
}
// remove k digits from string and find the smallest substring
//_x is a string that contain non-negative number and k is number
// of digit we will remove from _x, return the smallest number0
std::string remove_k_digits(const string &x, int &k) {
  // special case, if there are _k digits to remove
  //  and _k==len(_x) and k=0, and nothing to do
  if (x.empty() || x.size() == static_cast<unsigned int>(k) || k < 0)
    return {"0"};
  vector<char> stack; // store the object
  for (const auto &item : x) {
    // remove element, removing must meet the condition
    // where the k times is limit for removing a number from stack
    while (k > 0 && !stack.empty() && stack.back() > item) {
      stack.pop_back();
      --k;
    }
    stack.push_back(item);
  }
  // while there is an element to pop, until the k times
  // meet, the top conditional statement that not guarantee
  // we remove k times, so pop_back() means remove last element
  // k times, consistently using prefix operator for reduce k value
  while (k > 0) {
    stack.pop_back();
    --k;
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
  // temporary variable
  auto *temp = new linked_list(); // allocate new object
  temp->item = item;              // assign item to temporary object
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
  // predecessor pointer
  const linked_list *temp = *lh; // temporary variable
  // find the predecessor of _rh
  linked_list *predecessor =
      item_head(*lh, *del); // find head or linked list before del
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
// power sum definition, x is target, n is power destination
// and start is, index or base to raise with n
int power_sum(const int x, const int n, int start) {
  if(x==0)
  	return 1;
  int total=0;
  //std::cerr<<"error"<<endl;
  //goal is raise base to n until it equals to x
  for (int i = start+1; pow(i,n)<=x; ++i){
  	cout<<i<<endl;
  	total+= power_sum(x-pow(i,n),n,i);
  	cout<<"tot :"<<total<<endl;
  }
  return total;
}
// compute fibonacci number, f_n = f_n-1 + f_n-2, with f_0 = 0, f-1 =1
long fib_r(const int n) {
  if (n == 0) // base case n=0
    return 0;
  if (n == 1) // base case for n=1
    return 1;
  return fib_r(n - 1) + fib_r(n - 2); // otherwise, call fib recursively
}
// fibonacci number with caching, if f(n) is already compute
// save it using caching technique, here f[n] is the place
// assume f[6] = f[5] + f[4], f[5] = f[4] + f[3] and so on until f[2]
long fib_c(const int n) {
  if (f[n] == unknown) // remember base case is f[0] and f[1]
    f[n] = fib_c(n - 1) +
           fib_c(n - 2); // rule is same, but result is filled in cache
  return f[n]; // save it, example f[6] = fib(5) + fib(4), f[5] = fib(4) +
               // fib(3) ..
  // and sum it without call sum fib(n) every time
}
// main function for compute fibonacci number with caching
// the for loop is intended to fill f[n] or cache result
// this method give better result to recursive version of fib_r with O(n)
long cache_fib(const int n) {
  f[0] = 0; // fir base case
  f[1] = 1;
  for (int i = 2; i <= n; ++i)
    f[i] = unknown;
  return fib_c(n);
}
// find fibonacci number using dynamic programming with performance O(n)
// this program is identically to cache_fib version with recursive call
long fib_dynamic(const int n) {
  vector<int> caching(static_cast<vector<int>::size_type>(n) + 1, 0);
  caching[0] = 0; // base case f(0) = 0
  caching[1] = 1; // and f(1) =1
  for (int i = 2; i <= n; ++i)
    caching[i] = caching[static_cast<std::vector<int>::size_type>(i) - 1] +
                 caching[static_cast<std::vector<int>::size_type>(i) - 2];
  return caching[n];
}
// find fibonacci number using dynamic programming with constant space
// this version only reduce the space required while performing fib_dynamic
// the idea is, we using last two value to compute fib(n)
long fib_ultimate(const int n) {
  long back1 = 1; // last two values for f[0], f[1]
  long back2 = 0;
  if (n == 0)
    return back2; // if n=1, return 0 + 1 !
  for (int i = 2; i < n;
       ++i) { // stopping condition is i < n, since we use last 2 value
    const long next = back1 + back2; // temporary variable for sum
    back2 = back1;
    back1 = next;
  }
  return back1 + back2;
}
// an efficient way to compute binomial coefficient (n\k)
// count the number of ways to choose k things out of n possibilities
long binomial_coefficient(const int n, const int k) {
  constexpr int max = 12; // maximum number
  vector<vector<long>> bc(12,
                          vector<long>(max, 0)); // binomial coefficient table
  // fill left most and right most with base case, value 1
  for (int i = 0; i <= n; ++i)
    bc[i][0] = 1; // base case,  for (n\0) =1
  for (int j = 0; j <= n; j++)
    bc[j][j] = 1; // base case, for (n\n)=1
  // apply dynamic programming, store the coefficient on given matrix
  for (int i = 2; i <= n;
       ++i) // generate n coefficient as general not until k reach
    for (int j = 1; j < i;
         ++j) // j<i, since base case is already filled with value
      bc[i][j] =
          bc[static_cast<std::vector<std::vector<long>>::size_type>(i) - 1]
            [static_cast<std::vector<long>::size_type>(j) - 1] +
          bc[static_cast<std::vector<std::vector<long>>::size_type>(i) - 1]
            [j];   // fill i,j with before and after
  return bc[n][k]; // return the binomial coefficient
}
} // namespace problem