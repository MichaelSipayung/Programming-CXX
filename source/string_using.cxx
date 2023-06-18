#include "string_using.hpp"
void intialize_str() {
  std::string s3 = "hiya";
  std::string s4(10, 'c');
  std::cout << "initialize with literal string : " << s3 << std::endl;
  std::cout << "initilalize with total length and copy : " << s4 << std::endl;
  /*direct initialization*/
  std::string s5("hiya");
  std::string s6(10, 's');
  /*copy initialization*/
  std::string s7 = "hiya";
}
void read_write() {
  std::string s;
  std::cout << "read the literal string : ";
  std::cin >> s;
  std::cout << "what i already read : " << s << std::endl;
}
void read_write_multiline() {
  std::cout << "read multiline literal string:  ";
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << "what i was read : " << s1 << " - " << s2 << std::endl;
}
void read_numbers_str() {
  std::string str;
  std::cout << "read unknown number of string : ";
  while (std::cin >> str) {
    std::cout << str << " ";
  }
}
void read_entire_line() {
  std::string line;
  std::cout << "read without ignore space : ";
  while (std::getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
}
void str_operation() {
  std::string test_empty;
  if (test_empty.empty()) {
    std::cout << "string is empty" << std::endl;
    test_empty = "fill it";
  }
  std::cout << "after assignment : " << test_empty << std::endl;
  std::string name = "michael sipayung";
  if (name.size() >= 10) {
    std::cout << "name is too long .. " << std::endl;
    name = "michael";
  }
  std::cout << "to long, and trim : " << name << std::endl;
}
void str_compare() {
  std::string str = "Hello";
  std::string phrase = "Hello World";
  std::string slang = "Hiya";
  std::cout << "first string less than second string : " << (str < phrase)
            << std::endl;
  std::cout << "the second string less than the third string : "
            << (phrase < slang) << std::endl;
}
void concate_str() {
  std::string s1 = "michael";
  std::string concate_s1 = s1 + "sipayung";
  std::cout << "after concatenation the string : " << concate_s1 << std::endl;
}
void rangeBasedFor() {
  std::string s("Hello World!!!");
  decltype(s.size()) punctCnt = 0;
  for (auto c : s) {
    if (ispunct(c)) {
      ++punctCnt;
    }
  }
  std::cout << punctCnt << " punctuation characters in " << s << std::endl;
}
void transBasedFor() {
  std::string s("Hello world");
  std::cout << "before transform the string : " << s << std::endl;
  for (auto &c : s) {
    c = toupper(c);
  }
  std::cout << "after transform the character : " << s << std::endl;
}
void traverseSubscript(const std::string x) {
  if (x.empty()) {
    std::cout << "x is empty string" << std::endl;
  }
  for (size_t i = 0; i < x.size(); ++i) {
    std::cout << " - " << x[i] << " ";
  }
  std::cout << std::endl;
}
void transformSubscript(std::string &s) {
  for (size_t i = 0; i < s.size() && (!isspace(s[i])); ++i) {
    s[i] = toupper(s[i]);
  }
  std::cout << "transform using subscript operator" << std::endl;
  std::cout << "result : " << s << std::endl;
}
void tranformRandom(const std::string hex) {
  std::cout
      << "Enter a series of numbers betweenn 0 and 15, separated by spaces"
      << std::endl;
  std::string result;
  std::string::size_type n;
  while (std::cin >> n) {
    if (n < hex.size()) {
      result += hex[n];
    }
  }
  std::cout << "hexadecimal transform : " << result << std::endl;
}
