#include "main.h"
using namespace Adv;

int main(int argc,char ** argv){
    //Test_Template t1(12,15.0,"world");
    //t1.compare_test();
    //t1.compare_str();
    //templ_cl_test();
    //using static data member on template cl
    //Foo_St<int> nat_num, other_num;
    //nat_num and other_num share the same stat member
    //cout<<nat_num.count()<<endl;
    //cout<<nat_num.count()<<endl;
    //cout<<other_num.count()<<endl;
    //Book_Str<std::string,double> rep_book;
    //cout<<"class member that are types : "<<rep_book.show_all()<<endl;
    //declare matrix with double type
    //MatD<2,3> two_thr;
    //Blob_T<int> vec_ls = {0,1,2,3,4,5,6,7};
    //cout<<"begin result :  " << *vec_ls.begin() <<endl;
    //cout<<"begin result :  " << *(vec_ls.begin()+1) <<endl;
    //cout<<"end result :  " << *(vec_ls.end()-1)<<endl;
    //default arguments and class templates
    int *px = new int;
    DebugDelete_T dx;
    dx(px);
    std::cout<<"fix issuing"<<std::endl;
    //member template that a class
    int a1[]= {0,1,2,3,4,5,6,7};
    Blob_Mem_T<int> nat_num(std::begin(a1),std::end(a1));//instantiation of member tem <int>
    nat_num.show_mem();
    //for the other version
    std::shared_ptr<std::vector<int>> temp = 
        std::make_shared<std::vector<int>>(std::begin(a1),std::end(a1));
    cout<<*temp->begin();
    return 0;
}
