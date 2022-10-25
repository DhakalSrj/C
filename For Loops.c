//Suraj Dhakal
//In this program nested for loop is used to get the required lines of output
//by taking user input.

//including the library
#include <stdio.h>

//start of main
int main (void)
{
    //Initializing the variables for the starting and ending values of i,j,k.
    int i,j,k;
    int startI,endI,startJ,endJ,startK,endK;

    //asking the user for the starting and ending values for i,j,k
	//and storing the values in a memory location
    printf("Enter the starting value for i:");
    scanf("%d", &startI);
    printf("Enter the ending value for i:");
    scanf("%d", &endI);
    printf("Enter the starting value for j:");
    scanf("%d", &startJ);
    printf("Enter the ending value for j:");
    scanf("%d", &endJ);
    printf("Enter the starting value for k:");
    scanf("%d", &startK);
    printf("Enter the ending value for k:");
    scanf("%d", &endK);
	printf("\n\n");

    //using nested for loop
    //the outer for loops creates the blocks in the output
    for (i=startI; i<endI ; i++)
    {
        //the middle for loops creates the lines per block in the output
        for(j=startJ; j<endJ; j++)
        {
            //the inner for loop creates the * per line in the output
            for (k=startK; k<endK; k++)
            {
                printf("*");
            }

            printf("\n");
        }

        printf("\n");


    }
    //end of main
    return 0;
}
