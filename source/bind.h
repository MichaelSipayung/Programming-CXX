/*
*Demonstrate how std::bind works
*replace the behavior of lamda to bind
*/
#ifndef BIND_OBJECT_H
#define BIND_OBJECT_H
#include <iostream>
#include <vector>
#include <functional> //header for std::bind
#include <algorithm>
bool checking_size(const std::string &s, std::string::size_type sz){
    return s.size()>=sz;
}
//using std::bind as function adaptor
//modify behavior of lamda
void modLambda(const std::vector<std::string>&word){
    //generate a callable object using std::bind 
    auto wc  = std::find_if(word.begin(),word.end(),std::bind(checking_size,std::placeholders::_1,6));
    std::cout<<"modify lambda version using std::bind"<<std::endl;
    std::cout<<"result : "<< *wc<<std::endl;
}
#endif