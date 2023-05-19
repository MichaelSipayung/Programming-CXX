#include "main.h"
void swapMove(double*,double*);
using namespace Adv;

int main(int argc,char ** argv){
    //derive-to-base conversion
    Quote item; //obj of base type
    Bulk_quote bulk; //obj of derived type
    Quote *p = &item; //p points to quote obj
    p=&bulk; // p point to  th quote part of bulk
    Quote &r = bulk; //r bound to the quote part of bulk
    return 0;
}
//no need copy just move the pointer
void swapMove(double *x, double *y){
    double *temp = x;
    x=y;
    y=temp;
}
