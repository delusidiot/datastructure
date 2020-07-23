#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"

int main(int argc, char* argv[])
{
	ArrayList* pList = NULL;
	ArrayListNode * pValue = NULL;

	pList = createArrayList();
	if (pList != NULL)
	{
		ArrayListNode node;

		node.data = 1;
		addArrayListElement(pList, 0, node);
		node.data = 3;
		addArrayListElement(pList, 1, node);

		node.data = 5;
		addArrayListElement(pList, 1, node);

		node.data = 7;
		addArrayListElement(pList, 1, node);

		node.data = 9;
		addArrayListElement(pList, 1, node);

		node.data = 10;
		addArrayListElement(pList, 1, node);

		node.data = 11;
		addArrayListElement(pList, 1, node);

		node.data = 12;
		addArrayListElement(pList, 1, node);
		node.data = 13;
		addArrayListElement(pList, 1, node);
		node.data = 14;
		addArrayListElement(pList, 1, node);
		node.data = 15;
		addArrayListElement(pList, 1, node);
		node.data = 16;
		addArrayListLast(pList, node);
		node.data = 0;
		addArrayListFirst(pList, node);
		displayArrayList(pList);


		removeArrayListElement(pList, 0);
		displayArrayList(pList);

		int arrayCount = getArrayListLength(pList);
		for (int i = 0; i < arrayCount; i++)
		{
			pValue = getArrayListElement(pList, i);
			printf("position[%d]-%d\n", i, pValue->data);
		}
		deleteArrayList(pList);
	}
	return 0;
}