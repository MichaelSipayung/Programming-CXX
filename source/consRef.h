#ifndef CONS_REF_H
#define CONS_REF_H
#include <iostream>
class Consref{
    public:
        Consref() = delete;
        Consref(int ii):i(ii),ci(ii),ri(i){} //explictly initialize reference and const member
    private:
        int i;
        const int ci;   //const object
        int &ri;        //reference
};
#endif