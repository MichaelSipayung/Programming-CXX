#include "main.h"
using namespace Adv;

int main(int argc,char ** argv){
    Test_Template t1(12,15.0,"world");
    t1.compare_test();
    t1.compare_str();
    templ_cl_test();
    //using static data member on template cl
    Foo_St<int> nat_num, other_num;
    //nat_num and other_num share the same stat member
    cout<<nat_num.count()<<endl;
    cout<<nat_num.count()<<endl;
    cout<<other_num.count()<<endl;
    
    return 0;
}
