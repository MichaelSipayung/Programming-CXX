#include "sales.h"
double Sales_data::avg_price()const{
    if (unit_sold)      //point to const object, implicit call to this
    {
        return revenue/unit_sold;
    }
    else{
        return 0;
    }
}
Sales_data& Sales_data::combine(const Sales_data&rhs){
    unit_sold+=rhs.unit_sold; //add the members of rhs into
    revenue+=rhs.revenue;     //the members of "this" object
    return *this; //return the object on which the function was called
}
std::istream &read(std::istream&is,Sales_data &item){
    double price=0;
    is>>item.bookNo>>item.unit_sold>>price;
    item.revenue=price*item.unit_sold;
    return is;
}
std::ostream&print(std::ostream &os,const Sales_data&item){
    os<<item.isbn()<<" "<<item.unit_sold<<" "<<item.revenue<<" "
        <<" "<<item.avg_price();
    return os;
}
Sales_data add(const Sales_data&lhs,const Sales_data&rhs){
    Sales_data sum =lhs; //copy data members from lhs into sum
    sum.combine(rhs);   //add data members from rhs into sum
    return sum;
}
Sales_data::Sales_data(std::istream &is){
    read(is,*this); //read will read a transaction from is into this object
}