#include "rassoc.h"
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
#include <fstream>
#include <utility> //the pair type
#include <vector>
using std::ifstream;
#include <sstream>
using std::istringstream;
using std::pair;
using std::runtime_error;
using std::vector;

namespace Refactor {
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
pair<string, size_t> processPair(const std::vector<string> &_x) {
  // process _x
  if (!_x.empty())                 // not empty, using _x to initialize the pair
    return {_x.back(), _x.size()}; // using list initialize
  else
    return {}; // explicitly constructed ret val
  // an alternative to do this is call make_pair function
}
void iterOnMap_r(map<string, size_t> &_x) {
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
void iterOnSet(const set<int> &_x) {
  auto begin = _x.begin();
  cout << "[ ";
  while (begin != _x.end())
    cout << *begin++ << " | "; // note : const object
  cout << " ]" << endl;
}
void iterAcrossMap(const map<string, int> &_x) {
  auto map_it = _x.cbegin();
  while (map_it != _x.cend()) {
    cout << map_it->first << " occurs " << map_it->second << " times " << endl;
    ++map_it; // increment the iterator to denote the next element
  }
}
void addingElementSet(set<string> &_x) {
  vector<string> y = {"is", "the", "or", "must", "less"};
  cout << "current size of set : " << _x.size() << endl;
  _x.insert(y.cbegin(), y.cend());
  // for debugging purpose
  cout << "show key or value : ";
  for (const auto &item : _x)
    cout << item << " | ";
}
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
void addingElementMultiMap(multimap<string, string> &_x) {
  _x.insert({"John", "Math for fun"});
  // insert same author but different value
  _x.insert({"John", "Basic Calculus"});
  _x.insert({"John", "Differential Calculus"});
  _x.insert({"Miller", "Basic Algebra"});
  _x.insert({"Miller", "Matrix Cookbook"});
  // debugging purpose
  debugPurpose(_x);
}
//  this program has already pass the test
//  the word transformation program, the first arguments is the
//  transformation rule and the last is the word we want to transform
void wordTransform(ifstream &map_file, ifstream &input) {
  auto trans_map = buildMap(map_file); // store the transformation
  string text;                         // hold each line from the input
  while (getline(input, text))         // read a line of input
  {
    istringstream stream(text); // read each word
    string word;
    bool firstword = true; // controls whether a space is printed
    // using nested loop to get a word each line
    while (stream >> word) {
      if (firstword)
        firstword = false;
      else
        cout << " "; // print a space between words
      // transform returns its first arguments or its transformation
      cout << transform(word, trans_map); // print the output
    }
    cout << endl; // done with this line of input
  }
}
// buildMap : reads its given file and builds the transformation map
// in short this is the transformation rules
map<string, string> buildMap(ifstream &map_file) {
  map<string, string> trans_map; // hold the transformation
  string key;                    // a word to transform
  string value;                  // phrase to use instead
  // read the first word into key and the rest of the line into value
  // calling getline means after read key read the rest before newline
  while (map_file >> key && getline(map_file, value)) {
    // since getline will read whitespace betweeen word and rule
    // we must calling susbstr to ensure the rule not followed by space
    if (value.size() > 1)               // check that there is a transformation
      trans_map[key] = value.substr(1); // skip leading space
    else
      throw runtime_error("no rule for " + key);
  }
  return trans_map;
}
// transform : if given string is in map, return the corresponding
// transformation, and if not return its argument, m is map which is contain
// the transformation rule return by buildMap function
const string &transform(const string &s, const map<string, string> &m) {
  // the actual map work
  auto map_it = m.find(s);
  // if this word is in transformation mpa
  if (map_it != m.cend())
    return map_it->second; // use the replacement word
  else
    return s; // otherwise return the original unchanged
}
} // namespace Refactor