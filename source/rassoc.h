/*associative container, map, set, multimap and multiset, which allow multiple key
 * for unordered container using unordered version on unordered_ header
 * set is only contain single key which is also its value
 * this program is part of the c++ primer book
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
#include <vector>
#include <utility>//the pair type
using std::pair;
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
//using multikey version of associative container
//multimap and multiset located in the same header
void multipleKey(const size_t &_sz){
  std::vector<int> number;
  //define a vector which is containt _sz*2 element
  for (size_t i = 0; i <_sz ; ++i) {
    number.push_back(i);
    number.push_back(i);
  }
  //initialize set, set must contain unique key
  set<int> single_key (number.begin(), number.end()); //hold _sz element
  //initialize multiset, allow the same key
  multiset<int> multi_key (number.begin(), number.end()); //hold 2*_sz
  cout<<"vector size : "<<number.size()<<endl;
  cout<<"set size -> "<<single_key.size()<<endl;
  cout<<"multiset : "<<multi_key.size()<<endl;
}
//pair type, hold two data member
//show how we could initialize pair and access the element
void pairType(){
  pair<string, size_t> word_cnt; //hold string and size_t
  pair<string,int> age_cnt; //hold string and int
  //assign using member of pair
  word_cnt.first="jack";
  word_cnt.second=1;
  age_cnt.first="michael";
  age_cnt.second=25;
  //call to standard output
  cout<<"word :" <<word_cnt.first<<" ,count : "<<word_cnt.second<<endl;
  cout<<"name :" <<age_cnt.first<<" ,age : "<<age_cnt.second<<endl;
}
//return pair object from a function
//create a pair of object from vector element
pair<string,size_t> processPair(const std::vector<string> &_x){
  //process _x
  if(!_x.empty()) //not empty, using _x to initialize the pair
    return {_x.back(),_x.size()}; //using list initialize
  else
    return pair<string,size_t>(); //explicitly constructed ret val
  //an alternative to do this is call make_pair function
}
} // namespace Refactor
#endif