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
        Sales_Data_Ov(const vector<string> &list_isbn, const std::size_t &index);
        Sales_Data_Ov(const vector<string>& entry):lstIsbn{entry}{}
        Sales_Data_Ov(const string &is, const double &pr, const double &rv)
            :isbn{is}, revenue{rv}, price{pr}{}
        Sales_Data_Ov(const Sales_Data_Ov &rh)noexcept
            :isbn{rh.isbn}, revenue{rh.revenue},price{rh.price}{}
        Sales_Data_Ov &operator+=(const Sales_Data_Ov&);
        Sales_Data_Ov &operator=(initializer_list<string>);
        //string &operator[](std::size_t n)
        //    {return lstIsbn[n];}
        //const string &operator[](std::size_t n)const
        //    {return lstIsbn[n];}
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
inline
Sales_Data_Ov::Sales_Data_Ov(const vector<string> &list_isbn, const std::size_t &index)
    :lstIsbn{list_isbn}, isbn{list_isbn[index]}{}
class Mat{
friend void show_data(const Mat&);
    public:
        Mat()=default;
        Mat(const vector<double> temp): data{temp}{}
        Mat(const Mat& rhs): data{rhs.data}{}
        Mat &operator=(const Mat&);
        Mat &operator+(const Mat&);
    private:
        bool chk_size(const Mat&);
        vector<double> data;
};
inline
bool Mat::chk_size(const Mat& rhs)
{
    if(data.size() != rhs.data.size())
        return false;
    return true;
}
inline
Mat &Mat::operator=(const Mat& rhs)
{
    if(!chk_size(rhs))
        return *this;
    else
        this->data=rhs.data;
    return *this;
}
inline
Mat &Mat::operator+(const Mat& rhs)
{
    auto temp = this;
    if(!chk_size(rhs))
        return *this;
    for(int i=0;i<data.size();++i)
        data[i]+=rhs.data[i];
    return *this;
}
void show_data(const Mat &lhs);
class IncDec_Operator{
    public:
        IncDec_Operator()=default;
        IncDec_Operator(const vector<int>&);
        IncDec_Operator(const IncDec_Operator &rh);
        IncDec_Operator &operator++(); //prefix op
        IncDec_Operator &operator--();
        IncDec_Operator operator++(int); //postfix, an extra arg supply to distiguishes
        IncDec_Operator operator--(int);
        void show_curr();
    private:
        vector<int> data;
        size_t pos;
};
inline 
IncDec_Operator::IncDec_Operator(const IncDec_Operator &rh)
{
    data = rh.data;
    pos= rh.pos;
}
inline
IncDec_Operator &IncDec_Operator::operator++()
{
    if(pos<this->data.size())
        ++pos;
    return *this;
}
inline
void IncDec_Operator::show_curr()
{
    std::cout<< data[pos];
}
inline 
IncDec_Operator &IncDec_Operator::operator--()
{
    if(pos<1)
        throw std::out_of_range("index out of range");
    else
        --pos;
    return *this;
}
inline
IncDec_Operator IncDec_Operator::operator++(int)
{
    IncDec_Operator temp = *this;
    ++*this; //advance the el; prefix chk the incr
    return temp; //return the saved state
}
inline
IncDec_Operator IncDec_Operator::operator--(int)
{
    //no check needed here, the call to prefix dec will do check
    IncDec_Operator temp =*this; //save the curr state
    --*this; //move backward one el; prefix --check the decrement
    return temp; 
}
inline 
IncDec_Operator::IncDec_Operator(const vector<int> &tmp)
    :data{tmp}, pos{0}{}
#endif