#include "ctor.h"
using namespace Adv;
using std::string;
//equivalent to the copy ctor that would be synthesized for sales_data
Sales_data::Sales_data(const Sales_data &orig):
    bookNo{orig.bookNo},
    unit_sold{orig.unit_sold},
    revenue{orig.revenue}{} //copies orig.rev 
//synthesized copy assignment op
void test_defCtor()
{
    Sales_data sal_x;
    Sales_data sal_y(sal_x);
}
Foo &Foo::operator=(const Foo& rhs)
{
    isbn = rhs.isbn;
    x = rhs.x;
    y= rhs.y;
    return *this; //ret reference to this obj
}
void test_copyAss()
{
    Foo foo_x;
    Foo foo_y = foo_x;
}