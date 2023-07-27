#ifndef PROBLEM_CODE
#define PROBLEM_CODE
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <string>
namespace Problem {
vector<size_t> spacePosition(const string &_x) {
  vector<size_t> temp;
  for (size_t i = 0; i < _x.length(); ++i)
    if (isspace(_x[i])) {
      temp.push_back(i);
    }
  return temp;
}
string stringReplace(const vector<string> &_dict, const string &_word) {
  string result;
  size_t len = _word.length();
  for (size_t i = 0; i < _dict.size(); ++i) {
    size_t len_dict = _dict[i].length();
    for (size_t j = 0; j <= (len - len_dict); ++j) {
    }
  }
  return result;
}
} // namespace Problem
#endif