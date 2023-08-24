#include "main.h"
using namespace problem;
using namespace refactor;
int main(int argc, char *argv[]) {
	const auto author = make_shared<my_tree>();
	author->isbn = "miller";
	author->left = make_shared<my_tree>();
	author->left->isbn = "turing";
	author->right = make_shared<my_tree>();
	author->right->isbn = "donald";
	const auto result = search_my_tree(author, "milsler");
	if (result)
		cout << "found miller" << endl;
	else
		cerr << "error, not found !" << endl;
	return 0;
}