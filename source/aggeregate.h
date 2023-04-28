#ifndef AGGEREGATE_CLASS_H
#define AGGEREGATE_CLASS_H
#include <iostream>
//aggeragate class example
struct DataAggeregate
{
    int val;
    std::string s;
    void allMemberPub(void);
};
//constexpr class, literal class
class Debug{
    public:
        constexpr Debug(bool b =true):hw(b),io(b),other(b){}
        constexpr Debug(bool h,bool i, bool o):
            hw(h),io(i),other(o){}
        constexpr bool any(){return hw||io||other;} //return constant expression
        void set_io(bool b){io=b;}
        void set_hw(bool b){hw=b;}
        void set_other(bool b){hw=b;}
    private:
        bool hw;
        bool io;
        bool other;
};
class Account{
    public:
        void calculate(){amount+=amount*interestRate;}
        static double rate(){return interestRate;} //not bound to any object
        static void rate(double); //they do not have a this pointer
        void inClassInit();
    private:
        std::string owner;
        double amount;
        static double interestRate; //static members of a class exist outside any object
        static double initRate();
        /*in class initialization of static data member*/
        static constexpr int period=30;//period is a constant expression
        double daily_tbl[period];
};
class AnotherStatic{
    public:
        AnotherStatic &clear(char = backgr);
    private:
        static const int backgr;
};
void changePrecis(const double);
#endif