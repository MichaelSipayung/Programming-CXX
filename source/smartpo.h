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
class strBlob{
    public:
        typedef std::vector<std::string>::size_type size_type;
        typedef std::vector<std::string>::iterator iterator;
        typedef std::vector<std::string>::const_iterator const_iterator;
        strBlob();
        strBlob(std::initializer_list<std::string>il);
        size_type size()const{return data->size();}
        bool empty()const{return data->empty();}
        void push_back(const std::string&t){data->push_back(t);}
        void pop_back();
        iterator begin()const{return data->begin();}
        iterator end()const{return data->end();};
        const_iterator cbegin()const {return data->cbegin();};
        const_iterator cend()const{return data->cend();};
        std::string&front();
        std::string&back();
        const std::string&front()const;
        const std::string&back()const;
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg)const;
};
strBlob::strBlob():data(std::make_shared<std::vector<std::string>>()){}
strBlob::strBlob(std::initializer_list<std::string>il):
    data(std::make_shared<std::vector<std::string>>(il)){}
void strBlob::check(size_type i,const std::string &msg)const
{
    if(i>=data->size())
        throw std::out_of_range(msg);
}
std::string &strBlob::front()
{
    check(0,"front on empty strblob");
    return data->front();
}
const std::string &strBlob::front()const
{
    return data->front();
}
std::string &strBlob::back()
{
    check(0,"back on empty strblob");
    return data->back();
}
const std::string &strBlob::back()const
{
    check(0,"back on empty strblob");
    return data->back();
}
void strBlob::pop_back()
{
    check(0,"pop back on empty strblob");
    data->pop_back();
}
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
void manage_array()
{
    auto alloc_vec  = std::make_shared<std::vector<int>>();
    auto point_vec  = alloc_vec;
    if(!alloc_vec.unique())
        alloc_vec.reset(new std::vector<int>()); //safetly alloc new resource
    // do something ...
}

}
#endif