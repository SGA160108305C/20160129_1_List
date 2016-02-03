#include <stdio.h>
#include <string>

#include "LinkedList.h"

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{

}

void LinkedList::Insert(int number)
{
	//맨 마지막에 추가한다.
	Node* node = new Node();
	node->data = number;
	node->next = nullptr;

	if (head != nullptr)
	{
		Node* tail = GetTail();
		tail->next = node;
	}
	else
	{
		head = node;
	}
}

Node* LinkedList::GetTail()
{
	Node* tail = head;
	while (tail != nullptr
		&& tail->next != nullptr)
	{
		tail = tail->next;
	}

	return tail;
}

void LinkedList::DeleteToPosition(int pos)
{
	Node* target = head;
	Node* prev = nullptr;
	int index = 0;
	while (index < pos)
	{
		if (target == nullptr)
		{
			break;
		}
		else
		{
			prev = target;
			target = target->next;
		}
		index++;
	}

	if (index == pos)
	{
		if (prev != nullptr)
		{
			prev->next = target->next;
		}
		else
		{
			head = target->next;
		}
		delete target;
		target = nullptr;

	}
}

void LinkedList::DeleteToData(int data)
{
	Node* target = head;
	Node* prev = nullptr;

	while (target != nullptr)
	{
		if (target->data == data)
		{
			if (prev != nullptr)
			{
				prev->next = target->next;
			}
			else
			{
				head = target->next;
			}
			delete target;
			target = nullptr;
			return;
		}
		prev = target;
		target = target->next;
	}
}

void LinkedList::Print()
{
	printf_s("List Print---------\n");
	Node* node = head;
	while (node != nullptr)
	{
		printf_s("%d -> ", node->data);
		node = node->next;
	}
	printf_s("End\n\n");
}

void LinkedList::DeleteAll()
{
	while (head != nullptr)
	{
		Node* target = head;
		head = head->next;

		delete target;
		target = nullptr;
	}
}

void LinkedList::ParseLine(char* line)
{
	char delim[] = " :;,\t\n";
	char* token = NULL;
	char* next_token = NULL;

	token = strtok_s(line, delim, &next_token);

	commandType command;
	if (strcmp(token, "i") == 0) command = i;
	else if (strcmp(token, "p") == 0) command = p;
	else if (strcmp(token, "dp") == 0) command = dp;
	else if (strcmp(token, "dd") == 0) command = dd;

	while (token != NULL)
	{
		token = strtok_s(NULL, delim, &next_token);

		switch (command)
		{
		case i:
			if (token != NULL)
			{
				int num = std::stoi(token);
				printf_s("Insert(%d)\n", num);
				Insert(num);
				Print();
			}

			break;

		case p:
			printf_s("Print()\n");
			Print();

			break;

		case dp:
			if (token != NULL)
			{
				int num = std::stoi(token);
				printf_s("DeleteToPosition(%d)\n", num);
				DeleteToPosition(num);
				Print();
			}

			break;

		case dd:
			if (token != NULL)
			{
				int num = std::stoi(token);
				printf_s("DeleteToData(%d)\n", num);
				DeleteToData(num);
				Print();
			}

			break;

		default:
			break;
		}

	}
}