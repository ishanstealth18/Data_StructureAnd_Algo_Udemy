#include <stdio.h>
#include <stdlib.h>

//Declaring global variable
int result = 0;

/**
Description: This function finds factorial of a number using recursive method.
Param: integer
return: NA
*/
int findFactorial(int num)
{
    //Logic for base case
    if(num <= 1)
    {
        result = 1;
        return;
    }
    //Logic to calculate factorial recursively.
    else
    {
        result = num * (findFactorial(num-1));
        printf("\nNum: %d",num);
        printf("\nResult: %d",result);
    }
    return result;
}


int main()
{
    printf("Answer: %d",findFactorial(3));
    return 0;
}
