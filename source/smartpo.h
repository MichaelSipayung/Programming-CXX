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
        iterator begin_s()const{return data->begin();}
        iterator end_s()const{return data->end();}
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
void array_dyn(const int &x)
{
    int *nat_num = new int[x]{0}; //initialize with 0
    std::cout<<"1. allocate array dynamically :  " << *nat_num<<std::endl;
    ++nat_num;
    *nat_num+=2;
    std::cout<<"2. allocate array dynamically :  " << *nat_num<<std::endl;
    std::string *authors  = new std::string[x]{}; //value initialized to empty string
    *authors = "miller";
    *authors+=" cliff";
    std::cout<<"allocate for string : " << *authors<<std::endl;
    char *short_auth  = new char[100]{}; //empty char, value initialized
    *short_auth  ='j';
    ++short_auth;
    *short_auth='a';
    std::cout<<*(short_auth-1)<<*(short_auth)<<std::endl;
    //direct initialized using braced list 
    int *arr_1 = new int[10]{0,12,3,4,5,6,7,74,43,2};
    std::string *str_1  = new std::string[10]{"jack","miller","pass","new","obj"};
    delete []arr_1; //freeing dynamic array
    delete []str_1;
    std::cout<<"success freed array from memory"<<std::endl;
    ///str_1[0]="9999"; problem! need to reallocate again //memory leak
}
//smart pointer and dynamic array
//using array inside smart ptr, access using [] not dot
//not point to object but to allocated array
void smart_arr()
{
    std::unique_ptr<int[]> nat_num(new int[10]{0}); //no cp for unique ptr, must direct init
    //assign value using []
    for(int i=0;i<10;++i)
        nat_num[i]=i*2;
    //traverse not using begin and end 
    for(int i=0;i<10;++i)
        std::cout<<nat_num[i]<<" | ";
    std::cout<<std::endl;
    //using release to destroy its pointer
    nat_num.release();
    //reset the pointer make it null or allocate the new value
    nat_num.reset(new int[100]); //ask new storange  
    nat_num[90]=90;
    std::cout<<"after reallocate : " <<nat_num[90]<<std::endl;
    //after that destroy
    nat_num.release();
    std::cout<<"safely destroy the object"<<std::endl;
}
//shared_ptr have no operator [] and unsupport to arithmetic op
void smart_arr2()
{
    std::shared_ptr<int> sp(new int[10],[](int *p){delete[]p;}); //pass lamda as a deleter
    //access using get member function 
    for(size_t i =0;i!=10;++i)
        *(sp.get()+i)=i; //use get to get built-in pointer //no subscript
    //free the array 
    sp.reset();
    std::cout<<"success reset the pointer sp"<<std::endl;
}
//the allocator class : seperate allocation fron construction
//using new and delete doing one thing two times deallocate and also destruction
void allocator_cl()
{
    std::allocator<std::string> alloc; //object that can allocate str
    auto p = alloc.allocate(3); //allocate 10 unconstructed str
    auto q=p; //q will point to one past the lst constr mem
    alloc.construct(q++,"first");
    alloc.construct(q++,"second");
    alloc.construct(q++,"three"); //point to last construct
    //alloc.construct(q++,"hi");//*q is "hi"
    for(auto i=0;i<3;++i)
        std::cout<<p[i]<<" | ";
    std::cout<<std::endl;
    //destroy the object
    while(q!=p)
    {
        std::cout<<"free the str"<<std::endl;
        alloc.destroy(--q); //free the string we actually allocated
    }
    //after destroy, making q point to the first uncostructed element
    alloc.construct(q++,"change");
    std::cout<<"after change : " << p[0]<<std::endl;
    //don't forget to destroy
    alloc.destroy(--q);
    //try to deallocate : free memory
    alloc.deallocate(p,3); //can't be null value
    //std::cout<<"val : "<<p[0]<<std::endl; //undefined
}
void sumNum()noexcept(true)
{
    int a =12;
    const std::vector<int> b ={9};
    std::cout<<"noexcept for exception safe : " << a+b[0]<<std::endl;
}
//copy element to unconstructed mem
void copy_unitialized_mem()
{
    std::allocator<int> alloc; //object that can allocate int 
    auto x1 = alloc.allocate(5); //unconstructed
    for(auto i=0;i<5;++i)
        alloc.construct(x1+i,i+2);
    for(auto i=0;i<5;++i)
        std::cout<<x1[i]<<" | ";
    //copy to unconstructed memory
    std::cout<<std::endl;
    auto dest_x1  = alloc.allocate(5);
    std::uninitialized_copy(x1, x1+5,dest_x1); //[beg,end,dest] 
    //after copy to unconstructed memory
    std::cout<<"copy unitialized : ";
    for(auto i=0;i<5;++i)
        std::cout<<dest_x1[i]<<" | ";
    std::cout<<std::endl;
}
//fill with copy 
void copy_fill(const std::vector<int>&x)noexcept(true)
{
    std::allocator<int> alloc;
    //allocate twice as many el as x hold
    auto p= alloc.allocate(x.size()*2); //p hold vector to int, x.size()*2 unconstrud el
    //construct el strt at p as copies of el in v
    auto q  = std::uninitialized_copy(std::begin(x),std::end(x),p); //point to th last uncon mem
    //initialized the remaining el to 42
    std::uninitialized_fill_n(q,x.size(),42); //construct n obj start from q to 42
    for(auto i=0;i<x.size()*2;++i)
        std::cout<<p[i] <<" | ";
    std::cout<<std::endl;
} 
//relearn allocator class
void alloc_cls(const int &z)
{
    std::allocator<double> alloc;
    auto p  = alloc.allocate(z);
    auto q  =p; //point to the last unconstruted p
    alloc.construct(q++,35.0); //q point to p[0]
    alloc.construct(q++,36.0);
    alloc.construct(q++,37.0);
    alloc.construct(q++,38.0); //dont dereference *q because it's sit on the uncons obj
    //p[0]=12.9; //ok memory already constr
    for(auto i=0;i<z;++i)
        std::cout<<p[i]<<" | ";
    std::cout<<std::endl;
    //destroy.. p still point to p[0] , q point to the one past the last constr elem
    while(q!=p)
        alloc.destroy(--q);
    //the deallocate
    alloc.deallocate(p,z);// deallocate p
    //demo copy 
    auto dest  = alloc.allocate(z*2);
    const std::vector<double> &tempVec = {0,1,2,3};
    std::uninitialized_copy(std::begin(tempVec), std::end(tempVec),dest);
    //point to the last unconstr : dest
    auto q_temp  = dest;
    std::uninitialized_fill_n(q_temp+z,z,55.0); 
    for(auto i=0;i<z*2;++i)
        std::cout<<dest[i]<<" | ";
    std::cout<<std::endl;
}

}
#endif