#include "main.h"
void swapMove(double*,double*);
using namespace Adv;

int main(int argc,char ** argv){
    //derive-to-base conversion
    Quote item; //obj of base type
    Bulk_quote bulk; //obj of derived type
    Quote *p = &item; //p points to quote obj
    p=&bulk; // p point to  th quote part of bulk
    Quote &r = bulk; //r bound to the quote part of bulk
    //call to virtual function
    Quote base_cl("0-21-0xisb",12.0);
    print(std::cout,base_cl,50);
    Bulk_quote der_cl("0-201-0xui",50,5,.19);
    print(std::cout,der_cl,10);
    //der_cl=base_cl; //error
    base_cl=der_cl; //ok copy only member of base_cl
    print(std::cout,base_cl,12);
    //abstract base class
    //Disc_quote dicounted; = error
    Pub_derv d1;
    d1.pub_mem(); //ok pub mem
    Priv_derv d2;
    //d2.pub_mem();   inaccesible
    d2.f1(); //ok member of priv_derv
    //dynamic binding for dctor
    Quote_S  *item_x= new Quote_S;
    delete item_x;
    cout<<"same static and dynamic type, call dctor base cl"<<endl;
    item_x = new Derived_Quote_S;
    cout<<"static and dynamic types differ"<<endl;
    delete item_x;
    cout<<"call dctor derived cl"<<endl;
    
    X_Point x_cpCtor; //ok, using the synthesized default ctor
    Y_Point y_derived; //ok
    //Y_Point y_cpCtor(y_derived); deleted function

    return 0;
}
//no need copy just move the pointer
void swapMove(double *x, double *y){
    double *temp = x;
    x=y;
    y=temp;
}
