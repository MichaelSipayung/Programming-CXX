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