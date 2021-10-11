#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"
#include"Node.h"
#include"Answer.h"
#include<conio.h>
using namespace std;
Node* Tree::search(Node* p, string val, Node*& parent)
{	
	return nullptr;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	return false;
}

void Tree::print(Node* p, int level)
{
/*
	cout << p->value;
	if (p->answersList)
	{
		
	}
	Node* tempPtr = p;
	list<Answer*>::iterator iter = tempPtr->answersList.begin();
	*/

}

void Tree::process(Node* p)
{
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

void Tree::deleteAllSubTree(Node* t)
{
}

void Tree::addRoot(string newval)
{
	root = new Node(newval);//now the root is have value - the string
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* rootPtr = searchQuestion(fatherquestion,root);
	if (rootPtr != NULL) {//if the question is in the tree
		rootPtr->isLeaf = false; //now this root is have a son so he is not a leaf
		Node* possiboleAns = new Node(newval); //if the next level in the tree is answer and no more leaf
		Answer* posiboleQue = new Answer(newanswer, possiboleAns);//if the user input is new levl in the tree create a new Answer type
		rootPtr->answersList.push_back(posiboleQue);//the user input is in the list of posiibole answer of the root
		return true;
	}
	return false;
}

string Tree::printToString(Node* p)
{
	return string();
}

void Tree::deleteSubTree(string val)
{//מה שעשיתי פה זה שקיבלתי מצביע לצומת הרצויה, 
//אם אין לו בנים אחלה סיימנו, אם יש לו בנים אז אני רץ עם איטרטור על כל הבנים שלו ושולח אותם לאותו סינון  בדיוק ברקורסיה
//מה שגורם לי בסוף למחיקה של כל העץ - מחכה שתאשר לי

	//מטורף ש'ך :)
	Node* tempPtr = searchQuestion(val,root);//find the node that have the string "val"
	if (tempPtr->isLeaf) //if the node is no have sons
		delete tempPtr;
	else {
		list<Answer*>::iterator iter = tempPtr->answersList.begin();
		for (; iter != tempPtr->answersList.end(); iter++) {//check all the sons and remove them
			Answer* temp = *iter;
			deleteSubTree(temp->ans);//reqursive delete
		}
	}



}
