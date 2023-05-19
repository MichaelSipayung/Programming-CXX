#ifndef INHERIT_H
#define INHERIT_H
#include <iostream>
#include <vector>
class Quote{
    public:
        Quote()=default;
        Quote(const std::string &book, double sales_price ):
            bookNo{book},price{sales_price}{}
        std::string isbn()const{return bookNo;}
        //define as virtual, expects its derived classes to define for themselves
        virtual double net_price(std::size_t n)const{
            return n*price;
        }; 
        //each base class should provide a virtual dctor
        virtual ~Quote()=default; //dynamic binding for dctor
    private:
        std::string bookNo;
    //allow derived class to access the price data member
    protected:
        double price=0.0; //normal, undiscounted price
};
class Bulk_quote: public Quote {
    public:
        Bulk_quote()=default;
        Bulk_quote(const std::string&, double, std::size_t,double);
        //declaration of virtual function from base class
        //using override to explicitly note that it intends a member
        //function to override a virtual that it inherits
        double net_price(std::size_t n)const override 
        {
            return n*price*discount; 
        }
        //undifined behavior if not already defined
    private:
        std::size_t min_qty=0; //minimum purchase for discount to apply
        double discount=0.0; //functional discount to apply
};
#endif