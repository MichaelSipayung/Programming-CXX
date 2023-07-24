/*associative container, map, set, multimap and multiset, which allow multiple
 * key for unordered container using unordered version on unordered_ header set
 * is only contain single key which is also its value this program is part of
 * the c++ primer book
 */
#ifndef ASSOC_CONT_REFACTOR_H
#define ASSOC_CONT_REFACTOR_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <map>
using std::map;
using std::multimap; // allow multiple key on map
#include <set>
using std::multiset; // allow multiple key on a set
using std::set;
#include <utility> //the pair type
#include <vector>
using std::pair;
namespace Refactor {
// debugPurpose : test if insertion, erasing element and others work properly
// test case map with every type
template <typename Object1, typename Object2>
void debugPurpose(const map<Object1, Object2> &_x) {
  for (const auto &item : _x)
    cout << "key : " << item.first << " value : " << item.second << endl;
}
// debugPurpose : test if insertion, erasing element and others work properly
// test case multimap with every type
template <typename Object1, typename Object2>
void debugPurpose(const multimap<Object1, Object2> &_x) {
  for (const auto &item : _x)
    cout << "key : " << item.first << " value : " << item.second << endl;
}
// debugPurpose : test if insertion, erasing element and others work properly
// test case set
template <typename Object> void debugPurpose(const set<Object> &_x) {
  for (const auto &item : _x)
    cout << "key : " << item << endl;
}
// word counting program, using map
// if the given word not exist, create it and
// if the given word exist more than one time, increase it
void wordCounting() {
  map<string, size_t> word_count; // empty map
  string word;
  while (cin >> word)   // put every word in sorted order
    ++word_count[word]; // fetch and increment the counter for word
  for (const auto &item : word_count) // calling member
    cout << item.first << " occurs " << item.second
         << ((item.second > 1) ? " times" : " time") << endl;
}
// using set, key as a value
// modification of word counting program, remove unnecessary word like "or",....
void wordCounting_m() {
  map<string, size_t> word_count; // empty map
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word) {
    if (exclude.find(word) ==
        exclude.end())    // count all word except a list of word on exclude
      ++word_count[word]; // fetch and increment the counter for word
  }
  for (const auto &item : word_count)
    cout << item.first << " occurs " << item.second
         << ((item.second > 1) ? " times" : " time") << endl;
}
// using multikey version of associative container
// multimap and multiset located in the same header
void multipleKey(const size_t &_sz) {
  std::vector<int> number;
  // define a vector which is containt _sz*2 element
  for (size_t i = 0; i < _sz; ++i) {
    number.push_back(i);
    number.push_back(i);
  }
  // initialize set, set must contain unique key
  set<int> single_key(number.begin(), number.end()); // hold _sz element
  // initialize multiset, allow the same key
  multiset<int> multi_key(number.begin(), number.end()); // hold 2*_sz
  cout << "vector size : " << number.size() << endl;
  cout << "set size -> " << single_key.size() << endl;
  cout << "multiset : " << multi_key.size() << endl;
}
// pair type, hold two data member
// show how we could initialize pair and access the element
void pairType() {
  pair<string, size_t> word_cnt; // hold string and size_t
  pair<string, int> age_cnt;     // hold string and int
  // assign using member of pair
  word_cnt.first = "jack";
  word_cnt.second = 1;
  age_cnt.first = "michael";
  age_cnt.second = 25;
  // call to standard output
  cout << "word :" << word_cnt.first << " ,count : " << word_cnt.second << endl;
  cout << "name :" << age_cnt.first << " ,age : " << age_cnt.second << endl;
}
// return pair object from a function
// create a pair of object from vector element
pair<string, size_t> processPair(const std::vector<string> &_x) {
  // process _x
  if (!_x.empty())                 // not empty, using _x to initialize the pair
    return {_x.back(), _x.size()}; // using list initialize
  else
    return {}; // explicitly constructed ret val
  // an alternative to do this is call make_pair function
}
// iterator on associative container
// value_type, key_type, mapped_type ; type for each associative container
void iterOnMap(map<string, size_t> &_x) {
  // we can't change the key but the value can change
  //*begin is a reference to a pair <const string,size_t> object
  if (!_x.empty()) {
    auto begin = _x.begin();
    cout << "show key : " << begin->first << endl;
    cout << "call value : " << begin->second << endl;
    // change the value through the iterator
    begin->second = 14;
    cout << "change value through the iterator : " << begin->second << endl;
  } else {
    std::cerr << "error, wrong size" << endl;
    return;
  }
}
// iterator for sets are const, key or value unchangeable
// since set iterator is const object, it's good to write _x as const object
void iterOnSet(const set<int> &_x) {
  auto begin = _x.begin();
  cout << "[ ";
  while (begin != _x.end())
    cout << *begin++ << " | "; // note : const object
  cout << " ]" << endl;
}
// iterating across an associative container
// const iterator
void iterAcrossMap(const map<string, int> &_x) {
  auto map_it = _x.cbegin();
  while (map_it != _x.cend()) {
    cout << map_it->first << " occurs " << map_it->second << " times " << endl;
    ++map_it; // increment the iterator to denote the next element
  }
}
// adding some elements from vector of string to set
// if vector holds the same value, set only use one of that
void addingElementSet(set<string> &_x) {
  vector<string> y = {"is", "the", "or", "must", "less"};
  cout << "current size of set : " << _x.size() << endl;
  _x.insert(y.cbegin(), y.cend());
  // for debugging purpose
  cout << "show key or value : ";
  for (const auto &item : _x)
    cout << item << " | ";
}
// adding the elements from vector to map using make pair or list initializer
void addingElementMap(map<string, size_t> &_x) {
  vector<string> word = {"miller", "find",   "the", "current", "way",
                         "to",     "attack", "the", "problem"};
  vector<size_t> count = {0, 2, 1, 4, 1, 2, 3, 5, 2};
  // insert key and a value to map, from vector
  auto begin = word.begin();
  auto begin_x = count.begin();
  if (word.size() == count.size()) {
    while (begin != word.end()) {
      _x.insert({*begin++, *begin_x++});
    }
  } else { // assume that vector has different size
    std::cerr << "insertion fail, check the key and value" << endl;
    return;
  }
  // for debugging purpose
  cout << "\nresult [ ";
  for (const auto &item : _x)
    cout << item.first << " : " << item.second << endl;
  cout << " ]" << endl;
}
// return from insert member
void addingElementMapRet(map<string, int> &_x) {
  string word;
  while (cin >> word) {
    // insert an element, if word already in _x, it does nothing
    // return iterator to the given key and bool to indicate the insertion is
    // fail or not
    auto ret = _x.insert({word, 1});
    if (!ret.second)       // word was already in _x
      ++ret.first->second; // increment the counter
  }
}
// working with multimap and multiset
// multiple key on a map and multiple key or value on set
// adding element to multimap
void addingElementMultiMap(multimap<string, string> &_x) {
  _x.insert({"John", "Math for fun"});
  // insert same author but different value
  _x.insert({"John", "Basic Calculus"});
  _x.insert({"Miller", "Basic Algebra"});
  _x.insert({"Miller", "Matrix Cookbook"});
  // debugging purpose
  debugPurpose(_x);
}
// erasing an element or specific range on associative container
// test case map
template <typename Object1, typename Object2>
void eraseMap(map<Object1, Object2> &_x, const Object1 &_key) {
  // erase : return how many element were removed
  // for map it's o or 1
  if (!_x.empty()) {
    if (_x.erase(_key)) // there are 3 version of remove function
      cout << "ok : " << _key << " removed\n";
    else // not match the key
      cout << "fail: " << _key << " not found!\n";
  } else { // show to the standard error
    std::cerr << "error, map is empty";
    return;
  }
}
// erasing element with specifiy key on multimap
template <typename Object1, typename Object2>
void eraseMap(multimap<Object1, Object2> &_x, const Object1 &_key) {
  // erase : return how many element were removed
  // return may not only 0 or 1
  if (!_x.empty()) {
    if (_x.erase(_key)) // 3 version (key),(iterator), (beg,end)
      cout << "ok : " << _key << " removed\n";
    else // not match the key
      cout << "fail: " << _key << " not found!\n";
  } else { // show to the standard error
    std::cerr << "error, map is empty";
    return;
  }
}
// subscripting on map container, multimap and set not provide subscript
// if key exist, change the value, but if not make one
template <typename Object1, typename Object2>
void subscriptMap(map<Object1, Object2> &_x, const Object1 &_key,
                  const Object2 &_val) {
  _x[_key] = _val; // key is exists, don't write but change val
  // test the result
  Refactor::debugPurpose(_x);
}
} // namespace Refactor
#endif