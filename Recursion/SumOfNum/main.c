#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Description: This function calculates sum using recursion.
Param: integer
Return: integer
*/
int calculateSum(int num)
{
    int sum = 0;
    //Base case for recursion
    if(num <= 0)
    {
        return 0;
    }
    else
    {
        //Calculate sum using recursion
        sum = num + calculateSum(num-1);
    }
    return sum;

}

/**
Description: This function prints numbers using recursion.
Param: integer
Return: integer
*/
int printNumbers(int num)
{
    //Base case for recursion
    if(num <= 0)
    {
        num = 0;
    }
    else
    {
        //Print numbers using recursion
        printNumbers(num-1);
        printf("\n%d",num);
    }
}

/**
Description: This function calculates sum of digits of a given
            number using recursion.
Param: integer
Return: integer
*/
int sumOfDigits(int num)
{
    int sum1 = 0;
    //Base case for recursion
    if((num%10) <= 0)
    {
        return 0;
    }
    else
    {
        //Calculate sum of digits using recursion
        sum1 = (num%10) + sumOfDigits((num/10));
    }
    return sum1;

}

/**
Description: This function converts from decimal to binary using recursion.
Param: integer
Return: integer
*/
void decimalToBinary(int num)
{
    //Base case for recursion
    if((num) <= 0)
    {
        return 1;
    }
    else
    {
        //recursion calls
        decimalToBinary(num/2);
        printf("%d ",num%2);
    }
    return 1;

}


/**
Description: This function finds power using recursion.
Param: double,double
Return: double
*/
double findNPower(double num, double power)
{
    double result = 0.0;
    //Base case for recursion
    if(power <= 0)
    {
        return 1;
    }
    else
    {
        //Recursion calls
        findNPower(num,power-1);
        result = pow(num,power);
        printf("\nResult = %.2f",result);
    }
    return result;

}

/**
Description: This function calculates GCD of 2 numbers using recursion.
Param: integer, integer
Return: integer
*/
int findGCD(int num1, int num2)
{
    int gcdVal = 0;
    //Base case of recursion
    if(num2 == 0)
    {
        return num1;
    }
    else
    {
        //Recursio calls
        return findGCD(num2,num1%num2);
    }
}

/**
Description: This function calculates fibonacci series using recursion.
Param: integer
Return: integer
*/
int fibonacciSeries(int num)
{
    //Base case for recursion
    if(num == 0)
    {
        return 0;
    }
    //Base case for recursion
    else if(num == 1)
    {
        return 1;
    }
    else
    {
        //Recursion calls
        return fibonacciSeries(num-1) + fibonacciSeries(num-2);
    }
}

/**
Description: This function shows Tower of Hanoi using recursion.
Param: integer,char,char,char
Return: NA
*/
void towerOfHanoi(int n, char src, char temp, char dest)
{
    printf("\nN: %d",n);
    //Base case for recursion
    if(n == 1)
    {
        printf("\nMove disk %d from %c to %c: ",n,src,dest);
        return;
    }
    else
    {
        //First recursion calls
        towerOfHanoi(n-1,src,dest,temp);
        printf("\nMove disk %d from %c to %c ",n,src,dest);
        //Second recursion calls
        towerOfHanoi(n-1,temp,src,dest);
    }
}

int main()
{
    int inputNum = 0;
    //printf("\nEnter number to calculate sum: ");
    //scanf("%d",&inputNum);
    //printf("\nSum: %d",calculateSum(inputNum));
    //printNumbers(inputNum);
    //printf("\nSum of digits: %d",sumOfDigits(inputNum));
    //decimalToBinary(inputNum);
    //findNPower(4.00,6.00);
    //printf("\nGCD: %d",findGCD(21,35));
    //printf("\n%d ",fibonacciSeries(5));
    towerOfHanoi(4,'A','B','C');
    return 0;
}
