#include "main.h"
using namespace problem;
using namespace refactor;
int main() {
	init_unique_ptr();
	//test copy
	const auto x = clone(12);
	cout << *x;
	return 0;
}