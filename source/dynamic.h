// dynamic memory and smart pointer
#pragma once
#include <iostream>
using std::string;
#include <map>
using std::map;
#include <memory>
using std::shared_ptr;
#include <set>
using std::set;
#include <string>
#include <utility>
#include <vector>
using std::vector;
namespace refactor {
// modification of binary search tree using smart pointer
struct my_tree {
  my_tree() : left(nullptr), right(nullptr) {}
  std::string isbn;
  std::shared_ptr<my_tree> left;
  std::shared_ptr<my_tree> right;
};
// modification of linked list using smart pointer
template <typename Object> struct my_linked_list {
  Object item;
  std::shared_ptr<my_linked_list> next;
  my_linked_list() : item(), next(nullptr) {}
  my_linked_list(const Object &val, std::shared_ptr<my_linked_list> &next_it)
      : item(val), next(next_it) {}
};
// str_blob class
class str_blob {
public:
  typedef std::vector<std::string>::size_type size_type;
  str_blob();
  str_blob(std::initializer_list<std::string> il);
  size_type size() const { return data_->size(); }
  bool empty() const { return data_->empty(); }
  // add and remove element
  void push_back(const std::string &t) const { data_->push_back(t); }
  void pop_back() const;
  // element access
  [[nodiscard]] std::string &front() const;
  [[nodiscard]] std::string &back() const;

private:
  std::shared_ptr<std::vector<std::string>> data_;
  // throw msg if data[i] is not valid
  void check(size_type i, const std::string &msg) const;
};
// pointer initialization
void init_pointer();
// copy on a smart_pointer
void copy_pointer();
// test smart pointer on binary search tree
void tree_application();
// test smart pointer on linked_list
void linked_application();
// traverse all element on binary tree
template <typename Object>
void tree_traverse(const std::shared_ptr<my_tree> &tr) {
  if (tr) {
    tree_traverse<Object>(tr->left); // left first
    std::cout << tr->isbn << " ";
    tree_traverse<Object>(tr->right); // go right
  }
}
// reference count, track how many object pointed to the current pointer
void reference_count();
// automatically free the associated memory
std::shared_ptr<int> factory();
// test automatically free memory
void use_factory();
// searching on a using smart pointer
std::shared_ptr<my_tree> search_my_tree(std::shared_ptr<my_tree> tr,
                                        const std::string &val);
// managing memory directly
void initialize_direct();
// dynamically allocated const objects
void initialize_const_direct();
// memory exhaustion
void memory_exhaust();
// freeing dynamic memory
void freeing_direct();
// fixing bug on built in pointer
int *factory_md(const int &);
void use_factory_md();
// resetting a value on a pointer
void reset_pointer_val();
// using shared_ptr with new
void smart_ptr_new();
// reset operation on smart pointer
void reset_smart_ptr();
// smart pointer and exceptions
void handle_exception();
void bad_ptr();
// unique ptr : own the object to which it points, only one unique_ptr
// at a time can point to a given object
void init_unique_ptr();
// copy and assign unique_ptr that is about to be destroy
std::unique_ptr<int> clone(int);
// weak_ptr is smart pointer that does not control the lifetime of the
// object to which it points. Binding a weak_ptr to a shared_ptr does not change
// the reference count of that shared ptr
void init_weak_ptr();
// safely access weak_ptr
void access_weak_ptr();

//design text_query program
class query_result; //declaration needed for return type in the query function
class text_query
{
public:
  using  line_no = std::vector<std::string>::size_type;
  explicit text_query(std::ifstream&);
  query_result query(const std::string&)const;
private:
  std::shared_ptr<std::vector<std::string>> file_; //input file
	//map of each word to the lines in which that word appears
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm_;
};
class query_result{
  friend std::ostream &print(std::ostream&, const query_result&);
public:
  using  line_no = std::vector<std::string>::size_type;
  query_result(string s, const shared_ptr<set<line_no>>& p, shared_ptr<vector<string>> f):
    sought_(std::move(s)), lines_(p), file_(std::move(f)){}
private:
  string sought_; //word this query represents
  shared_ptr<set<line_no>> lines_; //line it's on
  shared_ptr<vector<string>>file_; //input file
};
} // namespace refactor
