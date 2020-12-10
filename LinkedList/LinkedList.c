#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
==>>>           you can Not update here
*/


/**
 *  \brief Create New Node with Generic Data
 *  
 *  \param [in] Value Generic data used to store in Node
 *  \return Pointer Of Node
 *  
 *  \details Create New Node in Memory and return a pointer from this Node.
 */
Node* CreateNode(void* Value)
{
	Node* Temp = (Node*) malloc(sizeof(Node));
	if(Temp == NULL)
	{
		printf("LinkedList #CreateNode: No enough memory.");
        system("PAUSE");
        exit(0);
		return NULL;
	}
	Temp->Data = Value;
	Temp->Next = NULL;
	Temp->Prev = NULL;
	
	return Temp;
}


/**
 *  \brief Create New Linked List
 *  
 *  \return Pointer of LinkedList
 *  
 *  \details Create New LinkedList in Memory and Return pointer from this List
 */
LinkedList* CreateLinkedList()
{
	LinkedList* List = (LinkedList*) malloc(sizeof(LinkedList*));
	if(List == NULL)
	{
		printf("LinkedList #CreateLinkedList: No enough memory.");
        system("PAUSE");
        exit(0);
		return NULL;
	}
	List->Root = NULL;
	List->Tail = NULL;
	List->Size = 0;
	
	return List;
}


/**
 *  \brief Add New Node at The Front of the LinkedList.
 *  
 *  \param [in] List :Pointer of LinkedList
 *  \param [in] Data :Generic Data used to store
 *  \return : None
 *  
 *  \details : Add New Node to LinkedList
 */
void AddFirst(LinkedList* List ,void* Data)
{
	Node* NewNode = CreateNode(Data);
	if(NewNode == NULL)
	{
		printf("LinkedList #AddFirst: No enough memory.");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 0)
	{
		List->Root = NewNode;
		List->Root->Next = NULL;
		List->Root->Prev = NULL;
		List->Tail = List->Root;
	}
	else
	{
		NewNode->Next = List->Root;
		List->Root->Prev = NewNode;
		List->Root = NewNode;
	}
	List->Size ++;
}


/**
 *  \brief :Add new node at the end of the linkedlist
 *  
 *  \param [in] List :Pointer of linkedlist
 *  \param [in] Data :Generic data used to store
 *  \return :None
 *  
 *  \details :Add new node to linkedlist
 */
void AddLast(LinkedList* List ,void* Data)
{
	Node* NewNode = CreateNode(Data);
	if(NewNode == NULL)
	{
		printf("LinkedList #AddLast: No enough memory.");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 0)
	{
		List->Root = NewNode;
		List->Root->Next = NULL;
		List->Root->Prev = NULL;
		List->Tail = List->Root;
	}
	else
	{
		NewNode->Prev = List->Tail;
		List->Tail->Next = NewNode;
		List->Tail = NewNode;
	}
	List->Size ++;
}

/**
 *  \brief :Add new node at the index of the linkedlist
 *  
 *  \param [in] List :Pointer of linkedlist
 *  \param [in] Data :Generic data used to store
 *  \param [in] Position :Index of node this is used at linkedlist
 *  \return :None
 *  
 *  \details :Add New Node with Generic Data at the Index of the LinkedList.
 */
void AddAtPosition(LinkedList* List ,void* Data ,int Position)
{
	if(List->Size < Position || Position < 0)
	{
		printf("LinkedList #AddAtPosition: Index out of bound");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == Position)
	{
		AddLast(List,Data);
	}
	else if (Position == 0)
	{
		AddFirst(List,Data);
	}
	else
	{
		Node* NewNode = CreateNode(Data);
		if(NewNode == NULL)
		{
			printf("LinkedList #AddAtPosition: No enough memory.");
        	system("PAUSE");
        	exit(0);
		}
		int idx=1;
		
		Node* temp = List->Root;
		
		while(idx < Position)
		{
			idx++;
			temp = temp->Next;
		}
		
		NewNode->Next = temp->Next;
		NewNode->Prev = temp;
		temp->Next->Prev = NewNode;
		temp->Next = NewNode;
	}
	List->Size ++;
}

/**
 *  \brief :Prints out the LinkedList to the terminal window.
 *  
 *  \param [in] List :Pointer of linkedlist 
 *  \return :None
 *  
 *  \details :Prints out the LinkedList to the terminal window with O(n) complexity.
 */
void print(LinkedList *List)
{
	printf("%c", '{');

	Node *temp = List->Root;
	while (temp != NULL)
	{
		printf(" %d", temp->Data);
		if (temp->Next != NULL)
			printf("%c", ',');
		temp = temp->Next;
	}

	printf(" }\n");
}


