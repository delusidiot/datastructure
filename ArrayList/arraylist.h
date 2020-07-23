#pragma once

#define TRUE 1
#define FALSE 0

#define NEXT_ARRAY_LENGTH 10

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement;
} ArrayList;

ArrayList* createArrayList();
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addArrayListElement(ArrayList* pList, int position, ArrayListNode element);
int removeArrayListElement(ArrayList* pList, int position);
ArrayListNode* getArrayListElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
int addArrayListFirst(ArrayList* pList, ArrayListNode element);
int addArrayListLast(ArrayList* pList, ArrayListNode element);