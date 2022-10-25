//Suraj Dhakal
//ASCII drawing tool

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "DrawTool.h"

//start of main
int main(void)
{
	
	char TableArray[MAXMAPSIZE][MAXMAPSIZE]={};
	int Usersize = 0;

	//calling function InitializeMap from DrawTool
	InitializeMap(TableArray,&Usersize);
	getchar();

	//calling function PrintInstructions from DrawTool
	PrintInstructions();

	//calling function PrintMap from DrawTool
	PrintMap(TableArray,Usersize);
	
	int loopContinue = 1;

	while (loopContinue)
	{
		int DrawCommandSize =100;
		char Buffer[DrawCommandSize];
		//prompting for a draw command 
		printf("Enter draw command (enter Q to quit):");
		//getting user input 
		fgets(Buffer,DrawCommandSize-1,stdin);
		char *Delimiters = "(),";
		char *Token = NULL;
		
		if (Buffer[0] != 'q' && Buffer[0] != 'Q') 
		{
			Token = strtok(Buffer,Delimiters);
			char command = *Token;
			Token = strtok(NULL,Delimiters);
			int Row = atoi(Token);
			Token = strtok (NULL,Delimiters);
			int Column = atoi(Token);
			Token = strtok (NULL,Delimiters);
			int Count = atoi (Token);
			Token = strtok (NULL,Delimiters);
			char Mark = *Token;
		
			
			if(Mark == '\n')
			{
			   Mark = 'X';
			}	   

			command = toupper(command);
			
			if (command == 'P')
			{
				if (Row<Usersize && Column<Usersize && Row >=0 && Column>=0)
				{
					*(*(TableArray + Row)+Column)= Mark;
				}
				else
				{
					printf("That draw command is out of range");
				}
			}
			else if (command == 'V')
			{
				if ((Count + Row) <= (Usersize) && Count > 0 && Row >= 0 && Column >= 0 && Column < Usersize && Row < Usersize)
				{
					DrawLine(TableArray,Row,Column,command,Count,Mark);
				}
				else 
				{
					printf("That draw command is out of range");
				}
			}
			else if (command == 'H')
			{
				if ((Count + Column) <= (Usersize) && Count > 0 && Row >= 0 && Column >= 0 && Column < Usersize && Row < Usersize)
				{
					DrawLine(TableArray,Row,Column,command,Count,Mark);
				}
				else 
				{
					printf("That draw command is out of range");
				}
			}
			else 
			{
				printf("That draw command is unknown");
			}	
		
			PrintMap(TableArray,Usersize);
		}
		else
		{
			loopContinue=0;
		}
	    
	}			
	//end of main
	return 0;
}