#pragma once
#include <iostream>
#include <list>
#include <string>
#include"Node.h"
#include"Answer.h"
using namespace std;
//Tree: the Decision Tree
class Tree
{
	Node* root;
	Node* search(Node* p, string val, Node*& );
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
	Node* searchQuestion(string father, Node* ptr);//this function find the root that have the father we search
	void deleteAllSubTree(Node* t);
	void addRoot(string newval);
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val)
	{
		if (!searchQuestion(val, root))//if the string is not in the tree
			cout << "Value not found" << endl;
		else {//print the path from the leaf up to the root
	
			Tree y;
			


			list<Answer*>::iterator iter = root->answersList.begin();//
			for (int counter = 0; counter < root->answersList.size(); counter++)
			{
				Answer* temp = *iter;
				if (searchAndPrint( temp->son,val))
				{
					if ( temp->son->value == val)
					{
						cout << temp->son->value ;
					}
					else
					{
						y.root= temp->son;
						y.searchAndPrint(val);
						
						process(y.root);
					}


				}
			}


		}

		/*
		n
		me
		s
		me
		a
		b
		s
		b
		c
		d
		s
		d
		e
		f
		*/
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

