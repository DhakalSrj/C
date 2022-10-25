//Suraj Dhakal

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "DrawTool.h"
#include "FileLib.h"
#include "ListLib.h"



//start of main
int main(int argc, char *argv[])
{
    NODE *LinkedListHead = NULL;
	NODE *TempPtr,*NewNode;
	char draw[15];
	char input[10];
	char TableArray[MAXMAPSIZE][MAXMAPSIZE]={};
	char *Delimiters = "(),";
	char *Token = NULL;
	//calling OpenFilefuction
	FILE *FH = OpenFile(argc,argv);
	//calling Function ReadFileIntoLinkedList 
	ReadFileIntoLinkedList(FH,&LinkedListHead);
	//calling function InitializeMap from DrawTool
	InitializeMap(TableArray);

	//prompting for upto 3 letters
	do
	{
		printf("\nPlease enter 1-3 letters: ");
		scanf("%s",input);
	}
	while (strlen(input)<=0 || strlen(input) > 3);
		
	for(int i=0;i<strlen(input);i++)
	{
		input[i]=toupper(input[i]);
		
		
		// Traversing the Linkedlist 
		TempPtr = LinkedListHead;
		
		while (TempPtr != NULL)
		{
			draw[0]='\0';
			TempPtr = FindLetter(TempPtr,input[i],draw);
			if(draw[0] != '\0')
			{
				Token = strtok(draw,Delimiters);
				char command = *Token;
				Token = strtok(NULL,Delimiters);
				int Row = atoi(Token);
				Token = strtok (NULL,Delimiters);
				int Column = atoi(Token);
				Token = strtok (NULL,Delimiters);
				int Count = atoi (Token);
				Token = strtok (NULL,Delimiters);
				char Mark = *Token;
				
				if (i==1)
				{
					Column +=7;
				}
				else if (i==2)
				{
					Column +=14;
				}
				
				command = toupper(command);
				
				if (Row <= MAXMAPSIZE && Column <= MAXMAPSIZE && Count <= MAXMAPSIZE)
				{
					DrawLine(TableArray, Row, Column, command, Count, Mark);
				}
				else 
				{
					printf("The draw command %s is unknown.\n",draw);
					draw[0] = '\0';
					TempPtr = NULL;
				}		
			}		
		}
	}
	//calling function PrintMap from DrawTool
	PrintMap(TableArray);
	//close file 
	fclose(FH);	

	//end of main
	return 0;
}