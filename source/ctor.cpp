#include "ctor.h"
using namespace Adv;
using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

//equivalent to the copy ctor that would be synthesized for sales_data
Sales_data::Sales_data(const Sales_data &orig):
    bookNo{orig.bookNo},
    unit_sold{orig.unit_sold},
    revenue{orig.revenue}{} //copies orig.rev 
//synthesized copy assignment op
Foo &Foo::operator=(const Foo& rhs)
{
    isbn = rhs.isbn;
    x = rhs.x;
    y= rhs.y;
    return *this; //ret reference to this obj
}
HashPtr::HashPtr(const HashPtr&rhs):ps{new string()}{}
HashPtr &HashPtr::operator=(const HashPtr &rhs)
{
    ps= rhs.ps;
    xPoint=rhs.xPoint;
    return *this;
}
void HashPtr::test_dctor()
{
    HashPtr hashX("Jack");
    std::cout<<"result : "<< hashX.xPoint<<std::endl;
    std::cout<<"point : "<< hashX.ps<<std::endl;
    auto byVal=hashX;
    std::cout<<"result : "<< hashX.xPoint<<std::endl;
    std::cout<<"point : "<< hashX.ps<<std::endl;
}
//cp assignment as default, using synthesized versions
Default_Sales& Default_Sales::operator=(const Default_Sales&)=default;
//safe copy assignment which is involve pointer
//copy x from x! 
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps); //cp the underlying str
    delete ps; //free old mem
    ps = newp; //cp data from rhs into this obj
    i =rhs.i;
    return *this; //ret his obj
}
void HasPtr::test_safeAssig()const
{
    HasPtr testX("Jackie");
    cout<<"pointer : " <<*testX.ps<<" mem : "<<testX.ps<<endl;
    testX=testX; //calling dctor first and free resource
    cout<<"pointer : " <<*testX.ps<<" mem : "<< testX.ps<<endl;
    HasPtr testY;
    testY=testX;
    cout<<"mem : " << testY.ps<<" val : "<< *testY.ps<<endl;
}
//dctor HasPtr_1
//if counter goes to zero, the dctor free the memory to which ps,use point
HasPtr_1::~HasPtr_1()
{
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
}
//cp assignment, if both obj are the same
//the counter will have been incremented before we check
HasPtr_1 &HasPtr_1::operator=(const HasPtr_1& rhs)
{
    ++*rhs.use; //increment the use count of the right hand operand
    if(--*use==0) //then decrement this obj counter
    {
        delete ps; //no other use ? free the obj allocated members
        delete use;
    }
    ps=rhs.ps;  //cp data from rhs into this obj
    i=rhs.i;
    use = rhs.use;
    return *this; //return this obj
}
size_t HasPtr_1::count()const
{
    return *use;
}
