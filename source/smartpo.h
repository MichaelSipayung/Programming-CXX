/*
* using smart pointer to dynamically allocate memory
* shared_ptr, unique_ptr, weak_ptr
*/
#ifndef SMART_POINTER_H
#define SMART_POINTER_H
#include <iostream>
#include <vector>
#include <memory>
#include <new> //header for for std::bad_alloc, std::nothrow
namespace Smart{
class StrBlobPtr; //forward declaration needed for friend declaration in strblob
class strBlob{
    friend class StrBlobPtr; //making strblobptr as friend use data member
    public:
        StrBlobPtr begin(); //return strblobptr to the first el
        StrBlobPtr end(); //and one past the last element
        typedef std::vector<std::string>::size_type size_type;
        typedef std::vector<std::string>::iterator iterator;
        typedef std::vector<std::string>::const_iterator const_iterator;
        strBlob();
        strBlob(std::initializer_list<std::string>il);
        //StrBlobPtr begin();
        //StrBlobPtr end();
        size_type size()const{return data->size();}
        bool empty()const{return data->empty();}
        void push_back(const std::string&t){data->push_back(t);}
        void pop_back();
        /*iterator begin()const{return data->begin();}
        iterator end()const{return data->end();}*/
        const_iterator cbegin()const {return data->cbegin();}
        const_iterator cend()const{return data->cend();}
        std::string& front();
        std::string& back();
        const std::string& front()const;
        const std::string& back()const;
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg)const;
};
class StrBlobPtr{ 
    public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(strBlob &a, size_t sz=0):
            wptr(a.data),curr(sz){}
        std::string& deref()const;
        StrBlobPtr& incr(); //prefix version
    private:
        std::shared_ptr<std::vector<std::string>> check
            (std::size_t, const std::string&)const;
        //store a weak_ptr, which means the underlying vector might be destr
        std::weak_ptr<std::vector<std::string>>wptr;
        std::size_t curr; //current position within the array
};
inline
strBlob::strBlob():data(std::make_shared<std::vector<std::string>>()){}
inline
strBlob::strBlob(std::initializer_list<std::string>il):
    data(std::make_shared<std::vector<std::string>>(il)){}
