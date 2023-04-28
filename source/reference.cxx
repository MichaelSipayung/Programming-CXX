#include "reference.hpp"
void pointer_const(){
    const double pi =3.14;
    const double *ptr= &pi;
    std::cout<<"point to double that is const"<<std::endl;
    std::cout<<"access the value : "<< *ptr <<std::endl;
}
void reference(){
    int a = 12;
    int &x_ref_a = a;
    std::cout<<"value after reference : " << x_ref_a<<std::endl;
}
void more_dereference(){
    int **x = nullptr;
    int y=12;
}
void cons_exp(){
    const int max_files = 20;
    const int limit = max_files+1;
    std::cout<<"1. example of the constant expression : "<<max_files<<std::endl;    
    std::cout<<"2. example of the constant expression : "<<limit<<std::endl;
    int a = sizeof(int);
    std::cout<<"not a constant expression : " << a 
        <<" the value know in runtime"<<std::endl;
    constexpr int mf = 20;
    std::cout<<"automatically check if the mf variable is const expression : " 
        << mf <<std::endl;
    constexpr int *np =nullptr;
    std::cout<<"example of the constant pointer to int"; 
}
void type_alias(){
    typedef double pecahan;
    pecahan phi =  22/7.0;
    std::cout<<"using type alias : " << phi <<std::endl;
    using inte_num = int;
    inte_num  x= 13;
    std::cout<<"type alias using keyword : " << x<<std::endl;
}
void type_alias_pointe(){
    typedef char *pstring;
    const pstring cstr=0;
    std::cout<<"cstr variable is a constant pointer to char"<<std::endl;
    const pstring *ps = nullptr;
    std::cout<<"ps is a variable pointer to constant pointer to char"<<std::endl;
}
void the_auto_spe(){
    auto x =12;
    auto y  = 1.0/x;
    std::cout<<"result x : " <<x <<std::endl;
    std::cout<<"result y : "<<y <<std::endl;
    int i =0, &r=i;
    auto a = r;
    std::cout<< "ignore reference type :" << a<<std::endl;
    const int ci =12;
    auto bi = ci;
    bi =13;
    std::cout<<"ignores top level const, bi variable can be modified : "<< bi<<std::endl;
    /*define it explicitly*/
    const auto f  = ci;
    std::cout<<"define it explicitly : " <<f <<std::endl;
}
void us_declty(){
    decltype (3/12.0) sum ;
    std::cout<<"using decltype to assign variable type from expression : " <<std::endl;    
    sum =13.5;
    std::cout<<"assign sum variable : " << sum <<std::endl;
    std::cout<<"decltype include the top level const not like auto "<<std::endl;
    const int ci =0,&cj=ci;
    decltype(ci) x= 0;
    std::cout<<"x has type const int" <<std::endl;
    decltype(cj) y  = x;
    std::cout<<"y has type const int & and it's bound to x"<<std::endl;
}