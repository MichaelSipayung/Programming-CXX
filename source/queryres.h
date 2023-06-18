#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <cstring>
#include <fstream> //fstream
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <sstream> //istringstr
#include <utility>
#include <vector>
using namespace std;
namespace Query {
class QueryResult {
  friend ostream &prints(ostream &, const QueryResult &);

public:
  typedef std::string::size_type line_no;
  QueryResult(string s, shared_ptr<set<line_no>> p,
              shared_ptr<vector<string>> f)
      : sought(s), lines(p), file(f) {}

private:
  string sought;                   // word this query represent
  shared_ptr<set<line_no>> lines;  // lines it's on
  shared_ptr<vector<string>> file; // input file
};
ostream &prints(ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " ";
  return os;
}
} // namespace Query
#endif