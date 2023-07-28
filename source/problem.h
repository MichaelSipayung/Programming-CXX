#ifndef PROBLEM_CODE
#define PROBLEM_CODE
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <string>
namespace Problem {
// performing binary search algorithm using template
// with running time O(lg n), note for halving range
// begin + (end-begin)/2; the present of begin on the front is
// adding the current left range to traverse [left, right]
// [right, left] !
vector<vector<int>> threeSum(vector<int> &);
template <typename Object>
void binarySearch(vector<Object> &_x, const Object &_data) {
  if (_x.empty()) // performing nothing because it it consist no element
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
} // namespace Problem
#endif