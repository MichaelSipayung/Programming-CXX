#ifndef SALES_H
#define SALES_H
#include <iostream>
struct Sales_data
{
    //constructor added
    Sales_data()=default;   //inline by default, optimize your code
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s,unsigned n,double p):
        bookNo(s),unit_sold(n),revenue(p*n){} //no further work, empty body
    Sales_data(std::istream&);

    //operation on sales_data objects
    std::string isbn()const{return bookNo;} //implicitly inline
    Sales_data &combine(const Sales_data&); //noninline function
    double avg_price()const;
    unsigned min()const{return minSold;}
    //data member
    unsigned minSold=0;
    std::string bookNo;
    unsigned unit_sold=0;
    double revenue=0.0;
};
//nonmember sales_data interface
Sales_data add(const Sales_data&,const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream&,Sales_data&);
#endif