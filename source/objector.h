#ifndef INHERIT_H
#define INHERIT_H
#include <iostream>
#include <vector>
#include <set>
#include <memory>
class Quote{
friend double print_total(std::ostream &, const Quote&,std::size_t );
    public:
        //simulating virtual copy
        //virtual function to return a dynamically allocated copy of itself
        //these members use reference qualifiers
        virtual Quote* clone()const &{return new Quote(*this);}
        virtual Quote* clone() &&{return new Quote(std::move(*this));}
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
double print_total(std::ostream &, const Quote&,std::size_t );
class Bulk_quote: public Quote {
    public:
        Bulk_quote* clone()const&{return new Bulk_quote(*this);}
        Bulk_quote* clone()&&{return new Bulk_quote(std::move(*this));}
        Bulk_quote()=default;
        Bulk_quote(const std::string&, double, std::size_t,double);
        //declaration of virtual function from base class
        //using override to explicitly note that it intends a member
        //function to override a virtual that it inherits
        double net_price(std::size_t n)const override;
        //undifined behavior if not already defined
    private:
        std::size_t min_qty=0; //minimum purchase for discount to apply
        double discount=0.0; //functional discount to apply
};
//inheritance and static member
//define only once for entire hierarchy
class Base{
    public:
        static void statmem(){}
};
class Derived:public Base{
    void f(const Derived&);
};
//preventing inheritance
class NoDerived final{
    public:
        NoDerived(double xP=0) :xpoint{xP}{}
    private:
        double xpoint;
};
//specify override to prevent undifined behavior
struct B_Base{
    virtual void f1(int)const;
    virtual void f2();
};
struct B_Derived:B_Base{
    void f1(int)const override; //specify override explicitly
    void f2()override;
};
//prevent to override
struct Next_Derived:B_Base{
    void f1(int)const final; //can't override f1(int)
};
struct Attem_Overr:Next_Derived{
    //void f1(int)const;
    double x_point;
};
//abstract base class
class Disc_quote:public Quote{
    public:
        Disc_quote()=default;
        Disc_quote(const std::string& book, double price, std::size_t qty,double disc)
            :Quote{book,price}, quantity{qty}, discount{disc}{}
        //pure virtual function
        double net_price(std::size_t)const=0;
    protected:
        std::size_t quantity=0; //purchase size for disc to apply
        double discount=0.0; //fractional discount to apply
};
//a derived class ctor initializes 
//its direct base class only
class Bulk_quote_ref:public Disc_quote{
    public:
        Bulk_quote_ref()=default;
        Bulk_quote_ref(const std::string &book, double price, std::size_t qty, double disc)
            : Disc_quote{book,price,qty,disc}{}
        //overrides the base version to implement the bulk purchase disount policy
        double net_price(std::size_t)const override;
};
class Basket{
    public:
        //basket uses synthesized default ctor and cp control mem
        void add_item(const std::shared_ptr<Quote> &sale)
            {items.insert(sale);}
        void add_item(const Quote& sale){
            items.insert(std::shared_ptr<Quote>(sale.clone()));
        }; //copy the given obj
        void add_item(Quote&& sale){
            items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
        }; //move the given object
        //print the total price for each book and the overall total
        //for all items in the basket
        double total_receipt(std::ostream&)const;
    private:
        //function to compare shared_ptr needed by the multiset member
        static bool compare_bsk(const std::shared_ptr<Quote> &lhs,
            const std::shared_ptr<Quote> &rhs){
                return lhs->isbn()<rhs->isbn();
        }
        //multiset to hold multiple quotes, ordered by the compare num
        std::multiset<std::shared_ptr<Quote>, decltype(compare_bsk)*>
            items{compare_bsk};
};
#endif