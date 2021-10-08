#pragma once
#include <iostream>
#include <list>
#include <string>
#include"Node.h"
using namespace std;
//Tree: the Decision Tree
class Tree
{
	Node* root;
	Node* search(Node* p, string val, Node*& parent);
	//returns node t where the string equals val. If t has a prent, the pointer parent will contain its address. 

	bool searchAndPrint(Node* p, string val);
	void print(Node* p, int level = 0);
	void process(Node* p);
public:
	Tree() { root = NULL; }
	~Tree() {
		deleteAllSubTree(root);
		root = 0;
	}
	void deleteAllSubTree(Node* t);
	void addRoot(string newval);
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val)
	{
		if (!searchAndPrint(root, val))
			cout << "Value not found" << endl;
	}
	void searchAndPrintArea(string val)
	{
		Node* parent;
		Node* area = search(root, val, parent);
		if (area) print(root);
	}
	void printAllTree() { print(root); }
	string printToString(Node* p);
	string printToString() { return printToString(root); }
	void deleteSubTree(string val);
	void process() { process(root); }
};

