#include "operator.hpp"
void testEmpty(const std::vector<int> x) {
  std::cout << "test empty vector, is't empty ? " << std::endl;
  if (!x.empty()) {
    std::cout << "vector has an element" << std::endl;
  }
}
void testBetterWrite(void) {
  int i;
  std::cout << "writting loop and test condition wisely" << std::endl;
  while ((i = getchar()) != 42) {
    std::cout << "do something wisely" << std::endl;
  }
}
void testCompound(void) {
  int sum = 0;
  std::cout << "sum number inclusive : ";
  for (int val = 1; val <= 10; ++val) {
    sum += val;
  }
  std::cout << std::endl;
}
void testPostfixPrefix(void) {
  int i = 0, j;
  j = ++i;
  std::cout << "postfix operator (i,j) :  "
            << "(" << i << ", " << j << ")" << std::endl;
  j = i++;
  std::cout << "prefix operator (i,j) :  "
            << "(" << i << ", " << j << ")" << std::endl;
  std::vector<int> usePostfix = {1, 23, 4, -4, 1, 3, 5};
  std::vector<int>::const_iterator begin = usePostfix.cbegin();
  std::cout << "use postfix if it's necessary" << std::endl;
  while (begin != usePostfix.cend() && *begin >= 0) {
    std::cout << *begin++ << std::endl;
  }
}
void memAccessOper(void) {
  std::string s1 = "a string ", *p = &s1;
  unsigned int n = s1.size();
  std::cout << "access the member of the string class : " << n << std::endl;
  n = (*p).size();
  std::cout << "access the member which *p point : " << n << std::endl;
  std::cout << "access the member which *p point(using arrow operator) : " << n
            << std::endl;
  std::vector<int> y = {1, 2, 3};
  std::vector<int> *x = &y;
  std::cout << "access vector member where they point : " << *(*x).begin()
            << std::endl;
}
void conditionalOpera(void) {
  const int grades = 90;
  std::string finalGrade = (grades < 60) ? "low" : "high";
  std::cout << "using basic conditional operator : " << finalGrade << std::endl;
  finalGrade = (grades > 90) ? "high pass" : (grades < 60) ? "fail" : "pass";
  std::cout << "nested conditional operator : " << finalGrade << std::endl;
}
void bitwiseOperator(void) {
  unsigned int number = 7;
  std::cout << "bitwise left shift 7<<2 : " << (number << 2) << std::endl;
  std::cout << "bitwise right shift 7>>2 : " << (number >> 2) << std::endl;
  std::cout << "bitwise not x : " << (number & 2) << std::endl;
  std::cout << "bitwise or x : " << (number | 2) << std::endl;
  std::cout << "bitwise xor x : " << (number ^ 2) << std::endl;
}
void explicitCast(void) {
  int a = 45, b = 13;
  double div = static_cast<double>(a) / b;
  std::cout << "after using static cast : " << div << std::endl;
  int castDiv = static_cast<int>(div) / 2;
  std::cout << "cast div and divided by b : " << castDiv << std::endl;
}