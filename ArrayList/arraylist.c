#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList()
{
	ArrayList* pReturn = NULL;

	pReturn = (ArrayList*)malloc(sizeof(ArrayList));
	if (pReturn != NULL)
	{
		pReturn->maxElementCount = NEXT_ARRAY_LENGTH;
		pReturn->currentElementCount = 0;
		pReturn->pElement = NULL;
	}
	else
	{
		printf("error, Memory allocation [ createArrayList ] \n");
	}

	if (pReturn != NULL) {
		pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * NEXT_ARRAY_LENGTH);
		if (pReturn->pElement == NULL)
		{
			printf("error, memory allocation [ createArrayList ] \n");
			free(pReturn);
			return NULL;
		}
		memset(pReturn->pElement, 0, sizeof(ArrayListNode) * NEXT_ARRAY_LENGTH);
	}
	return pReturn;
}

void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}
int isArrayListFull(ArrayList* pList)
{
	int ret = FALSE;
	if (pList != NULL)
	{
		if (pList->currentElementCount == pList->maxElementCount)
		{
			ret = TRUE;
		}
	}
	return ret;
}
int addArrayListElement(ArrayList* pList, int position, ArrayListNode element)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (isArrayListFull(pList) == TRUE)
		{
			ArrayListNode* temp = (ArrayListNode*)malloc((sizeof(ArrayListNode) * pList->maxElementCount) + (sizeof(ArrayListNode) * NEXT_ARRAY_LENGTH));
			if (temp != NULL) {
				pList->maxElementCount += NEXT_ARRAY_LENGTH;
				memcpy(temp, pList->pElement, sizeof(ArrayListNode) * pList->maxElementCount);
				free(pList->pElement);
				pList->pElement = temp;
				printf("Rise Array [ addArrayListElement ]\n");
			}
			else {
				ret = TRUE;
				printf("Error, Rise Error [ addArrayListElement ]\n ");
			}
			
		}
		if (position >= 0 && position <= pList->currentElementCount && ret != TRUE)
		{
			for (int i = pList->currentElementCount - 1; i >= position; i--)
			{
				pList->pElement[i + 1] = pList->pElement[i];
			}
			pList->pElement[position] = element;
			pList->currentElementCount++;
			ret = TRUE;
		}
		else
		{
			ret = FALSE;
			printf("error, position index-[%d] out of range [ addArrayListElement ]\n", position);
		}
	}
	return ret;
}
int removeArrayListElement(ArrayList* pList, int position)
{
	int ret = FALSE;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			for (int i = position; i < pList->currentElementCount - 1; i++)
			{
				pList->pElement[i] = pList->pElement[i + 1];
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			printf("error, position index-[%d] out of range [ removeArrayListElement ]\n", position);
		}
	}
	return ret;
}
ArrayListNode* getArrayListElement(ArrayList* pList, int position)
{
	ArrayListNode* pReturn = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < getArrayListLength(pList))
		{
			pReturn = &(pList->pElement[position]);
		}
		else
		{
			printf("error, position index-[%d] out of range [ getArrayListElement ]\n", position);
		}
	}
	return pReturn;
}
void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("max element count : %d\n", pList->maxElementCount);
		printf("curunt element count : %d\n", pList->currentElementCount);
		for (int i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d], [%d]\n", i, getArrayListElement(pList, i)->data);
		}
		for (int i = pList->currentElementCount; i < pList->maxElementCount; i++)
		{
			printf("[%d], Empty\n", i);
		}
	}
	else
	{
		printf("ArrayList is NULL\n");
	}
}
void clearArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		pList->currentElementCount = 0;
	}
	else
	{
		printf("error, List is NULL\n");
	}
}
int getArrayListLength(ArrayList* pList)
{
	int ret = 0;
	if (pList != NULL)
	{
		ret = pList->currentElementCount;
	}
	return ret;
}
int addArrayListFirst(ArrayList* pList, ArrayListNode element)
{
	int ret = FALSE;
	int position = 0;
	if (pList != NULL)
	{
		ret = addArrayListElement(pList, position, element);
	}
	return ret;
}

int addArrayListLast(ArrayList* pList, ArrayListNode element)
{
	int ret = FALSE;
	int position = 0;
	if (pList != NULL)
	{
		position = getArrayListLength(pList);
		ret = addArrayListElement(pList, position, element);
	}
	return ret;
}