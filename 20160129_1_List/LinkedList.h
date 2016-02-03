#pragma once

#include "Node.h"

class LinkedList
{
public:
	enum commandType
	{
		i, p, dp, dd
	};

	LinkedList();
	~LinkedList();

	void Insert(int number);
	void DeleteToPosition(int pos);
	void DeleteToData(int data);
	void Print();

	void DeleteAll();
	void ParseLine(char* line);

private:
	Node* head = nullptr;//마지막은 tail

	Node* GetTail();
};