#include "overload.h"
using std::ostream;
ostream &operator<<(ostream &os, const Sales_Data_Ov& item)
{
    os<<item.isbn<<" "<<item.price <<" " << item.revenue <<" "<< item.avg_price();
    return os;
}
istream &operator>>(istream &is, Sales_Data_Ov& item)
{
    double price;
    is>>item.isbn>>price;
    if(is)
        item.revenue=price*5;
    else
        Sales_Data_Ov(); //fail, return to default state
    return is;
}

double Sales_Data_Ov::avg_price()const
{
    return revenue/price;
}
