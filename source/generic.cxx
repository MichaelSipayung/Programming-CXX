#include "generic.h"
// using std::find
void findAl(const std::vector<int> &x) {
  if (!x.empty()) {
    int val = 42;
    auto result = std::find(x.begin(), x.end(), val);
    std::cout << "The value " << val
              << (result == x.cend() ? " is not present" : "is present")
              << std::endl;
    std::list<std::string> author_name = {"Miller", "Jack", "Potret",
                                          "Goodfellow", "Anton"};
    std::string find_auth = "miller";
    auto result_auth =
        std::find(author_name.begin(), author_name.end(), find_auth);
    if (result_auth == author_name.cend()) {
      std::cout << "not found" << std::endl;
    }
    // for built in array
    int nat_num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (std::empty(nat_num)) {
      std::cout << "oops nothing to search, this is empty container"
                << std::endl;
    }
    int find_nat = 8;
    auto result_nat =
        std::find(std::begin(nat_num), std::end(nat_num), find_nat);
    if (result_nat == std::cend(nat_num)) {
      std::cout << "sorry not found !" << std::endl;
    } else {
      std::cout << "found, natural num : " << find_nat << std::endl;
    }
  }
  // implemented on string
  std::string isbn = "00X1-988-000-math";
  char c = 'X';
  auto result_isbn = std::find(isbn.begin(), isbn.end(), c);
  std::cout << "is it found, string case " << std::endl;
  if (result_isbn == isbn.cend()) {
    std::cout << "not found" << std::endl;
  } else {
    std::cout << "success, found char : " << c << " in  : " << isbn
              << std::endl;
  }
}
void sumElm(const std::vector<double> &x) {
  // using std::accumulate to sum all the element
  double sum = std::accumulate(x.begin(), x.end(), 0.0);
  std::cout << "return the final sum : " << sum << std::endl;
  // test for string
  std::string auth = "jack";
  auto res_auth = std::accumulate(auth.begin(), auth.end(), std::string(""));
  std::cout << "test for string case : " << res_auth << std::endl;
}
void modifyEl(std::string &x) {
  std::cout << "before performing std::fill : " << x << std::endl;
  // change the element on container
  std::fill(x.begin(), x.end(), '0'); // set all element to 0
  std::cout << "after perform std::fill : " << x << std::endl;
}
// using back_inserter to avoid access invalid element
void safeInsert(std::string &x) {
  auto it = std::back_inserter(x); // equals to call push back
  std::cout << "before call back_inserter : " << x << std::endl;
  *it = 'j';
  std::cout << "after call back inserter : " << x << std::endl;
}
void safeCopy(size_t n) {
  int x[] = {0, 1, 2, 3, 4, 5, 6};
  int temp[sizeof(x) / sizeof(*x)];
  std::copy(std::begin(x), std::end(x), temp);
  // using std::replace
  std::replace(std::begin(x), std::end(x), 0, 12); // replace every 0 to 42
}
void elimDups(std::vector<std::string> &x) {
  // sort word alphabetically
  std::sort(x.begin(), x.end());
  // unique reorders the input range so that each word appears once
  // remove consecutive duplicate value
  std::cout << "After sort the element : [ ";
  for (auto out : x)
    std::cout << out << " | ";
  std::cout << "]\n";
  std::cout << "using std::unique : ";
  // size is unchanged
  auto end_unique =
      std::unique(x.begin(), x.end()); // point to the last non unique element
  std::cout << *end_unique << std::endl;
  std::cout << "After call std::unique : [ ";
  for (auto out : x)
    std::cout << out << " | ";
  std::cout << "]\n";
  x.erase(end_unique, x.end()); // remove non unique element
  std::cout << "after call erase : ";
  for (auto out : x)
    std::cout << out << " | ";
  std::cout << "]\n";
}
// passing function to arguments
bool predicateCon(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}
void testPredicate(std::vector<std::string> x) {
  std::cout << "using sort : ";
  std::sort(x.begin(), x.end());
  for (auto i : x)
    std::cout << i << " | ";
  std::cout << std::endl;
  std::cout << "overload sort : ";
  std::sort(x.begin(), x.end(), predicateCon); // no arguments
  for (auto i : x)
    std::cout << i << " | ";
  std::cout << "]" << std::endl;
}
// lamda : callable unit of code .
void useLambda() {
  auto f = [] { return 42; };
  std::cout << " using lamda : " << f() << std::endl;
}
void lamdaWithArgs() {
  auto shorter = [](const std::string &a, const std::string &b) {
    return a.size() < b.size();
  };
  std::vector<std::string> auth_name = {"jack", "miller", "doss", "fos",
                                        "joe",  "joel",   "doss"};
  std::cout << "original value : [ ";
  for (auto i : auth_name)
    std::cout << i << " | ";
  // elimnate duplicate
  auto nonUniq = std::unique(auth_name.begin(), auth_name.end());
  auth_name.erase(nonUniq, auth_name.end());
  std::stable_sort(auth_name.begin(), auth_name.end(), shorter);
  std::cout << "\nsort : [ ";
  for (auto i : auth_name)
    std::cout << i << " | ";
  std::cout << "]" << std::endl;
  // direct way
  std::stable_sort(auth_name.begin(), auth_name.end(),
                   [](const std::string &a, const std::string &y) {
                     return a.size() < y.size();
                   });
  std::cout << "passing using direct way : [ ";
  for (auto i : auth_name)
    std::cout << i << " | ";
  std::cout << "] " << std::endl;
}
// using capture list in lambda expression
void useCaptureList(const std::vector<std::string> &x,
                    std::string::size_type sz) {
  //[capture list]... only variable in the capture list can appear in the func
  // body
  auto shorter = [sz](const std::string &a) { return a.size() >= sz; };
  auto wc = std::find_if(x.begin(), x.end(), shorter);
  std::cout << "find word which is greater than : " << sz << std::endl;
  std::cout << "find it first : " << *wc << std::endl;
  std::cout << "find it the second : " << *wc << std::endl;
  // the for each algorithm
  // print every word which satisfy the condition wc , [++wc ... x.end()]
  std::for_each(wc, x.end(),
                [](const std::string &s) { std::cout << s << " "; });
}
void capByVal() {
  size_t v1 = 42; // local variable
  // copies v1 into the callable object named f
  auto f = [v1] { return v1; };
  v1 = 0;       // no effect on the corresponding value inside the lambda
  auto j = f(); // j is 42; f store a copy of v1 when created it
}
void capByRef() {
  size_t v1 = 42;
  // the object f2  contain reference to v1
  auto f2 = [&v1] { return v1; };
  // f2= 42
  // change it
  v1 = 0;
  auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
}
// we can't copy reference object
// eg. stream must pass by reference in lamda expression
void capByRef(std::vector<std::string> &word, std::string::size_type s,
              std::ostream &os = std::cout, char c = ' ') {
  std::for_each(word.begin(), word.end(),
                [&os, c](const std::string &s) { os << s << c; });
}
// implicit reference
void implicitCapture(std::vector<std::string> &word,
                     std::vector<std::string>::size_type sz, std::ostream &os,
                     char c = ' ') {
  // os implicitly captured by reference; c explicitly captured by value
  std::for_each(word.begin(), word.end(),
                [&, c](const std::string &s) { os << s << c; });
}
// mutable lambda
void changeValueLambda() {
  size_t v1 = 42;                           // local variable
  auto f = [v1]() mutable { return ++v1; }; // dont omit the parameter list
  v1 = 0;
  auto j = f(); // j = 43
}
// specify the return type in lambda expression
// case : transform every element in a container
void trailingRet(std::vector<int> &x) {
  std::transform(x.begin(), x.end(), x.begin(), [](int i) -> int {
    if (i < 0)
      return -i;
    else
      return i;
  });
}
void bindArg();
