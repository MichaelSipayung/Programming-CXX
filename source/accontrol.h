#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H
#include <iostream>
    using std::cout;
    using std::cin;
    using std::string;
#include <vector>
    using std::vector;
//protected members
class Base_Acc{
    public:
        void pub_mem(){};
    protected:
        int prot_mem; //protected member
    private:
        char priv_mem;
};
//all member accessible through access specifier
struct Pub_derv:public Base_Acc{ 
    //making acc from this obj to public member of base cl
    int f(){return prot_mem;}
};
struct Priv_derv:private Base_Acc{
    //making acc from this obj to private member of base cl
    int f1()const{return prot_mem; } 
    //ok, but have no access to base cl private mem
};
class Sneaky: public Base_Acc{
friend void clobber(Sneaky&); //access sneaky prot member
friend void clobber(Base_Acc&); //can't acc prot member of base_acc
    private:
        int j;
};
void clobber(Sneaky &s){
    s.j = s.prot_mem=0;
}
//member on derived clas 
//only have an access to data or member in derived class not to base class
void clobber(Base_Acc &b){
    //b.prot_mem=0; not accessible
}
#endif