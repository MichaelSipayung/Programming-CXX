/*
 *Demonstrate how std::bind works
 *replace the behavior of lamda to bind
 */
#ifndef BIND_OBJECT_H
#define BIND_OBJECT_H
#include <algorithm>
#include <functional> //header for std::bind
#include <iostream>
#include <vector>
bool checking_size(const std::string &s, std::string::size_type sz) {
  return s.size() >= sz;
}
// using std::bind as function adaptor
// modify behavior of lamda
void modLambda(const std::vector<std::string> &word) {
  // generate a callable object using std::bind
  auto wc = std::find_if(word.begin(), word.end(),
                         std::bind(checking_size, std::placeholders::_1, 6));
  std::cout << "modify lambda version using std::bind" << std::endl;
  std::cout << "result : " << *wc << std::endl;
}
// another ilustration
bool check_another(const std::string &word, int x) { return (word.size() < x); }
void test_check_another(const std::string &x) {
  auto wc = std::bind(check_another, std::placeholders::_1, 5);
}
void other_f(int v, int w, int x, int y, int z) {
  std::cout << " v : " << v << " w: " << w << " z : " << y << std::endl;
}
void test_other_f() {
  auto wc =
      std::bind(other_f, 2, 3, std::placeholders::_2, 4, std::placeholders::_1);
  wc(3, 5); // call by reverse order for std::bind
}
bool other_f1(int x, int y, const std::string &word, int z,
              const std::string &otherW) {
  if (word.size() < (x + y))
    return false;
  else
    return otherW.size() > z;
}
void test_other_f1() {
  auto wc = std::bind(other_f1, 2, 3, std::placeholders::_2, 5,
                      std::placeholders::_1);
  // call wc(x,y)  == f(2,3,y,5,x) //reverse order
  std::cout << "test how the object arrange in std::bind : "
            << wc("jackie", "geo") << std::endl;
}
// note for bind object
// f(a,b,c,d,e)  = g(x,y) => after bind = f(a,b,y,d,x)
//  binding reference paramaters
std::ostream &bind_print(std::ostream &os, const std::string &s, char c) {
  return os << s << c;
}
void test_bind_print(const std::vector<std::string> &word, std::ostream &os) {
  std::for_each(
      word.begin(), word.end(),
      std::bind(bind_print, std::ref(os), std::placeholders::_1,
                ' ')); // using std::ref(reference obj) for bind reference arg
}
bool bind_corrected(int x, int y, const std::string &word, int x_1,
                    const std::string word_1) {
  if ((x + y) < word.size())
    std::cout << "bind parameter call : (x,y)-> word : " << word << std::endl;
  return false;
  if (x_1 < word_1.size())
    std::cout << "call x_1->word_1 parameters : " << word_1 << std::endl;
  return true;
  return true;
}
void test_bind_corr() {
  auto w_test = std::bind(bind_corrected, 2, 3, std::placeholders::_2, 4,
                          std::placeholders::_1);
  std::cout << "test 1: " << w_test("back arg", "front args")
            << std::endl; // reverse order to assign & call
}
#endif