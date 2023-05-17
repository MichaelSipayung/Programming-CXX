#ifndef OVERLOAD_OP_H
#define OVERLOAD_OP_H
#include <string>
#include <iostream>
#include <vector>
class Sales_Cl{
friend std::ostream &operator<<(std::ostream&, const Sales_Cl&);
    public:
        Sales_Cl()=default;
        Sales_Cl(const std::string &s):bookNo{s}{}
        Sales_Cl(const std::string &s, unsigned n, double p):
            bookNo{s}, units_sold{n}, revenue{p*n}{}
        //overload
        Sales_Cl &operator+=(const Sales_Cl &);
    private:
        double avg_price() const;  
	    std::string bookNo;
	    unsigned units_sold = 0;
	    double revenue = 0.0;        
};
std::ostream &operator<<(std::ostream&, const Sales_Cl&);

class Mat{
friend void show_data(const Mat&);
    public:
        Mat()=default;
        Mat(const std::vector<double> temp): data{temp}{}
        Mat(const Mat& rhs): data{rhs.data}{}
        Mat &operator=(const Mat&);
        Mat &operator+(const Mat&);
    private:
        bool chk_size(const Mat&);
        std::vector<double> data;
};
void show_data(const Mat&);

class IncDec_Operator{
    public:
        IncDec_Operator()=default;
        IncDec_Operator(const std::vector<std::string>&);
        IncDec_Operator(const std::vector<int>&);
        IncDec_Operator(const IncDec_Operator &rh);
        IncDec_Operator &operator++(); //prefix op
        IncDec_Operator &operator--();
        IncDec_Operator operator++(int); //postfix, an extra arg supply to distiguishes
        IncDec_Operator operator--(int);
        std::string &operator*()const; //we intended not to change the state
        std::string *operator->()const;
        ~IncDec_Operator(){}
        void show_curr();
        void show_str()const;
    private:
        std::vector<int> data;
        std::vector<std::string> *str_data;
        size_t pos;
};

//function call operator
struct absInt{
    int operator()(int val)const{
        return val <0?-val:val;
    }
    void test_funObj();
};
inline
void absInt::test_funObj()
{
    absInt test_x;
    std::cout<<test_x(-12);
}
//function obj classes with state
class PrintString{
    public:
        PrintString(std::ostream &o=std::cout, char c=' '):
            os{o}, sep{c}{}
        void operator()(const std::string &s)const {os<<s<<sep;}
    private:
        std::ostream &os; //stream on which to write
        char sep; //char to print after each output
};
#endif