#ifndef RVALUE_H
#define RVALUE_H
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::allocator;
using std::unique_ptr;
#include <utility>
#include <algorithm>
using std::sort;
namespace Adv{
class RvalRef{
    public:
        RvalRef()=default;
        RvalRef(const string &is,const double &rev):isbn{is},revenue{rev}{}
        RvalRef(const RvalRef &rh):isbn{rh.isbn}, revenue{rh.revenue}{}
        RvalRef(RvalRef &&s)noexcept; //mv ctor
        RvalRef &operator=(RvalRef&&)noexcept;
        RvalRef &operator=(const RvalRef&)noexcept;
        //RvalRef &operator=(const RvalRef&)=delete;
        ~RvalRef(){}; //need dctor for cp ctor an cp assign
        void rvalBase()noexcept(true);
        void rvalMove()noexcept(true);
        void showData()noexcept;
        void mvMatch()noexcept;
        void cpMatch()noexcept;
    private:
        string isbn;
        double revenue;
};
//Synthesized move operations
struct X{
    int i; //built in type can move
    string s; //str defines its own mv oper
};
struct hasX{
    X mem; //x has synt move op
};
class Foo_1{
public:
    Foo_1()=default;
    Foo_1(const Foo_1&); //cp ctor
    void noMoveOp()noexcept;
};
class Rhs_1{
    public:
        //mv ctor
        Rhs_1()=default;
        Rhs_1(const Rhs_1&)=default;
        Rhs_1(Rhs_1&&p)noexcept:xPoint{p.xPoint},yPoint{p.yPoint}{p.xPoint=0; p.yPoint=0;}
        Rhs_1& operator=(Rhs_1 mvCp); //assign oper is both move and cp assign oper
        ~Rhs_1(){}
        void demo_mvCp()noexcept;
        //providing both cp and move on a function
        void push_back(const double&);
        void push_back(double&&);
        void demo_push();
        void assign(const double &x, const double y){xPoint=x;yPoint=y;} 
        void assign(double &&x, double &&y)
            {xPoint=std::move(x); yPoint=std::move(y);}
    private:
        double xPoint;
        double yPoint;
};
inline
void Rhs_1::push_back(const double &s)
{
    xPoint +=s;
    yPoint+=s;
}
inline
void Rhs_1::push_back(double &&s)
{
    xPoint= std::move(s);
    yPoint= std::move(s);
}
inline
void Rhs_1::demo_push()
{
    Rhs_1 testX;
    testX.assign(12.0,13.0); //using move version
    double lvalX=13.0;
    double lvalY=12.0;
    testX.assign(lvalX,lvalY); //using cp version 
    //push test
    testX.push_back(14.9); //second v
    testX.push_back(lvalX);//first v

}
inline
Rhs_1 &Rhs_1::operator=(Rhs_1 mvCp)
{
    using std::swap;
    swap(*this,mvCp);
    return *this;
}
inline
void Rhs_1::demo_mvCp()noexcept
{
    Rhs_1 hp,hp2;
    hp= hp2; //hp2 is lval
    hp = std::move(hp2); //mv ctor moves hp2
}
inline
void Foo_1::noMoveOp()noexcept
{
    Foo_1 x;
    Foo_1 y(x);
    Foo_1 z(std::move(x)); //calling cp ctor no mv ctor; ok safe
}
void syntMove()
{
    X x,x2 = std::move(x);
    hasX hx,hx2= std::move(hx); //use synt move ctr
}
inline 
void RvalRef::rvalBase()noexcept(true)
{
    int xPoint = 12;
    int &lvalRef = xPoint;
    xPoint = 13;
    cout<<"lval ref : " << lvalRef<<endl;
    int &&rvalRef = xPoint*12;
    std::cout<<"rval ref : "<<rvalRef<<endl;
    const int &bindRef = xPoint*2;
    cout<<"bind reference to const to an rval : "<<bindRef<<endl;
    int &&anRvalRef  = xPoint++; //postfix op. ok, val : 13, xpoint =14
    cout<<"dealing rval ref with postfix operator : "<< anRvalRef<<endl;
}
inline
void RvalRef::rvalMove()noexcept(true)
{
    //variables are lvalues
    int &&rr1  =42;
    //int &&rr2=rr1; error
    //cast lvalue to its correspoinding rvalue reference type
    int &&rr3 = std::move(rr1);//cast, thinking about temporary object
}
//body for destroying object that can't aut destroy eq. pointer
RvalRef::RvalRef(RvalRef &&s)noexcept
    :isbn{s.isbn}, revenue{s.revenue}
{
    s.isbn=" "; //ensure no object point to this
    s.revenue= 0.0;
}
inline
void RvalRef::showData()noexcept
{
    cout<<"isbn : "<< isbn<<endl;
    cout<<"revenue : "<<revenue<<endl;
}
RvalRef &RvalRef::operator=(RvalRef &&s)noexcept
{
    if(this!=&s)
    {
        //freed memory if it contain pointer
        isbn=s.isbn;
        revenue=s.revenue;
        s.isbn=" ";
        s.revenue=0.0;
    }
    return *this;
}
RvalRef &RvalRef::operator=(const RvalRef &s)noexcept
{
    if(this!=&s)
    {
        isbn =s.isbn;
        revenue=s.revenue;
    }
    return *this;
}
inline
void RvalRef::mvMatch()noexcept
{
    RvalRef v1,v2("jackie", 15.5);
    v1= std::move(v2); //mv assignment;
    cout<<" calling mv assignment : "<<endl;
    v1.showData();
}
inline
void RvalRef::cpMatch()noexcept
{
    RvalRef v1,v2;
    v1=v2; //cp assignment
}
class Ref_Mem_Fun
{
    public:
        Ref_Mem_Fun()=default;
        Ref_Mem_Fun(const Ref_Mem_Fun &s):fixPoint{s.fixPoint}{}
        Ref_Mem_Fun &operator=(const Ref_Mem_Fun&)&; //may assign only to modifiable lval  
        ~Ref_Mem_Fun(){}
        void testLvalRef();
        double xPoint;
    private:
        string fixPoint;
};
inline
Ref_Mem_Fun &Ref_Mem_Fun::operator=(const Ref_Mem_Fun& s)&
{
    //do assign operation .
    return *this;
}
inline
void Ref_Mem_Fun::testLvalRef()
{
    double x = 35.9;
    Ref_Mem_Fun objTest, objTestY;
    //bjTestY() = objTest;  error left hand op return rvalue
    Ref_Mem_Fun &anoTest(objTest);
    anoTest =objTest; //ok left op return lval
}
//overloading and reference function
class Foo_B{
    public:
        Foo_B()=default;
        Foo_B(const Foo_B&)= default;
        Foo_B sorted() &&; //may run modifiable rvalues
        Foo_B sorted()const&; //run any kind of foo_b
        void demo_Overload();
    private:
        vector<int> data;
};
Foo_B Foo_B::sorted()&&
{
    sort(data.begin(), data.end());
    return *this;
}
Foo_B Foo_B::sorted() const&
{
    Foo_B ret(*this); //make a copy
    sort(ret.data.begin(), ret.data.end());
    return ret; //ret cp
}
inline
void Foo_B::demo_Overload()
{
    Foo_B val;
    Foo_B &refLval =val;
    refLval.sorted(); //calling sorted & version
    //Foo_B initRval(); //calling the second version &&, ret by val initR is rval
    //().sorted();
} 
}
#endif