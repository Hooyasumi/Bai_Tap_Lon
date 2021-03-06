#pragma once

#include <stdio.h>
#include "Node.h"

class Stack
{
private:
	Node* pHead;
public:
	Stack();
	~Stack();
	bool isEmpty();
	Node* createNode(Data x);
	void Push(Data x);
	bool Pop(Data& x);
	Node* getHead();
};