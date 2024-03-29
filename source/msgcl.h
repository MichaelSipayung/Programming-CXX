#ifndef MESSAGE_CL_H
#define MESSAGE_CL_H
#include <iostream>
#include <memory>
#include <set>
using std::cout;
using std::endl;
using std::set;
using std::string;
namespace Adv {
class Folder;
class Message {
  friend class Folder;

public:
  explicit Message(const string &str = " ") : contents{str} {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();
  void save(Folder &);
  void remove(Folder &);

private:
  string contents;
  set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};
class Folder {
public:
  Folder(const Folder &);

private:
  string fld;
};
} // namespace Adv
#endif