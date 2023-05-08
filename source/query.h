#ifndef QUERY_PROG_H
#define QUERY_PROG_H
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <fstream> //fstream
#include <sstream> //istringstr
#include <utility>
#include <cstring>
using namespace std;
namespace Query{

class QueryResult; //declaration needed for return type in the query func
class TextQuery{
    public:
        using line_no  = string::size_type;
        TextQuery(ifstream&);
        QueryResult query(const string&)const; 
    private:
        shared_ptr<vector<string>> file; //in file
        //map of each word to the set of lines in which that word appear
        map<string,shared_ptr<set<line_no>>> wm;
};
}
#endif