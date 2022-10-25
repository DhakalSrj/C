//Suraj Dhakal
//Bitwiswe Calculator 

#include <stdio.h>
#define BITS 8
//function to print the values stored in binary 	
void printarray(char Binary[BITS+1])
{
    int i;
    for(i = BITS-1;i >= 0; i--)
    {
        printf("%c",Binary[i]);
    }
}
// function to convert decimal into binary 
void ConvertDecimalToBinary(int num , char Value[BITS+1])
{
	int Decimal[BITS];
	int i;
	//for loop to divide the number in half and ignore the remainder
	//And store the divided value in the int array
	for ( i = 0; i < BITS+1 ; i++)
	{
		Decimal[i]= num;
		num = num >> 1;
	    
	}
	char temp[BITS+1];
	temp[BITS+1] =0;
	//for loop to check and see if the number is even or odd
	for ( i=0; i < BITS ; i++)
	{
	    
		if ((Decimal[i] & 1) == 0)
		{
			Value[i]=48;
			
		}
		else 
		{
			Value[i]=49;
			
		}
			
	}
	
	
}
//startof main    
int main(void)
{
	//intializing variables 
	int Number1,Number2;
	char Operator[3]={};
	char numarray1[BITS+1],numarray2[BITS+1],resultarray[BITS+1];
	//Welcome Message for the bitwise calculator
	//taking base 10 user inputs and storing their values
	printf("Welcome! This is the Bitwise calculator.\n\n");
	printf("Enter two base 10 values with a bitwise operator to see the decimal result and the binary result.");
	printf("The format is:\n\n");
	printf("FirstNumber Operator SecondNumber\n\n");
	printf("This calculator can be used with &,|,^,>> and << \n\n");
	printf("For example,enter the expression\n\n");
	printf("2 & 4\n\n");
	printf("Please note that the spaces between numbers and operators is essential and ");
	printf("the two entered values must be between 0 and 255.\n\n");
	printf("Please Enter the expression.\n\n");
	scanf ("%d %s %d" , &Number1, Operator,&Number2);
	
	//prompting the user to input the correct values for the expression needed 
	while((Number1 < 0 || Number1 > 255) || (Number2 < 0 || Number2 > 255))
	{
		printf("The entered expression contains out of range values.\n\n");
		printf("Please re-enter the expression using values between 0 and 255.\n\n");
		scanf("%d %s %d" , &Number1, Operator,&Number2);
	}
	
	// for Bitwise AND
	if (Operator[0]=='&')
	{
	     int resultnum = Number1 & Number2;
		 printf("In base 10... \n\n");
	     printf("%d %s %d = %d ",Number1,Operator,Number2,resultnum);
		 printf("\n\nIn %d",BITS);
		 printf("-bit base 2:\n\n");
	     ConvertDecimalToBinary(Number1,numarray1);
	     printarray(numarray1);
		 printf("\n & \n");
		 ConvertDecimalToBinary(Number2,numarray2);
		 printarray(numarray2);
		 printf("\n======== \n");
		 ConvertDecimalToBinary(resultnum,resultarray);
		 printarray(resultarray);
		 printf("\n\n");
		 
	} 
	//for Bitwise OR	 
    else if (Operator[0]=='|')
	{
		int resultnum = Number1 | Number2;
		printf("In base 10... \n\n");
	    printf("%d %s %d = %d ", Number1,Operator,Number2,resultnum);
		printf("\n\nIn %d",BITS);
		printf("-bit base 2:\n\n");
	    ConvertDecimalToBinary(Number1,numarray1);
		printarray(numarray1);
		printf("\n | \n");
		ConvertDecimalToBinary(Number2,numarray2);
		printarray(numarray2);
		printf("\n========\n");
		ConvertDecimalToBinary(resultnum,resultarray);
		printarray(resultarray);
		printf("\n\n");
		
		
	}
	//for Bitwise XOR
    else if (Operator[0]=='^')
	{
		int resultnum = Number1 ^ Number2;
		printf("In base 10... \n\n");
	    printf("%d %s %d = %d ", Number1,Operator,Number2,resultnum);
		printf("\n\nIn %d",BITS);
		printf("-bit base 2:\n\n");
	    ConvertDecimalToBinary(Number1,numarray1);
		printarray(numarray1);
		printf("\n ^ \n");
		ConvertDecimalToBinary(Number2,numarray2);
		printarray(numarray2);
		printf("\n========\n");
		ConvertDecimalToBinary(resultnum,resultarray);
		printarray(resultarray);
		printf("\n\n");
		
	}
	//for Bitwise left shift
    else if(Operator[0]=='<')
	{
	    int resultnum=Number1 << Number2;
		printf("In base 10... \n\n");
	    printf("%d %s %d = %d ", Number1,Operator,Number2,resultnum);
		printf("\n\nIn %d",BITS);
		printf("-bit base 2:\n\n");
	    ConvertDecimalToBinary(Number1,numarray1);
		printarray(numarray1);
		printf("\n << \n");
		ConvertDecimalToBinary(Number2,numarray2);
		printarray(numarray2);
		printf("\n========\n");
		ConvertDecimalToBinary(resultnum,resultarray);
		printarray(resultarray);
		printf("\n\n");
		
	}
	//for Bitwise right shift 	
	else if(Operator[0]=='>')
	{
		
	    int resultnum = Number1 >> Number2;
		printf("In base 10... \n\n");
	    printf("%d %s %d = %d ", Number1,Operator,Number2,resultnum);
		printf("\n\nIn %d",BITS);
		printf("-bit base 2:\n\n");
	    ConvertDecimalToBinary(Number1,numarray1);
		printarray(numarray1);
		printf("\n >> \n");
		ConvertDecimalToBinary(Number2,numarray2);
		printarray(numarray2);
		printf("\n========\n");
		ConvertDecimalToBinary(resultnum,resultarray);
		printarray(resultarray);
		printf("\n\n");
	}
	//promting the user that the operator entered is invalid
	else 
	{
	printf("\n\nOperator %s", Operator );
	printf(" is not supported by this calculator.\n\n");
	}
	
//end of main 
return 0;
}