/**
 *  \brief :remove first node from linkedlist
 *  
 *  \param [in] List :pointer of linkedlist
 *  \return :None
 *  
 *  \details :Delete Node at The Front of the LinkedList.
 */
void DeleteFirst(LinkedList* List)
{
	
	if(List->Size == 0)
	{
		printf("LinkedList #DeleteFirst: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 1)
	{
		free(List->Root);
		
		List->Root = NULL;
		List->Tail = NULL;
	}
	else
	{
		Node* temp = List->Root;
		List->Root = List->Root->Next;
		List->Root->Prev = NULL;
		free(temp);
	}
	List->Size --;
}

/**
 *  \brief :Delete The Last Node from linkedlist. 
 *  
 *  \param [in] List :pointer of linkedlist
 *  \return :None
 *  
 *  \details :Delete node at the end of the linkedlist.
 */
void DeleteLast(LinkedList* List)
{
	if(List->Size == 0)
	{
		printf("LinkedList #GetFirst: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 1)
	{
		free(List->Root);
		
		List->Root = NULL;
		List->Tail = NULL;
	}
	else
	{
		Node* temp = List->Tail;
		
		List->Tail = List->Tail->Prev;
		List->Tail->Next = NULL;
		
		free(temp);
	}
	List->Size --;
}


/**
 *  \brief :Delete's the first Node whose data matches the parameter, if it exists.
 *  
 *  \param [in] List :pointer of List
 *  \param [in] Data :we want to delete it 
 *  \return :None
 *  
 *  \details More details
 */
void DeleteValue(LinkedList* List , void* Data)
{
	if(List->Size == 0 )
	{
		printf("LinkedList #DeleteValue: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 1)
	{
		if(List->Root->Data == Data)
		{
			DeleteFirst(List);
		}
	}
	else
	{
		int idx=0;
		Node* temp = List->Root;
		while(temp != NULL)
		{
			if(temp->Data == Data)
			{
				temp->Next->Prev = temp->Prev;
				temp->Prev->Next = temp->Next;
				
				List->Size --;
				
				free(temp);
				return;
			}
			temp = temp->Next;
		}
		
	}
}


/**
 *  \brief :Delete Node From Any Position
 *  
 *  \param [in] List :pointer of List
 *  \param [in] Position :index used to delete specific node.
 *  \return :None
 *  
 *  \details More details
 */
void DeleteAtPosition(LinkedList* List ,int Position)
{
	if(List->Size == 0 )
	{
		printf("LinkedList #DeleteAtPosition: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else if(Position > List->Size)
	{
		printf("LinkedList #DeleteAtPosition: Index out of bound");
        system("PAUSE");
        exit(0);	
	}
	else if(List->Size == 1)
	{
		DeleteFirst(List);
	}
	else if(List->Size == Position) 
	{
		DeleteLast(List);
	}
	else
	{
		int idx=0;
		Node* temp = List->Root;
		while(idx < Position)
		{
			idx++;
			temp = temp->Next;
		}
		
		temp->Next->Prev = temp->Prev;
		temp->Prev->Next = temp->Next;
		
		free(temp);
	}
	List->Size --;
}


/**
 *  \brief :Get data of the first node of the linkedlist.
 *  
 *  \param [in] List :pointer of list.
 *  \return :poinetr of void
 *  
 *  \details More details
 */
void* GetFirst(LinkedList* List )
{
	if(List->Size == 0)
	{
		printf("LinkedList #GetFirst: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else
	{	
		return List->Root->Data;
	}
}


/**
 *  \brief :Get data of the last node of the linkedlist.
 *  
 *  \param [in] List :pointer of list.
 *  \return :poinetr of void
 *  
 *  \details More details
 */
void* GetLast(LinkedList* List)
{
	if(List->Size == 0)
	{
		printf("LinkedList#_remove: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else
	{	
		return List->Tail->Data;
	}
}


/**
 *  \brief :Get data of Node from specific position at the linkedlist.
 *  
 *  \param [in] List :pointer of list.
 *  \param [in] Position :index you want receive data from it.
 *  \return :pointer of void
 *  
 *  \details More details
 */
void* GetAtPosition(LinkedList* List ,int Position)
{
	if(List->Size == 0 )
	{
		printf("LinkedList #GetAtPosition: The list is empty.");
        system("PAUSE");
        exit(0);
	}
	else if(Position > List->Size)
	{
		printf("LinkedList #GetAtPosition: Index out of bound");
        system("PAUSE");
        exit(0);
	}
	else if(List->Size == 1)
	{
		return GetFirst(List);
	}
	else if(List->Size == Position) 
	{
		return GetLast(List);
	}
	else
	{
		int idx=0;
		Node* temp = List->Root;
		while(idx < Position)
		{
			idx++;
			temp = temp->Next;
		}
		return temp->Data;
	}
}


/**
 *  \brief :Prints out the LinkedList to the terminal window in the Forward form with O(n) complexity.
 *  
 *  \param [in] List :Pointer of linkedlist.
 *  \return :None.
 *  
 *  \details More details
 */
void DisplayForward(LinkedList* List)
{
	printf("%c", '{');

	Node *temp = List->Root;
	while (temp != NULL)
	{
		printf(" %d", temp->Data);
		if (temp->Next != NULL)
			printf("%c", ',');
		temp = temp->Next;
	}

	printf(" }\n");
}


/**
 *  \brief :Prints out the LinkedList to the terminal window in the backward form with O(n) complexity.
 *  
 *  \param [in] List :Pointer of linkedlist.
 *  \return :None.
 *  
 *  \details More details
 */
void DisplayBackward(LinkedList* List)
{
	printf("%c", '{');

	Node *temp = List->Tail;
	while (temp != NULL)
	{
		printf(" %d", temp->Data);
		if (temp->Prev != NULL)
			printf("%c", ',');
		temp = temp->Prev;
	}

	printf(" }\n");	
}


/**
 *  \brief :delete the linkedlist.
 *  
 *  \param [in] List :pointer of linkedlist.
 *  \return :None.
 *  
 *  \details More details
 */
void Clear(LinkedList* List)
{
	List->Root = NULL;
	List->Tail = NULL;
	List->Size = 0;
}


/**
 *  \brief :Copies a given LinkedList and returns the cloned version.
 *  
 *  \param [in] List :pointer of list.
 *  \return :pointer of list  or NULL.
 *  
 *  \details :Copies a given LinkedList and returns the cloned version with O(n) complexity.
 */
LinkedList* Clone(LinkedList* List)
{
	if (List == NULL)
	{
		return NULL;
	}
	
	LinkedList *copy = CreateLinkedList();
	Node *temp = List->Root;

	while (temp != NULL)
	{
		AddLast(copy, temp->Data);
		temp = temp->Next;
	}

	return copy;
}


/**
 *  \brief :Search about specific item
 *  
 *  \param [in] List :pointer of list
 *  \param [in] data :data whose search about it. 
 *  \return :index of data or -1 -> data not found.
 *  
 *  \details More details
 */
int Search(LinkedList* List ,void* data)
{
	if(List->Size == 0 )
	{
		printf("LinkedList #Search: The list is empty.");
		return -1;
	}
	else if(List->Size == 1)
	{
		return (List->Root->Data == data )?0:-1;
	}
	else
	{
		int idx=0;
		Node* temp = List->Root;
		while(temp->Next != NULL)
		{
			if(temp->Data == data)
			{
				return idx;
			}
			idx++;
			temp = temp->Next;
		}
		free(temp);
	}
}


/**
 *  \brief :Return node at the index of linkedlist
 *  
 *  \param [in] List :pointer of linkedlist
 *  \param [in] Index :used to return node
 *  \return :pointer of Node or NULL
 *  
 *  \details :Find specific Node based upon Index
 */
Node* Find(LinkedList* List ,int Index)
{
	if(List->Size == 0 )
	{
		printf("LinkedList #Find: The list is empty.");
        return NULL;
	}
	else if(Index > List->Size)
	{
		printf("LinkedList #Find: Index out of bound");
        return NULL;
	}
	else if(Index == 0)
	{
		return List->Root;
	}
	else if(List->Size == Index) 
	{
		return List->Tail;
	}
	else
	{
		int idx=0;
		Node* temp = List->Root;
		while(idx < Index)
		{
			idx++;
			temp = temp->Next;
		}
		return temp;
	}
}


/**
 *  \brief :Return Size Of Linked List.
 *  
 *  \param [in] List :pointer of list.
 *  \return :size of list
 *  
 *  \details More details
 */
int Size(LinkedList* List)
{
	return List->Size;
}


/**
 *  \brief :Check if Linked List is Empty or Not.
 *  
 *  \param [in] List :Pointer of LinkedList.
 *  \return :0 -> Not Empty and 1 -> Empty. 
 *  
 *  \details More details
 */
int IsEmpty(LinkedList* List)
{
	return (List->Size == 0);	
}






