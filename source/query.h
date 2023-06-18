#ifndef QUERY_PROG_H
#define QUERY_PROG_H
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

class QueryResult; // declaration needed for return type in the query func
class TextQuery {
public:
  using line_no = string::size_type;
  TextQuery(ifstream &);
  QueryResult query(const string &) const;

private:
  shared_ptr<vector<string>> file; // in file
  // map of each word to the set of lines in which that word appear
  map<string, shared_ptr<set<line_no>>> wm;
};
} // namespace Query
#endif