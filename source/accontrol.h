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
    protected:
        int prot_mem; //protected member
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