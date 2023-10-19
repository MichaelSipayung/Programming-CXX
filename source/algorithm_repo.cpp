#include "algorithm_repo.h"
using namespace algorithm;
// testing purpose,linked_list implementation simple case : string
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
// testing purpose, binary tree implementation simple case : string
void algorithm::test_binaryTree_implement() {
  binary_tree<string> bin_tr("Manning");
  bin_tr.left->item = "Fimitr";
  bin_tr.right->item = "Merry";
  auto make_aut = make_shared<binary_tree<string>>(bin_tr);

  binary_tree<string> lft_bin("Dimitri");
  lft_bin.left->item = "Dar thy";
  lft_bin.right->item = "Dorthy";
  bin_tr.left->left = make_shared<binary_tree<string>>(lft_bin);

  binary_tree<string> rhs_bin("Orreys");
  rhs_bin.left->item = "Norris";
  rhs_bin.right->item = "Zorro";
  bin_tr.right->right = make_shared<binary_tree<string>>(rhs_bin);

  show_tree(make_aut);
  // testing for all node is pass 1
  cout << "\nusing another style : ";
  auto found_m = search_tree(string("Zorro"), make_aut);
  if (found_m)
    cout << "found";
  else
    cout << "not found";
  // test pass 2
  auto auth = make_shared<binary_tree<string>>();
  auth->item = "Maning";
  // parent is optional node
  auth->left = make_shared<binary_tree<string>>();
  auth->left->item = "Lessie";
  auth->right = make_shared<binary_tree<string>>();
  auth->right->item = "Thomas";
  cout << "\ntraverse all node : ";
  show_tree(auth);
  cout << "\nsearching operation : ";
  const string auth_find = "Maning";
  auto found = search_tree(auth_find, auth);
  if (found)
    cout << "found it";
  else
    cout << "not found";
  // testing for finding minimum element on binary tree
  cout << "\nFinding minimum element : ";
  auto fmin = find_min_tree(make_aut);
  if (fmin)
    cout << fmin->item << endl;
  else
    cout << "not found\n";

  cout << "\nFinding maximum element : ";
  auto fmax = find_max_tree(make_aut);
  if (fmax)
    cout << fmax->item << endl;
  else
    cout << "not found\n";
}
// testing purpose for double linked list
void algorithm::test_double_list_implement() {
  auto dlA = make_shared<double_list<string>>();
  dlA->item = "A";

  auto dlB = make_shared<double_list<string>>();
  dlB->prev = make_shared<double_list<string>>();
  dlB->item = "B";

  dlA->next = dlB;
  dlB->prev = dlA;

  auto dlC = make_shared<double_list<string>>();
  dlC->item = "C";
  dlC->prev = make_shared<double_list<string>>();
  dlB->next = dlC;
  dlC->prev = dlB;

  auto dlD = make_shared<double_list<string>>();
  dlD->item = "D";
  dlD->prev = make_shared<double_list<string>>();
  dlD->prev = dlC;
  dlC->next = dlD;

  cout << "prev B : " << dlB->prev->item << endl;
  cout << "next A : " << dlA->next->item << endl;
  cout << "next B : " << dlB->next->item << endl;
  cout << "prev C : " << dlC->prev->item << endl;
  cout << "next C : " << dlC->next->item << endl;
  cout << "prev D : " << dlD->prev->item << endl;

  cout << "\nshow all : ";
  show_doubly_list(dlA); // show all node
  // testing for searching
  if (auto findIt = search_db_list("A", dlA))
    cout << "\nfound it ..." << findIt->item;
  else
    cout << "\nnot found";
  // push an element on a back position
  const string add("E");
  push_back_db_list(add, dlD->next);
  cout << "\nafter push an item at back position : ";
  show_doubly_list(dlA); // show all node
  // test for push front
  push_front_db_list(string("1"), dlA);
  cout << "\nafter push an item at front position : ";
  show_doubly_list(dlA); // show all node
  push_front_db_list(string("2"), dlA);
  cout << "\nafter push an item at front position : ";
  show_doubly_list(dlA); // show all node
}
// show all node in a doubly linked list
void algorithm::show_doubly_list(
    const shared_ptr<double_list<string>> &db_list) {
  if (db_list) { // do nothing if there is node
    cout << db_list->item << " - ";
    show_doubly_list(db_list->next); // recursive call to next node
  }
}
// searching an item in a double linked list
shared_ptr<double_list<string>>
algorithm::search_db_list(const string &src,
                          const shared_ptr<double_list<string>> &db_list) {
  if (!db_list)
    return nullptr;
  if (db_list->item == src)
    return db_list;
  return search_db_list(src, db_list->next);
}
// push an item to double linked list, push back
void algorithm::push_back_db_list(const string &item,
                                  shared_ptr<double_list<string>> &db_list) {
  if (!db_list) { // the last pointer is pointer->next that point to nothing
    db_list = make_shared<double_list<string>>(); // since we point to null_ptr
    db_list->item = item;                         // assign the given value
  }
}
// push an item to double linked list, push front
void algorithm::push_front_db_list(const string &item,
                                  shared_ptr<double_list<string>> &db_list) {
  if (!db_list) { // there is no element or null pointer
    db_list = make_shared<double_list<string>>(); // allocate a new place
    db_list->item = item;
  }
  // safely add to the front through check the previous node, then move current
  // item
  else if (!db_list->prev) { // there is at least one node, check previous,
                             // assume null
    // db_list->prev=make_shared<double_list<string>>(); //ask a new place
    // db_list->prev->item=item;
    auto temp = make_shared<double_list<string>>();
    temp->item = item;    // store item in the safe place temporary object
    temp->next = db_list; // move next pointer to current node
    db_list = temp;       // just place all thing in db_list
  }
}
// test case for insertion on a binary tree
void algorithm::test_insertion_tree() {
  auto auth = make_shared<binary_tree<string>>();
  auth->item = "Manning";
  auth->parent = auth;
  // parent is optional node
  auth->left = make_shared<binary_tree<string>>();
  auth->left->item = "Lessie";
  auth->right = make_shared<binary_tree<string>>();
  auth->right->item = "Thomas";
  insert_node_tree(string("Lilith"), auth->parent, auth);
  cout << "\ntraverse all node : ";
  show_tree(auth);
  test_pred_succ(auth);
}
void algorithm::delete_node_test() {
  auto data = make_shared<binary_tree<int>>();
  data->item = 6;

  data->left = make_shared<binary_tree<int>>();
  data->left->item = 2;

  data->right = make_shared<binary_tree<int>>();
  data->right->item = 8;

  data->left->left = make_shared<binary_tree<int>>();
  data->left->left->item = 1;

  data->left->right = make_shared<binary_tree<int>>();
  data->left->right->item = 4;

  data->left->right->left = make_shared<binary_tree<int>>();
  data->left->right->left->item = 3;
  cout << "\nlook the data after constructed : ";
  show_tree(data);

  cout << "delete test\n";
  auto tempObj = data;
  int n_data = 0;
  cout << "input number to be deleted : ";
  cin >> n_data;
  delete_node_tree(n_data, tempObj);
  cout << "del what ? " << n_data << ", result : ";
  show_tree(tempObj);
}