void strBlob::check(size_type i,const std::string &msg)const
{
    if(i>=data->size())
        throw std::out_of_range(msg);
}
inline
std::string &strBlob::front()
{
    check(0,"front on empty strblob");
    return data->front();
}
inline
const std::string &strBlob::front()const
{
    return data->front();
}
inline
std::string &strBlob::back()
{
    check(0,"back on empty strblob");
    return data->back();
}
inline
const std::string &strBlob::back()const
{
    check(0,"back on empty strblob");
    return data->back();
}
inline
void strBlob::pop_back()
{
    check(0,"pop back on empty strblob");
    data->pop_back();
}
//definition of strblobptr
inline
std::shared_ptr<std::vector<std::string>>
    StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret  = wptr.lock(); //is the vector still around ?
    if(!ret)
        throw std::runtime_error("unbound strblobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret; //otherwise, return a shared_ptr to the vector
}
//dereference and increment strblobptr
inline
std::string& StrBlobPtr::deref()const
{
    auto p  = check(curr,"dereference past end");
    return (*p)[curr]; //(*p) is the vector to which this object points
}
inline
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of strblobptr");
    ++curr; //advance current state
    return *this;
}
//this member can't be defined until strstrblob and strstrblobptr are defined
//don't forget to put declaration of strblowptr before strblob class
inline
StrBlobPtr strBlob::begin(){return StrBlobPtr(*this);}
inline
StrBlobPtr strBlob::end(){return StrBlobPtr(*this,data->size());}
template<typename Object>
void hello_ptr(std::shared_ptr<Object>&x, const Object&val)
{
    if(x)
        *x = val;
    else
        std::cout<<"null pointer"<<std::endl;    
}
//using make_shared function to allocate dynamic memory
void alloc_ptr(const double&x,const std::string&y)
{
    //test case for string and double object
    std::shared_ptr<double> temp_d= std::make_shared<double>(x); //temp_d store x as value
    std::shared_ptr<std::string> temp_str  = std::make_shared<std::string>(y);
    std::shared_ptr<int> temp_int = std::make_shared<int>(); //value initialize : 0
    std::cout<<"access the element : " << *temp_d<<std::endl;
    //using auto 
    auto temp_aut  = std::make_shared<std::vector<double>>();
}
//dynamically alocate the object using new
//deallocate using delete
void alloc_new()
{
    int *x  = new int;//unitialized int
    std::string *y  = new std::string(); //value initialized empty string
    std::vector<int>*p= new std::vector<int>{0,1,2,3,4,5,6,7,8,9}; //val init 10 el
    //value initialized using empty parentheses
    std::vector<std::string> *str  = new std::vector<std::string>();
    //for const object
    const int *pc1 = new const int(1024); //pc1 is pointer to const, pc1 value is 1024
    const std::string *str1 = new const std::string();//default initialized, empty string
}
//if new unable to allocate the requested storange, throw exception bad_alloc
//nothrow to return null pointer if it fail
void alloc_nothrow()
{
    int *p1 = new int; //ooh fail, throw bad_alloc
    int *p2  = new (std::nothrow) int;//if fail, return null pointer
}
void dealloc_obj()
{
    int *x = new int(13);
    int *y = new (std::nothrow) int[10];
    for (int i = 0; i < 10; ++i)
    {
        *y  =i;
        std::cout<<*y<<" | ";
        ++y;
    }
}
//using new in smart pointer
//smart pointer ctor is explicit so you can't implicitly convert
std::shared_ptr<int>clone(int p){
    //eror return new int(p) // try to implicit conversion to shared_ptr
    return std::shared_ptr<int>(new int(p));
}
std::shared_ptr<double>clone(double p){
    return std::make_shared<double>(p);
}
//using reset to assign new value
//reset the counter which p point
void other_op()
{
    auto p  = std::make_shared<int>(134);
    int val =20;
    std::cout<<"old p : " << *p<<std::endl;
    auto point_p = p;
    std::cout<<"counter : 1 (unique) and otherwise " << p.unique()<<std::endl;
    if(!p.unique())
        p.reset(new int(*p)); //we aren't alone, alocate new copy
    
    *p+=val; //now that we know we're the only pointer, okay to change this object
    std::cout<<"after calling reset to p : (p) " <<*p<<std::endl;
    std::cout<<"after calling reset to p : (q) " <<*point_p<<std::endl;
}
void manage_con()
{
    auto alloc_vec  = std::make_shared<std::vector<int>>();
    auto point_vec  = alloc_vec;
    if(!alloc_vec.unique())
        alloc_vec.reset(new std::vector<int>()); //safetly alloc new resource
    // do something ...
    //alloc pointer to int case
    auto alloc_point = std::make_shared<int*>(new int[10]);
    *alloc_point = new int(13);
    ++(*alloc_point) = new int(20); //point to next address
    std::cout<<"allocate array using smart pointer : " << *(*alloc_point)<<std::endl;
    //reset
    alloc_point.reset(new int*());
    *alloc_point = new int(13);
    std::cout<<"allocate array using smart pointer : " << *(*alloc_point)<<std::endl;
}
//unique_ptr no copy or assignment because
//it's only point to one object at the time
void uniqPtr_alloc()
{
    std::unique_ptr<double> x(new double(45.0)); //x point to int with val 45.0
    std::unique_ptr<std::vector<int>> enery(new std::vector<int>()); //enery point to vec int
    std::cout<<"access it's element : " << *x << std::endl;
    //x.reset() //delete the obj to which x points
    x.reset(new double(35.5)); //reset the pointer
    std::cout<<"access it's element : " << *x << std::endl;
    //release : relingquishes control of the pointer u had held; 
    //return the pointer u had held
    x.release(); 
    if(x==nullptr)
        std::cout<<"after call release... reset pointer to null value"<<std::endl;
}
//return unique_ptr
//copy or assig a unique_ptr that is about to destroyed. ok
std::unique_ptr<int>cloneRet(int p)
{
    std::unique_ptr<int> temp(new int(p)); //ok temporary 
    return temp; //destroy
}
//weak_ptr = share object weakly
void alloc_weakly()
{
    auto x  = std::make_shared<int>(14);
    std::weak_ptr<int>y(x); //reference count x is still 1
    std::cout<<"after weakly share object : " << x.use_count()<<std::endl;
    //non weak version 
    auto z  = x;
    std::cout<<"non weak version, now reference count to x :  " << x.use_count()<<std::endl;
}
//using member lock to access object in weak_ptr
void acc_weakPtr()
{
    auto x = std::make_shared<double>(45.9);
    std::weak_ptr<double> y(x); //x share it's object to x
    //it might no longer exist, access indirectly
    if(std::shared_ptr<double>z = y.lock())
        std::cout<<*x<<std::endl; //inside the if, y shares its object with p
    //reset weak_ptr 
    y.reset();
    x.reset(new double(90.7));
    std::cout<<"after reset weak_ptr [0 (use_count = 0) otherwise ] : " << y.expired() <<std::endl;
}
//declare class, needed forward declaration for BasePoint class
class BasePointFriend;
class BasePoint{
    friend BasePointFriend;
    public:
        BasePoint(){};
        void push_back();
        double back();
        //declare friend member here
        BasePointFriend begin();
        BasePointFriend end();
    private:
        std::shared_ptr<std::vector<double>> data;
        void check();
};
class BasePointFriend{
    public:
        BasePointFriend(){};
    private:
        std::weak_ptr<std::vector<double>> data_f;
        void check();
};
//define begin and end 
}
#endif