// FileLib.c
//Suraj Dhakal . 1001765507

#include <stdio.h>
#include <string.h>
#include "ListLib.h"
#include <ctype.h>
#include <stdlib.h>


FILE *OpenFile(int argc, char *argv[])
{	
	/* declare various variables needed */
	int max =1000;
	char File_Name[max];
	FILE *read =NULL;

	/* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
	if (argc >=2)
	{
		strcpy(File_Name,argv[1]);
	}
	
	else 
	{
		printf("\nMust be run with an input file name.\n\nEnter a file name at the prompt: ");
		fgets(File_Name , max-1, stdin);
		File_Name[strlen(File_Name)-1] ='\0';
	}

	do
	{
		/* open file with "r" mode */
		read = fopen(File_Name,"r");
		/* if file did not open */
		if (read == NULL)
		{
			/* print message seen in sample output */
			printf("\nCould not open input file named %s\n",File_Name);
			/* read in new filename */
			printf("\nEnter a file name at the prompt: ");
			scanf("%s",File_Name);
			printf("\n");
			/* open the file "r" mode */
			read = fopen(File_Name,"r");
		}
	}
	while (read == NULL);
	return read;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	/* declare various variables needed */
	char letter;
	char *drawcommand;
	int maxsize =1000;
	char check[maxsize];
	char *Token;
	/* while fgets() reads the file */
	while(fgets(check,maxsize-1,DCFile) !=NULL)
	{
		/* if line from file ends with \n, then replace \n with \0 */
		if (check[strlen(check)-1] == '\n')
		{
			check[strlen(check)-1] = '\0';
		}
		
		/* tokenize to get the Letter and the DrawCommand */
		Token =strtok (check,"|");
		letter = *Token;
		Token = strtok(NULL,"|");
		drawcommand = malloc (strlen(Token)*sizeof(char));
		strcpy(drawcommand, Token);
	
		/* Call AddDrawCommandToList with correct parameters */
		AddDrawCommandToList(letter,drawcommand,LinkedListHead);
	}
	
}
