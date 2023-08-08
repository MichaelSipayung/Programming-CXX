#include "main.h"
using namespace problem;
int main() {
	queue_linked<int> num;
	num.put(3);
	num.put(5);
	num.put(7);
	while (!num.empty())
	{
		cout << num.get() <<" | ";
	}
	queue_array<string> auth(3);
	auth.put("miller");
	auth.put("thomas");
	if (!auth.empty())
	{
		cout << auth.get()<<endl;
		cout << auth.get();

	}
	return 0;
}