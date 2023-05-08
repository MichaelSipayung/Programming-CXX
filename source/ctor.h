#ifndef COPY_CTOR_H
#define COPY_CTOR_H
#include <iostream>
#include <vector>
namespace Adv
{
class Sales_data{
    public:
        Sales_data(); //default ctor
        Sales_data(const Sales_data&); //copy ctor
        ~Sales_data(){};
    private:
        std::string bookNo;
        int unit_sold=0;
        double revenue =0.0;
};
class Foo{
    public:
        Foo();
        Foo(const Foo&); //copy ctor
        Foo& operator=(const Foo&); //ass op
        ~Foo(){}; //destructor
    private:
        string isbn;
        int x=0;
        double y=0.0;
};
}
#endif