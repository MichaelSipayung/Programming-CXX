#include "main.h"

int main(int argc, char **argv) {
	vector<int> num = {0,1,2,3,1,13,1,3,1,3,111,231,34};
	Refac::useFind(num,111);
	list<string> authname={"jackie","miller","john","bradley","fuller"};
	Refac::useFind(authname,"miller");
	Refac::useFindAl(num,1);
	//test on built in array
	int currNum[] ={0,1,3,1,5,1,5,12,5,3,6,7,68,609};
	Refac::useFindAl(currNum,1);
	return 0;
}
