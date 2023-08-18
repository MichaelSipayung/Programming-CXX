#include "main.h"
using namespace problem;
int main() {
	tree<string> root, left,right;
	vector<string> ls = { "Knuth","Turing","Bjarne" };
	std::sort(ls.begin(), ls.end());
	root.item = ls[1];
	left.item = ls.front();
	right.item = ls.back();
	root.left = &left;
	root.right = &right;
	//traverse_tree(&root);
	//delete root
	
	delete_node(&root, string("Knuth"));
	traverse_tree(&root);
	//return 0;
}