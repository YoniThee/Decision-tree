#pragma once
#include"Node.h"
#include<iostream>
#include<string>
using namespace std;
//Answer: for each answer, the string, and the pointer to the node where to continue
class Node;
class Answer
{
public:
	Answer(string s, Node* p) { ans = s; son = p; }
	string ans;
	Node* son;
	friend class Tree;
};