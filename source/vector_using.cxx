#include "vector_using.hpp"
#define NUMBER_EL 11
void introToVector(void) {
  std::vector<int> holdInt;
  std::vector<std::string> holdString;
  std::vector<std::string> copyVector(holdString);
  /*initialize the element*/
  std::vector<std::string> articles = {"a", "an", "the"};
  std::vector<int> ivec(10, 0);
  ivec[9] = 9;
  std::cout << "start element : " << ivec[0] << " .... " << ivec[9]
            << std::endl;
}
void addElement(void) {
  std::vector<int> v2;
  for (int i = 0; i != 100; ++i) {
    v2.push_back(i);
  }
  std::cout << "what i added : ";
  for (size_t i = 0; i < 100; i++) {
    std::cout << v2[i] << " ";
  }
  std::cout << std::endl;
}
void modifyElement(void) {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  if (!v.empty()) {
    for (auto &i : v) {
      i *= i;
    }
  } else {
    std::cout << "sorry has no element to multiply" << std::endl;
  }
  std::cout << "modify the current value in a vetor : ";
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
void modifyBySubs(void) {
  std::vector<unsigned> scores(11, 0);
  unsigned grade;
  std::cout << "input grade, seperate by commas : ";
  while (std::cin >> grade) {
    if (grade <= 100) {
      ++scores[grade / 10];
    }
  }
  std::cout << "the output should be : ";
  auto begin = scores.begin();
  while (begin != scores.end()) {
    std::cout << *begin << " ";
    ++begin;
  }
  std::cout << std::endl;
}
void byIterator(void) {
  std::vector<unsigned> nat{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<unsigned>::iterator begin, end;
  begin = nat.begin(), end = nat.end();
  std::cout << "traverse the element by iterator type : ";
  while (begin != end) {
    std::cout << *begin << " ";
    ++begin;
  }
  std::cout << std::endl;
  /*application in string*/
  std::string name("michael sipayunG");
  std::string::iterator str_begin, str_end;
  str_begin = name.begin(), str_end = name.end();
  while (str_begin != str_end) {
    if (isupper(*str_begin)) {
      *str_begin = tolower(*str_begin);
    }
    ++str_begin;
  }
  std::cout << "after traverse the element using string : " << name
            << std::endl;
  /*applying in const vector*/
  const std::vector<int> naturalNum = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int>::const_iterator begin_con, end_con;
  begin_con = naturalNum.cbegin(), end_con = naturalNum.cend();
  std::cout << "accessing the element using const itrator in const vector : ";
  while (begin_con != end_con) {
    std::cout << *begin_con << " ";
    ++begin_con;
  }
  std::cout << std::endl;
}
void dereferenceMem(void) {
  std::vector<int> clas{1, 2, 3, 4, 5};
  auto begin = clas.begin();
  if ((*begin) < 6) {
    std::cout << "dereference using * operator : " << *begin << std::endl;
  }
  std::vector<std::string> line{"john", "doe", "does", "nothing"};
  for (auto it = line.cbegin(); it != line.end() && !it->empty(); ++it) {
    std::cout << *it << std::endl;
  }
}
void arrayStruc(void) {
  int array[NUMBER_EL];
  int *pointAr[NUMBER_EL]; /*array of NUMBER_EL pointer to int*/
  int withoutDim[] = {1, 2, 3, 4, 5};
  char a2[] = {'n', 'u', 'l'}; /*make extra space for null character*/
  std::cout << "traverse the element using range for : ";
  for (auto i : a2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::string num[] = {"one", "two", "three"};
  std::string *pointBegin = num;
  std::string *pointEnd = num + 2;
  std::cout << "access the data : ";
  while (pointBegin != pointEnd) {
    std::cout << *pointBegin << " ";
    ++pointBegin;
  }
  std::cout << std::endl;
  std::cout << "Access the last element :" << *pointBegin << std::endl;
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *beg = std::begin(ia); /*point to first element*/
  int *end = std::end(ia);
  std::cout << "using begin and end funtion : ";
  while (beg != end) {
    std::cout << *beg;
    ++beg;
  }
  std::cout << std::endl;
  std::cout << "size of ia : " << sizeof(ia) / sizeof(int) << std::endl;
  unsigned i = 0, len = sizeof(ia) / sizeof(int);

  while (i != len) {
    std::cout << ia[i++] << " | ";
  }
  std::cout << std::endl;
}
void advAray(void) {
  int ia[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int last = *(ia + 7);
  std::cout << "result after dereference : " << last << std::endl;
  /*array of character*/
  const char name[] = "michael sipayung";
  std::cout << "safe defined the string : " << strlen(name) << std::endl;
  char destination[sizeof(name) / sizeof(char)];
  strcpy(destination, name);
  std::cout << "after safe copy to the destination : " << destination
            << std::endl;
  std::cout << "compare the string : strcmp(source,destination) : "
            << strcmp(name, destination) << std::endl;
  char safeConca[2 * sizeof(name) / sizeof(char) + 1];
  strcpy(safeConca, name);
  strcat(safeConca, name);
  std::cout << "safe concate : " << safeConca << std::endl;
}
void interfaceOldC(void) {
  int ar[] = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> ivec(std::begin(ar), std::end(ar));
  std::cout << "here we are demonstrate how to interface the c code to c++"
            << std::endl;
  for (auto a : ivec) {
    std::cout << a << " | ";
  }
  std::cout << std::endl;
}
void arrayMultid(void) {
  int ia[3][4]; /*array of size 3; each element is an array of ints of size 4*/
  int initialize[2][2] = {{1, 2}, {3, 4}};
  /*traverse the element*/
  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 2; ++j) {
      std::cout << initialize[i][j] << " | ";
    }
    std::cout << std::endl;
  }
  std::cout << "taverse the multidimensional array .. " << std::endl;
  /*using range for to traverse the element*/
  std::cout << "Access the element : " << std::endl;
  for (auto &row : initialize) {
    for (auto &col : row) {
      std::cout << col << " | ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  /*pointer to multidimension array*/
  int(*p)[4] = ia; /*p points to an array of four int*/
}