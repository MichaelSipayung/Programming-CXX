#include "msgcl.h"
using namespace Adv;
void Message::save(Folder &f)
{
    cout<<"function folder defenition"<<endl;
}
void Message::add_to_Folders(const Message&msg)
{
    cout<<"function add to folder"<<endl;
}
void Message::remove(Folder& f)
{
    cout<<"function that remove folder"<<endl;
}
Folder::Folder(const Folder &f):fld{string()}{}