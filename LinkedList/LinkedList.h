#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/*
==>>>           you can Not update here
*/

typedef struct Node{
	void* Data;
	struct Node* Next;
	struct Node* Prev;
}Node;

typedef struct LinkedList{
	Node* Root;
	Node* Tail;
	int Size;
}LinkedList;



Node* CreateNode(void* Value);
LinkedList* CreateLinkedList();

void AddFirst(LinkedList* List ,void* Data);
void AddLast(LinkedList* List ,void* Data);
void AddAtPosition(LinkedList* List ,void* Data ,int Position);

void print(LinkedList *list);
void DisplayForward(LinkedList* List);
void DisplayBackward(LinkedList* List);

void DeleteFirst(LinkedList* List);
void DeleteLast(LinkedList* List);
void DeleteValue(LinkedList* List , void* Data);
void DeleteAtPosition(LinkedList* List ,int Position);

void* GetFirst(LinkedList* List);
void* GetLast(LinkedList* List );
void* GetAtPosition(LinkedList* List ,int Position);

void Clear(LinkedList* List);
LinkedList* Clone(LinkedList* List);

int Search(LinkedList* List ,void* data);
Node* Find(LinkedList* List ,int Index);

int Size(LinkedList* List);
int IsEmpty(LinkedList* List);


#endif