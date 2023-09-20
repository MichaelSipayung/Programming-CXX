#include "algorithm_repo.h"
using namespace algorithm;
//testing purpose,linked_list implementation simple case : string
void algorithm::test_list_implement() {
  auto auth = make_shared<list_data<string>>();
  auth->item = "Jack";
  auth->next = make_shared<list_data<string>>();
  auth->next->item = "Donald";
  auth->next->next = make_shared<list_data<string>>();
  auth->next->next->item = "Miller";
  // searching test
  if (const auto result = search_list(string("Donald s"), auth))
    cout << "found! " << result->item;
  else
    cout << "not found";
  cout << endl;
  // show all data test
  show_list(auth);
  // insertion test
  insert_list(string("Knuth"), auth);
  cout << endl;
  // test insertion
  show_list(auth);
  // test predecessor_list
  auto pred = predecessor_list(auth->next->next, auth);
  if (pred)
    cout << "\npred value : " << pred->item;
  else
    cout << "no pred...";
  // deletion on a list
  delete_list(auth->next->next->next->next, auth);
  cout << "result after deleted : ";
  show_list(auth);
}
//testing purpose, binary tree implementation simple case : string
void algorithm::test_binaryTree_implement() {
  binary_tree<string> bin_tr("Maning");
  bin_tr.left->item = "Fimitr";
  bin_tr.right->item = "Merry";
  auto make_aut = make_shared<binary_tree<string>>(bin_tr);

  binary_tree<string> lft_bin("Dimitr");
  lft_bin.left->item = "Darthy";
  lft_bin.right->item = "Dorthy";
  bin_tr.left->left = make_shared<binary_tree<string>>(lft_bin);

  binary_tree<string> rhs_bin("Orreys");
  rhs_bin.left->item = "Norrys";
  rhs_bin.right->item = "Zorrys";
  bin_tr.right->right = make_shared<binary_tree<string>>(rhs_bin);

  show_tree(make_aut);
  //testing for all node is pass 1
  cout << "\nusing another style : ";
  auto found_m = search_tree(string("Zorrys"), make_aut);
  if(found_m)
    cout<<"found";
  else
    cout<<"not found";
  //test pass 2
  auto auth = make_shared<binary_tree<string>>();
  auth->item = "Maning";
  //parent is optional node
  auth->left = make_shared<binary_tree<string>>();
  auth->left->item = "Lessie";
  auth->right = make_shared<binary_tree<string>>();
  auth->right->item = "Thomas";
  cout << "\ntraverse all node : ";
  show_tree(auth);
  cout << "\nsearching operation : ";
  const string auth_find="Maning";
  auto found = search_tree(auth_find,auth);
  if(found)
    cout<<"found it";
  else
    cout<<"not found";
}
//testing purpose for double linked list
void algorithm::test_doubleList_implement(){
  auto dlA = make_shared<double_list<string>>();
  dlA->item="A";

  auto dlB = make_shared<double_list<string>>();
  dlB->prev = make_shared<double_list<string>>();
  dlB->item="B";

  dlA->next=dlB;
  dlB->prev=dlA;

  auto dlC = make_shared<double_list<string>>();
  dlC->item ="C";
  dlC->prev = make_shared<double_list<string>>();
  dlB->next=dlC;
  dlC->prev=dlB; 

  cout<<"prev B : "<<dlB->prev->item<<endl;
  cout<<"next A : "<<dlA->next->item<<endl;
  cout<<"next B : "<<dlB->next->item<<endl;
  cout<<"prev C : "<<dlC->prev->item<<endl;


}
