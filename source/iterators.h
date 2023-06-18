/* iterator operation on
 * container, file stream and etc ..
 */
#ifndef ITERATORS_H
#define ITERATORS_H
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
template <typename Object> void iter_print_v(const std::vector<Object> &word) {
  for (auto x : word)
    std::cout << x << " ";
  std::cout << std::endl;
}
template <typename Object> void iter_print_l(const std::list<Object> &word) {
  for (auto x : word)
    std::cout << x << " ";
  std::cout << std::endl;
}
template <typename Object> void iter_print_str(const Object &str) {
  std::cout << str << std::endl;
}
template <typename Object>
void iter_back_inst(std::vector<Object> &dest,
                    const std::vector<Object> &source) {
  std::copy(source.begin(), source.end(), std::back_inserter(dest));
}
template <typename Object>
void iter_front_inst(std::list<Object> &dest, const std::list<Object> &source) {
  std::copy(source.begin(), source.end(), std::front_inserter(dest));
}
template <typename Container>
void iter_inserter(Container &dest, const Container &source) {
  std::copy(source.begin(), source.end(), std::inserter(dest, dest.begin()));
  // inserter : insert element by element which not reverse by order
}
// iostream iterators, istream_iterator, ostream_iterator
template <typename Object>
void iter_istream(std::istream_iterator<Object> &word,
                  std::istream_iterator<Object> &eof) {
  // read from stream, and stop read after type non object or hit the EOF
  std::cout << "using iostream iterator case (read) : ";
  std::vector<Object> vec(word, eof); // construct vec from an iterator range
  std::cout << "show value after encounter the end of file : ";
  iter_print_v(vec);
}
// apply iostream iterator in algorithm
// note library algorithm work with iterator
template <typename Object>
const Object &iter_on_alg(std::istream_iterator<Object> &in,
                          std::istream_iterator<Object> &eof) {
  std::cout << "After the summation : ";
  const Object &result = std::accumulate(in, eof, Object{});
  return result;
}
// using std::ostream_iter
template <typename Object>
void iter_ostream(std::ostream_iterator<Object> &out_iter,
                  const std::vector<Object> &value) {
  for (auto v : value)
    *out_iter++ = v; // the assignment writes this element to cout
  // operator * and ++ do nothing on ostream_iter and istream_iter
  // equals to out_iter = v
  std::cout << std::endl;
}
// using reverse iterator
template <typename Container> void iter_reverse(const Container &data) {
  std::cout << "non reverse iterator : ";
  auto n_begin = std::begin(data);
  auto n_end = std::end(data);
  while (n_begin != n_end) {
    std::cout << *n_begin++ << " ";
  }
  std::cout << "\nusing reverse iterator : ";
  auto begin = std::rbegin(data);
  auto end = std::rend(data);
  while (begin != end)
    std::cout << *begin++
              << " "; // using postfix operator, need not to change the state
}
// relation between reverse iterator
// program to print the word before comma
// case : word at the end of string
void iter_relation(const std::string &data) {
  // find the value in reverse order or traverse the element by reverse order
  auto rcomma = std::find(std::crbegin(data), std::crend(data), ',');
  auto foundIt = std::string(rcomma.base(),
                             data.cend()); // base [data ....base find... end]
  std::cout << "\nfind it : " << foundIt << std::endl;
}
#endif