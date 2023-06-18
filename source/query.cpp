#include "query.h"
#include "queryres.h"
using namespace Query;
using std::getline;
QueryResult TextQuery::query(const string &sought) const {
  // return a pointer to this set if we dont find sought
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  // use find and not subsc to avoid adding word to wm
  auto loc = wm.find(sought);
  if (loc == wm.end())
    return QueryResult(sought, nodata, file); // not found
  else
    return QueryResult(sought, loc->second, file); // ok found
}
TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
  string text;
  while (getline(is, text)) // for each line in the file
  {
    file->push_back(text);    // remember this line of text
    int n = file->size() - 1; // the current line number , first ln, sec ln ...
    std::istringstream line(text); // separate the line into words
    std::string word;
    while (line >> word) // for each word in that line
    {
      // if word isn't already in wm, subsc add a new entry
      auto &lines = wm[word]; // lines is shar ptr, note lines is reference
      if (!lines)             // that pointer is null the first time we see word
        lines.reset(new set<line_no>); // allocate a new set
      lines->insert(n);                // insert the line num
    }
  }
}

// return queryresult
// define print here
