#include "Stack.h"

Stack::Stack()
{
	pHead = NULL;
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		Node* p = pHead;
		pHead = p->pNext;
		delete p;
	}
}

bool Stack::isEmpty()
{
	if (pHead == NULL)
		return true;
	return false;
}

Node* Stack::createNode(Data x)
{
	Node* p = new Node();
	p->Info = x;
	p->pNext = NULL;
	return p;
}

void Stack::Push(Data x)
{
	Node* p = createNode(x);
	if (isEmpty())
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead;
		pHead = p;
	}
}

bool Stack::Pop(Data& x)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node* p = pHead;
		x = p->Info;
		pHead = p->pNext;
		delete p;
	}
	return true;
}

Node* Stack::getHead()
{
	return pHead;
}
