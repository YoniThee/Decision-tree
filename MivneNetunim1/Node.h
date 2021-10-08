#pragma once
#include"Answer.h"
//Node: each node in the decision tree
class Node
{
	void removeSonValue(string v);
public:
	list<Answer*> answersList;
	string value;
	bool isLeaf;
	Node(string v) { isLeaf = true;  value = v; }
	Node() { }
	friend class Tree;
};