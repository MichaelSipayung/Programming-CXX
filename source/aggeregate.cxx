#include "aggeregate.h"

void DataAggeregate::allMemberPub(void){
    DataAggeregate data_1  ={1024,"Anna"};
    std::cout<<"Demo aggeragate class (val): " << data_1.val<<std::endl;
    std::cout<<"Demo aggeragate class (name): " << data_1.s<<std::endl;
}
//defenition of static data member
//define the member just only once
//program return undifined behavior if static member  not defined
//account::initRate defenition
double Account::initRate(){
    return 0.0098;
}
double Account::interestRate =initRate(); //define interest rate 
//account::rate defenition
void Account::rate(double newRate){
    interestRate = newRate;
}
constexpr int Account::period; //period defenition
void Account::inClassInit(){
    std::cout<<"using constant expression to define period :  " << Account::period<<std::endl;
    int x  = period;
    std::cout<<"use period after it's defined"<<std::endl;
    std::cout<<"otherwise the program may fail to compile"<<std::endl;
}
/*use a static member as a default arguments*/
//defeni the default value
const int AnotherStatic::backgr=13;
AnotherStatic &AnotherStatic::clear(char x){
    return *this;
}
double preccision=0.0000008;
void changePrecis(const double prec){
    std::cout<<"before change preccision : " << preccision<<std::endl;
    preccision = prec;
    std::cout<<"change preccision : " << preccision <<std::endl;
}
