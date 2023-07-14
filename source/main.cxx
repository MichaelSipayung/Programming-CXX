#include "main.h"

int main(int argc, char **argv) {
  // test accumulate on string
  vector<double> curr_num = {0.4, 0.5, 0.6, 0.611};
  vector<double> dest(4, 0);
  Refac::copyAlg(curr_num, dest);
  cout << "after calling copy algorithm : " << *(dest.begin()) << endl;
  Refac::replaceAlg(curr_num, 0.4, 0.9);
  cout << "after calling replace algorithm : " << *(curr_num.begin()) << endl;
  vector<double> ageFam = {12.5, 13.2, 14.3, 14.3, 15.8,
                           15.6, 16.7, 16.8, 16.8};
  Refac::elimDupsAlg(ageFam);
  cout << "after eliminate duplicate : ";
  for (auto &item : ageFam)
    cout << item << " | ";
  cout << endl;
  vector<string> authList = {"the",  "quick", "red",  "fox", "jumps",
                             "over", "the",   "slow", "red", "turtle"};
  Refac::sortElPredicate(authList);
  for (auto &item : authList)
    cout << item << " | ";
  cout << endl;
  // test for stable sort algorithm
  cout << "stable sort using lamda expression on third arguments" << endl;
  vector<string> authList_s = {"is",    "the",  "quick", "red",    "foxs",
                               "jumps", "over", "fox",   "turtle", "slow",
                               "the",   "over", "red"};
  Refac::biggesAlg(authList_s, 3);
  Refac::capByRefLambda(cout);

  return 0;
}
