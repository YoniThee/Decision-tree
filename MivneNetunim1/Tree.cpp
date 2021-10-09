#include"Tree.h"
#include"Node.h"
#include"Answer.h"
#include<conio.h>
using namespace std;
Node* Tree::search(Node* p, string val, Node*& parent)
{
	return nullptr;
}

Node* Tree::searchQuestion(string question, Node* ptr)
{
	if (!(ptr->value.compare(question)))//if we found the question
		return ptr;
	else {
		list<Answer*>::iterator iter = ptr->answersList.begin();//
		for (; iter != ptr->answersList.end(); iter++) {//check all the sons of this father and search the question
			Answer *temp = *iter;
			searchQuestion(question, temp->son);
		}
	}
	return nullptr;//if the question is not in the tree
}

void Tree::addRoot(string newval)
{
	root->value = newval;//now the root is have value - the string
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* rootPtr = searchQuestion(fatherquestion,root);
	if (rootPtr != NULL) {//if the question is in the tree
		rootPtr->isLeaf = false; //now this root is have a son so he is not a leaf
		Node* possiboleAns = new Node(newval); //if the next levl in the tree is answer and no more leaf
		Answer* posiboleQue = new Answer(newanswer, possiboleAns);//if the user input is new levl in the tree create a new Answer type
		rootPtr->answersList.push_back(posiboleQue);//the user input is in the list of posiibole answer of the root
		return true;
	}
	return false;
}
