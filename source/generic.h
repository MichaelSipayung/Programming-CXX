/*
    generic algorithm tested to container
*/
#ifndef GENERIC_H
#define GENERIC_H
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
void findAl(const std::vector<int>&);
void sumElm(const std::vector<double>&);
void modifyEl(std::string &);
void safeInsert(std::string&);
void safeCopy(size_t);
void elimDups(std::vector<std::string>&x);
bool predicateCon(const std::string &, const std::string &);
void testPredicate(std::vector<std::string>);
void useLambda();
void lamdaWithArgs();
void useCaptureList(const std::vector<std::string> &,std::string::size_type);
void capByVal();
void capByRef();
void capByRef(std::vector<std::string> &, std::string::size_type,
    std::ostream&,char);
void implicitCapture(std::vector<std::string>&,std::vector<std::string>::size_type,
    std::ostream&,char);
void changeValueLambda();
//using trailing return type to lambda  
void trailingRet(std::vector<int> &);
#endif