/*
*Demonstrate how std::bind works
*replace the behavior of lamda to bind
*/
#ifndef BIND_OBJECT_H
#define BIND_OBJECT_H
#include <iostream>
#include <vector>
#include <functional> //header for std::bind
bool check_size(const std::string &s, std::string::size_type sz){
    return s.size()>=sz;
}
#endif