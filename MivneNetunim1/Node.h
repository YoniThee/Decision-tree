#pragma once
#include"Answer.h"
using namespace std;
//Node: each node in the decision tree
class Answer;
class Node
{
	void removeSonValue(string v);
public:
	list<Answer*> answersList;
	std::string value;
	bool isLeaf;
	Node(string v) { isLeaf = true;  value = v; }
	Node() { }
	friend class Tree;
};