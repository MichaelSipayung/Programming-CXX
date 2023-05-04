/*
* using smart pointer to dynamically allocate memory
*shared_ptr, unique_ptr, weak_ptr
*/
#ifndef SMART_POINTER_H
#define SMART_POINTER_H
#include <iostream>
#include <vector>
#include <memory>
namespace Smart{
class strBlob{
    public:
        typedef std::vector<std::string>::size_type size_type;
        strBlob();
        strBlob(std::initializer_list<std::string>il);
        size_type size()const{return data->size();}
        bool empty()const{return data->empty();}
        void push_back(const std::string&t){data->push_back(t);}
        void pop_back();
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
}
#endif