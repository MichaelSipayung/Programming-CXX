/*associative container, map, set, multimap and multiset, which allow multiple
 * key for unordered container using unordered version on unordered_ header set
 * is only contain single key which is also its value this program is part of
 * the c++ primer book
 */
#pragma once
#include "m_sales.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <utility> //the pair type
#include <vector>
namespace Refactor {
// debugPurpose : test if insertion, erasing element and others work properly
// test case map with every type
template <typename Object1, typename Object2>
void debug_purpose(const std::map<Object1, Object2> &_x) {
  for (const auto &item : _x)
    std::cout << "key : " << item.first << " value : " << item.second
              << std::endl;
}
// debugPurpose : test if insertion, erasing element and others work properly
// test case multimap with every type
template <typename Object1, typename Object2>
void debug_purpose(const std::multimap<Object1, Object2> &_x) {
  for (const auto &item : _x)
    std::cout << "key : " << item.first << " value : " << item.second
              << std::endl;
}
// debugPurpose : test if insertion, erasing element and others work properly
// test case set
template <typename Object> void debugPurpose(const std::set<Object> &_x) {
  for (const auto &item : _x)
    std::cout << "key : " << item << std::endl;
}
// first word_counting program
void word_counting();
// using set, key as a value
// modification of word counting program, remove unnecessary word like "or",....
void word_counting_m();
// using multi key version of associative container
// multimap and multiset located in the same header
void multiple_key(const size_t &sz);
// pair type, hold two data member
// show how we could initialize pair and access the element
void pair_type();
// return pair object from a function
// create a pair of object from vector element
std::pair<std::string, size_t> process_pair(const std::vector<std::string> &);
// iterator on associative container
// value_type, key_type, mapped_type ; type for each associative container
void iterate_map_r(std::map<std::string, size_t> &);
// iterator for sets are const, key or value unchangeable
// since set iterator is const object, it's good to write _x as const object
void iterate_on_set(const std::set<int> &);
// iterating across an associative container
// const iterator
void iterate_across_map(const std::map<std::string, int> &);
// adding some elements from vector of string to set
// if vector holds the same value, set only use one of that
void adding_element_set(std::set<std::string> &);
// adding the elements from vector to map using make pair or list initializer
void adding_element_map(std::map<std::string, size_t> &);
// return from insert member
void adding_element_map_ret(std::map<std::string, int> &);
// working with multimap and multiset
// multiple key on a map and multiple key or value on set
// adding element to multimap
void adding_element_multi_map(std::multimap<std::string, std::string> &);
// erasing an element or specific range on associative container
// test case map
template <typename Object1, typename Object2>
void erase_map(std::map<Object1, Object2> &_x, const Object1 &_key) {
  // erase : return how many element were removed
  // for map it's o or 1
  if (!_x.empty()) {
    if (_x.erase(_key)) // there are 3 version of remove function
      std::cout << "ok : " << _key << " removed\n";
    else // not match the key
      std::cout << "fail: " << _key << " not found!\n";
  } else { // show to the standard error
    std::cerr << "error, map is empty";
    return;
  }
}
// erasing element with specifiy key on multimap
template <typename Object1, typename Object2>
void erase_map(std::multimap<Object1, Object2> &x, const Object1 &key) {
  // erase : return how many element were removed
  // return may not only 0 or 1
  if (!x.empty()) {
    if (x.erase(key)) // 3 version (key),(iterator), (beg,end)
      std::cout << "ok : " << key << " removed\n";
    else // not match the key
      std::cout << "fail: " << key << " not found!\n";
  } else { // show to the standard error
    std::cerr << "error, map is empty";
    return;
  }
}
// subscripting on map container, multimap and set not provide subscript
// if key exist, change the value, but if not make one
template <typename Object1, typename Object2>
void subscript_map(std::map<Object1, Object2> &x, const Object1 &key,
                   const Object2 &_val) {
  x[key] = _val; // key is exists, don't write but change val
  // test the result
  Refactor::debugPurpose(x);
}
// prefer accessing elements using function rather
// than subscript operator since it will write if not exist
template <typename Object>
void access_element_container(const std::set<Object> &x, const Object &y) {
  if (x.contains(y))
    std::cout << "key exists : ";
  // using member count, but useless since set has unique key
}
template <typename Object1, typename Object2>
void access_element_container(const std::map<Object1, Object2> &x,
                              const Object1 &y) {
  if (x.contains(y))
    std::cout << "key exist : " << y;
}
// finding elements in a multimap and multiset
// using count to tell that we want to know total object
// find return iterator to the given key
template <typename Object1, typename Object2>
void access_element_container(const std::multimap<Object1, Object2> &x,
                              const Object1 &y) {
  if (x.size() == 0)
    return;
  // _y is the key, traverse all value with the given key
  // for multimap, the key with different value will be adjacent
  auto n = x.count(y);      // total elements
  auto iterate = x.find(y); // return iterator to the first match
  // traverse n times
  while (n) {
    std::cout << iterate->second << " | ";
    ++iterate; // advance to next
    --n;       // keep track, zero is indicator to stop
  }
}
// alternative solution to find element using
// lower_bound and upper_bound member
template <typename Object1, typename Object2>
void access_element_container_m(const std::multimap<Object1, Object2> &x,
                                const Object1 &y) {
  if (x.size() == 0)
    return;
  auto begin = x.lower_bound(y); // return iterator first position
  auto end = x.upper_bound(y);   // return to the end match position
  while (begin != end) {
    std::cout << begin->second << " | ";
    ++begin;
  }
}
void word_transform(std::ifstream &, std::ifstream &);
std::map<std::string, std::string> build_map(std::ifstream &);
const std::string &transform(const std::string &,
                             const std::map<std::string, std::string> &);
// hash-er function, calculate hash code
size_t hasher(const M_Sales_data &sd);
std::unordered_map<std::string, size_t> &
word_count(std::unordered_map<std::string, size_t> &);
/*std::unordered_map<M_Sales_data, decltype(hasher)*,size_t> &wordCount
  (std::unordered_map<M_Sales_data, decltype(hasher)*, size_t>&);
*/
} // namespace Refactor
