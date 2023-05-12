#ifndef OVERLOAD_OP_H
#define OVERLOAD_OP_H
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::initializer_list;
using std::vector;
class Sales_Data_Ov{
friend ostream &operator<<(ostream &, const Sales_Data_Ov&);
friend istream &operator>>(istream &, Sales_Data_Ov&);
friend Sales_Data_Ov operator+(const Sales_Data_Ov&, const Sales_Data_Ov&);
friend bool operator==(const Sales_Data_Ov&, const Sales_Data_Ov&);
friend bool operator!=(const Sales_Data_Ov&, const Sales_Data_Ov&);
friend bool operator<(const Sales_Data_Ov&, const Sales_Data_Ov&);
friend bool operator>(const Sales_Data_Ov&, const Sales_Data_Ov&);
    public:
        Sales_Data_Ov()=default;
        Sales_Data_Ov(const vector<string>& entry):lstIsbn{entry}{}
        Sales_Data_Ov(const string &is, const double &pr, const double &rv)
            :isbn{is}, revenue{rv}, price{pr}{}
        Sales_Data_Ov(const Sales_Data_Ov &rh)noexcept
            :isbn{rh.isbn}, revenue{rh.revenue},price{rh.price}{}
        Sales_Data_Ov &operator+=(const Sales_Data_Ov&);
        Sales_Data_Ov &operator=(initializer_list<string>);
        void currIsbn();
    private:
        double avg_price()const;
        string isbn;
        double price;
        double revenue;
        vector<string> lstIsbn;
}; 
ostream &operator<<(ostream &, const Sales_Data_Ov&);
istream &operator>>(istream &, Sales_Data_Ov&);
Sales_Data_Ov operator+(const Sales_Data_Ov&, const Sales_Data_Ov&);
inline 
bool operator==(const Sales_Data_Ov& lh, const Sales_Data_Ov& rh)
{
    return lh.isbn==rh.isbn 
            && lh.revenue==rh.revenue 
            && lh.price==rh.price;
}
inline 
bool operator!=(const Sales_Data_Ov& lh, const Sales_Data_Ov& rh)
{
    return !(lh==rh);
}
inline
bool operator<(const Sales_Data_Ov& lh, const Sales_Data_Ov& rh)
{
    return lh.price<rh.price;
}
inline
bool operator>(const Sales_Data_Ov &lh, const Sales_Data_Ov &rh)
{
    return !(lh<rh);
}
inline 
Sales_Data_Ov &Sales_Data_Ov::operator=(initializer_list<string> item)
{
    lstIsbn = item;
    return *this;
}
inline 
void Sales_Data_Ov::currIsbn()
{
    auto begin = lstIsbn.begin();
    auto end = lstIsbn.end();
    while (begin!=end)
    {
        cout<<*begin;
        ++begin;
    }
}
#endif