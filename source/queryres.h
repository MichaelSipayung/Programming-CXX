#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
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
class QueryResult{
friend ostream&prints(ostream&,const QueryResult&);
    public:
        typedef std::string::size_type line_no;
        QueryResult(string s, shared_ptr<set<line_no>>p,shared_ptr<vector<string>>f ):
            sought(s),lines(p),file(f){} 
    private:
        string sought; //word this query represent
        shared_ptr<set<line_no>> lines; //lines it's on
        shared_ptr<vector<string>>file; //input file
};
ostream &prints(ostream &os, const QueryResult &qr)
{
    os<<qr.sought <<" occurs "<< qr.lines->size()<<" ";
    return os;
}
}
#endif