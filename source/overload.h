#ifndef OVERLOAD_OP_H
#define OVERLOAD_OP_H
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
class Sales_Data_Ov{
friend ostream &operator<<(ostream &, const Sales_Data_Ov&);
friend istream &operator>>(istream &, Sales_Data_Ov&);
    public:
        Sales_Data_Ov()=default;
        Sales_Data_Ov(const string &is, const double &pr, const double &rv)
            :isbn{is}, revenue{rv}, price{pr}{}
        Sales_Data_Ov(const Sales_Data_Ov &rh)noexcept
            :isbn{rh.isbn}, revenue{rh.revenue},price{rh.price}{}
    private:
        double avg_price()const;
        string isbn;
        double price;
        double revenue;
}; 
ostream &operator<<(ostream &, const Sales_Data_Ov&);
istream &operator>>(istream &, Sales_Data_Ov&);
#endif