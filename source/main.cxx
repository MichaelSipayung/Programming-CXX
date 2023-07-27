#include "main.h"
int main() {
  //builMap test
  ifstream filename;
  filename.open("rule.txt");
  auto result  = Refactor::buildMap(filename);
  for(const auto &item:result)
    cout<<"key : " <<item.first<<", value : " << item.second<<endl;
  filename.close();
  return 0;
}