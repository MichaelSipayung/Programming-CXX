#include "main.h"
using namespace Problem;
int main() {
  // auto result = searchList(&ls,string("miller"));
  linkedList ls;
  ls.item = "Turing"; //head-2
  linkedList rs(string("Knuth"), &ls); //head-1
  linkedList last(string("Jack"), &rs); //head
  //Jack -> knuth -> Turing
  auto *test = &last;
  //looking the predecessor of Knuth : Jack
  auto result = item_head(test,&last);
  if(result)
    cout<<"pred value : "<< result->item<<endl;
  else
    cerr<<"error, no successor"<<endl;
  return 0;
}