//Suraj Dhakal
//1001766507
//Bingo Game

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


//function prototypes
void BingoNum(int column[5][5]);
void FillBingoCard(int BingoArray[5][5]);
int PickNumber(int pickedNumber[],int totalNoPicked);
void printPickedNumber (int num);
bool checkNumber(int array[5][5], int num);
bool checkRow(int array[5][5]);
bool checkColumn(int array[5][5]);
bool checkDiagonal(int array[5][5]);

//function to generate random numbers for each required column range
void BingoNum(int column[5][5])
{
	srand(time(0));
	int i,j;
	int count;
	int generatedNumber[5];
	for (j = 0; j < 5; j++)
	{
	    count = 0;
    	while(count < 5)
    	{
    	    int num;
    	    int isPresent;
    	    isPresent = 0;
			//generates random number
			//1-15  for 1st column
			//16-30 for 2nd column
			//31-45 for 3rd column
			//46-60 for 4th column
			//61-75 for 5th column
    	    num = (rand()%15) + ((15*j) + 1);
    	    if (count == 0)
			{
    	        generatedNumber[count] = num;
    	        count++;
    	    }
    	    else
			{
    	        for (i = 0; i < count; i++)
    	        {
    	            if (generatedNumber[i] == num)
					{
    	                isPresent = 1;
    	            }
    	        }
    	        if (isPresent == 0)
    	        {
    	            generatedNumber[count] = num;
    	            count++;
    	        }
    	    }
    	}
    	for (i=0;i<5;i++)
    	{
    	    column[i][j] = generatedNumber[i];
    	    if (i == 2 && j == 2 )
    	    {
    	       column[i][j] = 0;
    	    }
    	}
	}
}
//function to print the table format and fill the random numbers in each array
void FillBingoCard(int BingoArray[5][5])
{
	int i,j,k;
	//print heading column
	printf("\tB\t\tI\t\tN\t\tG\t\tO\n");
	for(i=0;i<=80;i++)
	{
		printf("-");
	}
	printf("\n");
	//print rows
	for (j = 0; j < 5; j++)
	{
		for (k = 0; k < 5; k++)
		{
			if (BingoArray[j][k] == 0)
			{
			    printf("|\tX\t");
			}
			else
			{
				printf("|\t%d\t",BingoArray[j][k]);
			}
		}
		//prints the divider for each row
		printf("|\n");
		for(i=0;i<=80;i++)
		{
			printf("-");
		}
		printf("\n");
	}
}
//function to generate random numbers ranging 1-75 to check if it exists in the Bingo Card
int PickNumber(int pickedNumber[],int totalNoPicked)
{
    int numFound = 0;
    int num, i;
    while(numFound == 0)
	{
        int unique = 1;
        num = (rand()%75) + 1;
        for (i = 0; i < totalNoPicked; i++)
        {
            if (pickedNumber[i] == num)
            {
               unique = 0;
            }
        }
        if (unique == 1)
		{
            numFound = 1;
        }
    }
    pickedNumber[totalNoPicked] = num;
    return num;
}
//function to print each letter associated with each number with respect to the column of the Bingo Card
void printPickedNumber(int num)
{
    printf("\n");
    if (num < 16)
    {
        printf("The next number is B%d\n", num);
    }
    else if (num < 31)
    {
        printf("The next number is I%d\n", num);
    }
    else if (num < 46)
    {
        printf("The next number is N%d\n", num);
    }
    else if (num < 61)
    {
        printf("The next number is G%d\n", num);
    }
    else{
        printf("The next number is O%d\n", num);
    }
}
// function to check if the random number exists in the Bingo card
//And if it does it fills it with 0
bool checkNumber(int array[5][5], int num)
{
    int i, j;
    bool isPresent = false;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (array[i][j] == num)
            {
                array[i][j] = 0;
                isPresent = true;
            }
        }
    }
    return isPresent;
}
// function to check if any row has been completed in the Bingo Card
bool checkRow(int array[5][5])
{
    bool isBingo = false;
    int i, j;
    int count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (array[i][j] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            isBingo = true;
        }
    }
    return isBingo;
}
//function to check if any column has been completed in the Bingo Card
bool checkColumn(int array[5][5])
{
    bool isBingo = false;
    int i, j;
    int count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (array[j][i] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            isBingo = true;
        }
    }
    return isBingo;
}
// function to check if either diagonals has been completed in the Bingo Card
bool checkDiagonal(int array[5][5])
{
    bool isBingo = false;
    int i,j,k;
    int countLR=0, countRL=0 ;
    for (i=0,j=0,k=4;i<5,j<5,k>=0;i++,j++,k--)
    {
		if(i!=2 && j!=2 && k!=2)
		{
            if (array[i][j]== 0)
            {
                countLR++;
            }
            if(array[k][i]==0)
            {
                countRL++;
            }
            if (countLR == 4 || countRL == 4)
            {
                isBingo =true;
            }
		}
    }
    return isBingo;
}
//start of main
int main(void)
{
    int Bingo[5][5]={};
    int totalNoPicked = 0;
    int pickedNumber[75];
    char isPresent;
    int yourNumber;
    BingoNum(Bingo);
    bool isBingo = false;
	//loop for the Bingo Card to be played until the players gets a row, a column or a diagonal
    while(!isBingo)
    {
        FillBingoCard(Bingo);
        yourNumber = PickNumber(pickedNumber,totalNoPicked);
        totalNoPicked++;

        printPickedNumber(yourNumber);
        printf("\n");

        printf("Do you have it (Y/N)? ");
        scanf(" %c", &isPresent);

        if (isPresent == 'Y' )
        {
           if (checkNumber(Bingo, yourNumber))
           {
                bool row = checkRow(Bingo);
                bool column = checkColumn(Bingo);
                bool diagonal = checkDiagonal(Bingo);
                if (row || column || diagonal)
                {
                    FillBingoCard(Bingo);
                }
                if (row && column)
                {
                    printf ("You filled out a row and a column -BINGO!!!\n");
                    isBingo = true;
                }
                else if (row)
                {
                    printf ("You filled out a row -BINGO!!!\n");
                    isBingo = true;
                }
                else if (column)
                {
                    printf ("You filled out a column -BINGO!!!\n");
                    isBingo = true;
                }
                else if(diagonal)
                {
                    printf("You filled out a diagonal -BINGO!!!\n");
                    isBingo = true;
                }
                else if (row && diagonal)
                {
                    printf("You filled out a row and a diagonal -BINGO!!!\n");
                    isBingo = true;
                }
                else if (column && diagonal)
                {
                    printf("You filled out a column and a diagonal -BINGO!!!\n");
                    isBingo = true;
                }
                else if ( row && column && diagonal)
                {
                    printf("You filled out a row, a column and a diagonal -BINGO!!!\n");
                    isBingo = true;
                }
           }
           else
           {
               printf("That value is not on your BINGO card -are you trying to cheat??\n");
           }


        }
    }
	//end of main
    return 0;
}
