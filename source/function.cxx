#include "function.hpp"
// function definition
long double fact(int x) {
  long double ret = 1;
  while (x > 1) {
    ret *= x--;
  }
  return ret;
}
size_t count_calls(void) {
  static size_t ctr = 0; // value will persist across calls
  return ++ctr;
}
void reset(int *ip) {
  *ip = 0;
  ip = 0; // the argument is unchanged
}
void resetByref(int &n) { n = 0; }
bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}
std::string::size_type find_char(const std::string &s, char c,
                                 std::string::size_type &occurs) {
  auto ret = s.size();
  occurs = 0;
  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size()) {
        ret = i; // remember the first occurence of c
      }          // assume not found, ret =0
      ++occurs;
    }
  }
  return ret;
}
void consParameter(const int x) {
  std::cout << "ignored top level const to argumen " << std::endl;
  std::cout << "show value : " << x << " (read only)" << std::endl;
}
void passArray(int *x) {
  std::cout << "pass array using pointer : " << (*x) << std::endl;
}
void passArrayElement(int x[10]) {
  std::cout << "first element : " << x[0] << std::endl;
}
void traverse(const int x[10]) {
  for (size_t i = 0; i < 10; i++) {
    std::cout << x[i] << " ";
  }
  std::cout << std::endl;
}
void printCStyleArr(const char *cp) {
  if (cp) {
    while (*cp) {
      std::cout << *cp++ << " ";
    }
  } else {
    std::cout << "sorry parameter is empty" << std::endl;
  }
}
void printStantLibConv(const int *beg, const int *end) {
  while (beg != end) {
    std::cout << *beg++ << " ";
  }
  std::cout << std::endl;
}
void printExplicitSize(const int a[], size_t size) {
  for (size_t i = 0; i != size; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
void arrayrefAsPar(int (&arr)[10]) { // parameter is a reference to an array
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
void multDimen(const int x[][NDATA], const size_t row) {
  for (size_t i = 0; i < row; ++i) {
    for (size_t j = 0; j < NDATA; ++j) {
      std::cout << x[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
int gcdFind(int p, int q) {
  if (q == 0) {
    return p;
  }
  int r = p % q;
  return gcdFind(q, r);
}
