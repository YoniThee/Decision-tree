#include"Tree.h"

Node* Tree::search(Node* p, string val, Node*& parent)
{
	return nullptr;
}

void Tree::addRoot(string newval)
{
	root = new Node(newval);//now the root is have value - the string
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	if (this->root->value == fatherquestion) {
		
	}
}
