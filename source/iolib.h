#ifndef IO_LIB_H
#define IO_LIB_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
#include <fstream>
using std::ifstream; // input file
using std::ofstream; // output file
#include <sstream>
using std::istringstream; // read a string
using std::ostringstream; // write a string
#include <vector>
namespace Refac {
struct PersonalInfo {
  string name;
  vector<string> phones;
};
void handl_Io() {
  string word;
  while (cin >> word)
    cout << "dealing with io " << endl;
}
void file_stream() {
  ifstream in("temp1.txt");
  in.close();
  ofstream out("temp2.txt", ofstream::app);
  out.close();
}
void test_istringstream() {
  string line, word;
  vector<PersonalInfo> people;
  std::cout << "using sstream :";
  while (getline(cin, line)) {
    PersonalInfo info;
    istringstream record(line);    // bind record to the line
    record >> info.name;           // record the name
    while (record >> word) {       // read the phone number
      info.phones.push_back(word); // and store them
    }
    people.push_back(info); // append this record to people
  }
}
} // namespace Refac
#endif
