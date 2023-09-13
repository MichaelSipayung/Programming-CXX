//this file is part of c++ primer, subject covered all about copy control
#pragma once
#include <iostream>

#include "dynamic.h"
using std::string;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
namespace refactor
{
class foo_copy
{
public:
	foo_copy(const foo_copy&); //copy ctor
	//the copy ctor should not define explicit
	foo_copy(); //default ctor : the first parameter must be reference type
	//assignment oeprator ordinarily should return a reference to their 
	//left hand operand
	foo_copy& operator=(const foo_copy&); //assignment operator
	~foo_copy();

private:
	string isbn;
	double revenue;
};
}
