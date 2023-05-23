#include "templ.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <string>
void Test_Template::compare_test()const
{
    cout<<"test int compare : " <<compare(x,3*x)<<endl;
    auto db =12.0;
    cout<<"test double compare : "<<compare(y,db)<<endl;
    string str = "hello world";
    cout<<"test st compare : "<< compare(z,str)<<endl;
}
void Test_Template::compare_str()const
{
    cout<<"using nontype template param : " << compare_s("hi","mom")<<endl;
}