/*associative container, map, set, multimap and multiset, which allow multiple
 * key for unordered container using unordered version on unordered_ header set
 * is only contain single key which is also its value this program is part of
 * the c++ primer book
 */
#ifndef ASSOC_CONT_REFACTOR_H
#define ASSOC_CONT_REFACTOR_H
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <utility> //the pair type
#include <vector>
namespace Refactor {
// debugPurpose : test if insertion, erasing element and others work properly
// test case map with every type
template <typename Object1, typename Object2>
void debugPurpose(const std::map<Object1, Object2> &_x) {
  for (const auto &item : _x)
    std::cout << "key : " << item.first << " value : " << item.second
              << std::endl;
}
// debugPurpose : test if insertion, erasing element and others work properly
// test case multimap with every type
template <typename Object1, typename Object2>
void debugPurpose(const std::multimap<Object1, Object2> &_x) {
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
void wordCounting();
// using set, key as a value
// modification of word counting program, remove unnecessary word like "or",....
void wordCounting_m();
// using multikey version of associative container
// multimap and multiset located in the same header
void multipleKey(const size_t &_sz);
// pair type, hold two data member
// show how we could initialize pair and access the element
void pairType();
// return pair object from a function
// create a pair of object from vector element
std::pair<std::string, size_t> processPair(const std::vector<std::string> &);
// iterator on associative container
// value_type, key_type, mapped_type ; type for each associative container
void iterOnMap_r(std::map<std::string, size_t> &);
// iterator for sets are const, key or value unchangeable
// since set iterator is const object, it's good to write _x as const object
void iterOnSet(const std::set<int> &);
// iterating across an associative container
// const iterator
void iterAcrossMap(const std::map<std::string, int> &);
// adding some elements from vector of string to set
// if vector holds the same value, set only use one of that
void addingElementSet(std::set<std::string> &);
// adding the elements from vector to map using make pair or list initializer
void addingElementMap(std::map<std::string, size_t> &);
// return from insert member
void addingElementMapRet(std::map<std::string, int> &);
// working with multimap and multiset
// multiple key on a map and multiple key or value on set
// adding element to multimap
void addingElementMultiMap(std::multimap<std::string, std::string> &);
// erasing an element or specific range on associative container
// test case map
template <typename Object1, typename Object2>
void eraseMap(std::map<Object1, Object2> &_x, const Object1 &_key) {
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
void eraseMap(std::multimap<Object1, Object2> &_x, const Object1 &_key) {
  // erase : return how many element were removed
  // return may not only 0 or 1
  if (!_x.empty()) {
    if (_x.erase(_key)) // 3 version (key),(iterator), (beg,end)
      std::cout << "ok : " << _key << " removed\n";
    else // not match the key
      std::cout << "fail: " << _key << " not found!\n";
  } else { // show to the standard error
    std::cerr << "error, map is empty";
    return;
  }
}
// subscripting on map container, multimap and set not provide subscript
// if key exist, change the value, but if not make one
template <typename Object1, typename Object2>
void subscriptMap(std::map<Object1, Object2> &_x, const Object1 &_key,
                  const Object2 &_val) {
  _x[_key] = _val; // key is exists, don't write but change val
  // test the result
  Refactor::debugPurpose(_x);
}
// prefer accessing elements using function rather
// than subscript operator since it will write if not exist
template <typename Object>
void accessElementContainer(const std::set<Object> &_x, const Object &_y) {
  if (_x.find(_y) != _x.cend())
    std::cout << "key exists : ";
  // using member count, but useless since set has unique key
}
template <typename Object1, typename Object2>
void accessElementContainer(const std::map<Object1, Object2> &_x,
                            const Object1 &_y) {
  if (_x.find(_y) != _x.cend())
    std::cout << "key exist : " << _y;
}
// finding elements in a multimap and multiset
// using count to tell that we want to know total object
// find return iterator to the given key
template <typename Object1, typename Object2>
void accessElementContainer(const std::multimap<Object1, Object2> &_x,
                            const Object1 &_y) {
  if (_x.size() == 0)
    return;
  // _y is the key, traverse all value with the given key
  // for multimap, the key with different value will be adjacent
  auto n = _x.count(_y);   // total elements
  auto iter = _x.find(_y); // return iterator to the first match
  // traverse n times
  while (n) {
    std::cout << iter->second << " | ";
    ++iter; // advance to next
    --n;    // keep track, zero is indicator to stop
  }
}
// alternative solution to find element using
// lower_bound and upper_bound member
template <typename Object1, typename Object2>
void accessElementContainer_m(const std::multimap<Object1, Object2> &_x,
                              const Object1 &_y) {
  if (_x.size() == 0)
    return;
  auto begin = _x.lower_bound(_y); // return iterator first position
  auto end = _x.upper_bound(_y);   // return to the end match position
  while (begin != end) {
    std::cout << begin->second << " | ";
    ++begin;
  }
}
void wordTransform(std::ifstream &, std::ifstream &);
std::map<std::string, std::string> buildMap(std::ifstream &);
const std::string &transform(const std::string &,
                             const std::map<std::string, std::string> &);
} // namespace Refactor
#endif