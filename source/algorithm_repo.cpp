#include "algorithm_repo.h"
using namespace algorithm;

void algorithm::test_list_implement()
{
  auto auth = make_shared<list_data<string>>();
  auth->item = "Jack";
  auth->next = make_shared<list_data<string>>();
  auth->next->item = "Donald";
  auth->next->next = make_shared<list_data<string>>();
  auth->next->next->item = "Miller";
  //searching test
  if (const auto result = search_list(string("Donald s"), auth))
    cout << "found! " << result->item;
  else
    cout << "not found";
  cout << endl;
  //show all data test
  show_list(auth);
  //insertion test
  insert_list(string("Knuth"), auth);
  cout << endl;
  //test insertion
  show_list(auth);
  //test predecessor_list
  auto pred=predecessor_list(auth->next->next, auth);
  if (pred)
    cout << "\npred value : "<< pred->item;
  else
    cout << "no pred...";
  //deletion on a list
  auto temps = auth->next->next;
  delete_list(temps , auth);
  cout << "result after deleted : ";
	show_list(auth);
}
