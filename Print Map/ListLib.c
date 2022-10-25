/* ListLib.c*/
/*Suraj Dhakal. 1001765507*/

#include "ListLib.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void  AddDrawCommandToList(char singlechar, char command[10], NODE** LinkedListHead)
{
    
	/* declare pointers of type NODE named TempPtr and NewNode */
    NODE *TempPtr, *NewNode;
	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */
	NewNode = malloc(sizeof(NewNode));
	NewNode->Letter = singlechar;
	NewNode->DrawCommand = malloc (strlen(command)+1);
	strcpy(NewNode->DrawCommand,command);
	NewNode->next_ptr =NULL;
	/* If the LinkedListHead is NULL, then give it the address of the new node */
	/* Else traverse to the end of the linked list and add the new node */
	if (*LinkedListHead == NULL)
	{
		*LinkedListHead = NewNode;
	}
	else 
	{
		TempPtr = *LinkedListHead;
		
		while (TempPtr->next_ptr != NULL)
		{
			TempPtr = TempPtr->next_ptr;
		}
		
		TempPtr->next_ptr = NewNode;
	}
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	NODE *TempPtr;
	TempPtr = LinkedListHead;
	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */
	while(TempPtr!=NULL && TempPtr->Letter != Letter)//(*Temptr).Letter
	{
		TempPtr = TempPtr->next_ptr;
	}

	if (TempPtr != NULL)
	{
		/* copy the DrawCommand from the node into the passed in parameter */
		/* return the next pointer stored in TempPtr */
		//DC = malloc(strlen(TempPtr->DrawCommand)+1);		
		strcpy(DC,TempPtr->DrawCommand);
		return TempPtr->next_ptr;
	}
	
	return TempPtr;
}
