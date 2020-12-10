#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


/*
==>>>           you can update here
*/

int main()
{
	int idx=0;
	
	LinkedList* List = CreateLinkedList();
	
	AddFirst(List ,((int*)1));
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	AddLast(List ,(int*)2);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	AddAtPosition(List ,(int*)3 ,1);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	AddAtPosition(List ,(int*)4 ,2);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	AddAtPosition(List ,(int*)5 ,2);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	int *ReturnValue = NULL;
	
	ReturnValue = (int*) GetFirst(List);
	printf("Val1:%d \n",ReturnValue);

	ReturnValue = (int*) GetLast(List);
	printf("Val2:%d \n",ReturnValue);

	ReturnValue = (int*) GetAtPosition(List ,3);
	printf("Val3:%d \n",ReturnValue);
	
	DeleteAtPosition(List ,2);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	DeleteFirst(List);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	DeleteLast(List);
	printf("SZ%d:%d \n",++idx,List->Size);
	printf("=================================\n");
	print(List);
	printf("=================================\n");
	
	
	
	
	return 0;
}