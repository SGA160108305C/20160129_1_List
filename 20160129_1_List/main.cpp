#include <stdio.h>
#include "LinkedList.h"

void main()
{
	LinkedList list;
	list.Insert(10);
	list.Insert(50);
	list.Insert(20);
	list.Insert(70);
	list.Insert(30);
	list.Print();

	list.DeleteToPosition(3);
	list.Print();

	list.DeleteToData(10);
	list.Print();

	list.DeleteAll();
	list.Print();

	FILE* fp = nullptr;
	fopen_s(&fp, "data.txt", "r");
	char line[256];
	if (fp != nullptr)
	{
		while (
			fgets(line, 256, fp) != nullptr)
		{
			printf_s("line : %s", line);
			list.ParseLine(line);
		}
	}

	getchar();
}