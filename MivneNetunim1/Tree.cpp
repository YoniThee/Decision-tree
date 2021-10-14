//Shay Dopelt 208737981 && yehonatan Thee 209016393
#define _CRT_SECURE_NO_WARNINGS
#include"Tree.h"
#include"Node.h"
#include"Answer.h"
using namespace std;
Node* Tree::search(Node* p, string val, Node*& parent)
{
	return nullptr;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	if (searchQuestion(val, p))//if the question is in the tree
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tree::print(Node* p, int level)
{

	cout << p->value << endl;
	list<Answer*>::iterator iter = p->answersList.begin();
	for (int counter = 0; counter < p->answersList.size(); counter++) {
		Answer* temp = *iter;
		if (!p->isLeaf) {
			for (int j = 0; j < level; j++)
				cout << "\t";
			cout << temp->ans << " :" << endl;
			for (int i = 0; i < level + 1; i++)
				cout << "\t";
			level++;
			print(temp->son, level);
		}
		level = 0;
		iter++;
	}
}


void Tree::path(Node* p)
{

	cout << "=>" << p->value;
}
void Tree::process(Node* p) {
	cout << p->value << endl;//question or solution
	if (!p->isLeaf) {
		string newInput;
		cin >> newInput;//get from the user the way in the tree
		list<Answer*>::iterator iter = p->answersList.begin();
		for (int i = 0; i < p->answersList.size(); i++) {//search for the answer that user chose
			Answer* temp = *iter;
			if (temp->ans == newInput) {
				if (!temp->son->isLeaf)//if the user input if a new answer(new root)
					process(temp->son);
				else//the input is solution
					cout << temp->son->value << endl;
			}
		iter++;
		}
	
	}
}

Node* Tree::searchQuestion(string question, Node* ptr)
{

	if (!(ptr->value.compare(question)))//if we found the question
		return ptr;
	else {
		list<Answer*>::iterator iter = ptr->answersList.begin();//
		for (int counter = 0; counter < ptr->answersList.size(); counter++) {//check all the sons of this father and search the question
			Answer* temp = *iter;
			Node* test = searchQuestion(question, temp->son);//if the question is not in the tree continune scan the tree 
			if (test == nullptr)
				iter++;
			else //we found the node
				return test;
		}

	}
	return nullptr;//if the question is not in the tree
}

void Tree::deleteAllSubTree(Node* T)
{
	if (T->isLeaf)
		delete T;
	else {
		list<Answer*>::iterator iter = T->answersList.begin();
		for (int i = 0; i < T->answersList.size(); i++) {
			Answer* temp = *iter;
			if (temp->son->isLeaf)
				delete temp;
			else {
				deleteAllSubTree(temp->son);
			}
			iter++;
		}
	}
	T->isLeaf = true;
}

void Tree::addRoot(string newval)
{
	root = new Node(newval);//now the root is have value - the string
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* rootPtr = searchQuestion(fatherquestion, root);
	if (rootPtr != NULL) {//if the question is in the tree
		rootPtr->isLeaf = false; //now this root is have a son so he is not a leaf
		Node* possiboleAns = new Node(newval); //if the next level in the tree is answer and no more leaf
		Answer* possiboleQue = new Answer(newanswer, possiboleAns);//if the user input is new levl in the tree create a new Answer type
		rootPtr->answersList.push_back(possiboleQue);//the user input is in the list of posiibole answer of the root
		return true;
	}
	return false;
}

string Tree::printToString(Node* p)
{
	return string();
}

void Tree::deleteSubTree(string val)
{
	/*Node* tempPtr = searchQuestion(val, root);//find the node that have the string "val"
	if (tempPtr) {//if the question is in the tree
		if (tempPtr->isLeaf) //if the node is no have sons
			delete tempPtr;
		else {
			list<Answer*>::iterator iter = tempPtr->answersList.begin();
			for (int counter = 0; counter < tempPtr->answersList.size(); counter++) {//check all the sons and remove them
				Answer* temp = *iter;
				deleteSubTree(temp->son->value);//reqursive delete
				iter++;
			}
		}
	}*/
	Node* temp = searchQuestion(val, root);
	if(temp)//if the val is in the tree
		deleteAllSubTree(temp);
	/*list<Answer*>::iterator iter = root->answersList.begin();//
	for (int counter = 0; counter < root->answersList.size(); counter++)
	{
		Answer* temp = *iter;
		if (searchAndPrint(temp->son, val))
		{
			
			if (temp->son->value == val)
			{
				deleteAllSubTree(temp->son);
			}
			else
			{
				
			}
		}
	}*/
}
