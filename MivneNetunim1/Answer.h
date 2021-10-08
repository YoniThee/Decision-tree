#pragma once
#include"Node.h"
#include<iostream>
#include<string>
using namespace std;
//Answer: for each answer, the string, and the pointer to the node where to continue
class Answer
{
public:
	string ans;
	Node* son;
	Answer(string s, Node* p) { ans = s; son = p; }
	Answer() {}
};