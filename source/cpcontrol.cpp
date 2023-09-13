#include "cpcontrol.h"
using namespace refactor;
//demonstrate how copy assignment work
foo_copy& foo_copy::operator=(const foo_copy& rhs)
{
	isbn = rhs.isbn;
	revenue = rhs.revenue;
	return *this; //return reference to this object
}
//destructor takes no parameter
foo_copy::~foo_copy()= default;
