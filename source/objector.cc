#include "objector.h"
Bulk_quote::Bulk_quote(const std::string& s, double p, std::size_t total,double disc)
    :Quote{s,p},min_qty{total},discount{disc}{}

double Bulk_quote::net_price(size_t cnt)const
{
    if(cnt>=min_qty)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}
void Derived::f(const Derived &der_obj)
{
    Base::statmem(); //ok base defines statemem
    Derived::statmem(); //derived inherits statemen
    //ok: derived obj can be used to access static member from base
    der_obj.statmem(); //access through a derrived obj
    statmem(); //access through this obj
}
double print_total(std::ostream &os, const Quote &rh, std::size_t total)
{
    double ret = rh.net_price(total);
    os<<"isbn : "<<rh.isbn()<<"# sold: "<<total<<" total due: "<<ret<<std::endl;
    return ret;
}
double Basket::total_receipt(std::ostream &os)const
{
    double sum=0.0;
    for(auto iter=items.cbegin(); iter!=items.cend(); 
        iter=items.upper_bound(*iter)){
        sum+=print_total(os, **iter, items.count(*iter));
    }
    os<<"Total sale: "<<sum<<std::endl;
    return sum;
}