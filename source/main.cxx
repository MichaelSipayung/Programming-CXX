#include "main.h"
using namespace problem;
using namespace refactor;
int main(int x, char *argv[]) {
	const auto author = make_shared<my_tree>();
	author->isbn = "miller";
	author->left = make_shared<my_tree>();
	author->left->isbn = "turing";
	author->right = make_shared<my_tree>();
	author->right->isbn = "donald";
	tree_traverse<string>(author);
	return 0;
}