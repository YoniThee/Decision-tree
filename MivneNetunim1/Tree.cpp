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
	/*//למה זה בוליאני??
	//זה לא הפונ הדפסה שרוצים ב-p
	//זה מגיע לפונ בשורה 28
	if (p->value == val) {
		return true;
	}
	else {//scan all the sons for search "val"
		list<Answer*>::iterator iter = p->answersList.begin();
		for (int counter = 0; counter < p->answersList.size(); counter++) {

			iter++;
		}
	}*/
	if (searchQuestion(val,p))//if the question is in the tree
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
	for (int i = 0; i < level; i++){
		cout << "\t";
	}
		cout << p->value << endl;
		list<Answer*>::iterator iter = p->answersList.begin();
		for (int counter = 0; counter < p->answersList.size(); counter++) {
			Answer* temp = *iter;
			if (!p->isLeaf) {
				cout  << temp->ans << " :" << endl << "\t";
				print(temp->son,level++);
			}
			iter++;
		}
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
		for (int counter = 0; counter < ptr->answersList.size(); counter++) {//check all the sons of this father and search the question
			Answer* temp = *iter;
			if(!searchQuestion(question, temp->son))//if the question is not in the tree continune scan the tree 
			iter++;
			else //we fount the node
				return temp->son;
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
	Node* rootPtr = searchQuestion(fatherquestion, root);
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
	Node* tempPtr = searchQuestion(val, root);//find the node that have the string "val"
	if (tempPtr->isLeaf) //if the node is no have sons
		delete tempPtr;
	else {
		list<Answer*>::iterator iter = tempPtr->answersList.begin();
		for (int counter = 0; counter < tempPtr->answersList.size(); counter++) {//check all the sons and remove them
			Answer* temp = *iter;
			deleteSubTree(temp->ans);//reqursive delete
			iter++;
		}
	}



}
