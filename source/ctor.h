#ifndef COPY_CTOR_H
#define COPY_CTOR_H
#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::size_t;
using std::endl;
using std::cout;
namespace Adv
{
class Sales_data{
    public:
        Sales_data()=default; //default ctor
        Sales_data(const Sales_data&); //copy ctor
        ~Sales_data(){};
    private:
        std::string bookNo;
        int unit_sold=0;
        double revenue =0.0;
};
class Foo{
    public:
        Foo()=default;
        Foo(const Foo&):isbn{" "},x{0},y{0}{} //copy ctor
        Foo& operator=(const Foo&); //ass op
        ~Foo(){}; //destructor
    private:
        string isbn;
        int x=0;
        double y=0.0;
};
//we use dctor together with cp ctor, cp assignment
class HashPtr{
    public:
        HashPtr()=default;
        HashPtr(const HashPtr&); //cp ctor
        HashPtr &operator=(const HashPtr&); //cp asignment
        HashPtr(const string &s = string()):
            ps{new string(s)}, xPoint{0}{}
        void test_dctor();
        ~HashPtr(){delete ps;}
    private:
        string *ps; //need dctor
        double xPoint =0.0;
};
class Default_Sales{
    public:
        //copy control; use default
        Default_Sales()=default;
        Default_Sales(const Default_Sales&)=default;
        Default_Sales& operator=(const Default_Sales&);
        ~Default_Sales()=default;
    private:
        string isbn;
        double revenue;
};
//prevent copy ctror and assignment
class PrevCopy
{
    public:
        PrevCopy()=default; //use synthesized version
        PrevCopy(const PrevCopy&)=delete; //no cp
        PrevCopy&operator=(const PrevCopy&)=delete; //no assignment
        ~PrevCopy()=default; //use synthesized dest
    private:
        string isbn;
        double xPoint;
};
//classes that act like value
class HasPtr{
    public:
        HasPtr(const string &s=string()):ps{new string(s)}, i{0}{}
        HasPtr(const HasPtr& p): ps{new string(*p.ps)}, i{p.i}{} //each HasPtr has it's own cp
        HasPtr& operator=(const HasPtr&);
        void test_safeAssig()const;
        ~HasPtr(){delete ps;}
    private:
        string *ps;
        int i;
};
//class act like pointer
class HasPtr_1{
    public:
        friend void swap(HasPtr_1&,HasPtr_1&);
        //ctor allocates a new str and a new counter, which it set to 1
        HasPtr_1(const string &s = string()):
            ps{new string(s)}, i{0},use{new size_t(1)}{}
        //cp ctor copies all three data members and increment the counter
        HasPtr_1(const HasPtr_1&p):
            ps{p.ps},i{p.i},use{p.use}{++*use;}
        HasPtr_1& operator=(const HasPtr_1&);
        size_t count()const;
        ~HasPtr_1();
    private:
        string *ps;
        int i;
        size_t *use; //member to keep track of how many obj share *ps
};
inline 
void swap(HasPtr_1 &lhs, HasPtr_1 &rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps); //swap the pointer, not the str data
    swap(lhs.i, rhs.i); //swap the int members
}
}
#endif