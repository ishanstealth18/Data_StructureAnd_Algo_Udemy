#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

//Declaring global variables
int arr[MAX_SIZE];
int top = 0;

/**
Description: This function inserts new elements in array
Param: integer
Return: NA
*/
void pushElements(int num)
{
    printf("\nTop: %d",top);
    //Storing element in array
    arr[top] = num;
    //incrementing top variable, so that next element will be inserted at incremented variable
    top++;

}

/**
Description: This function deletes latest elements from array
Param: NA
Return: NA
*/
void popElements()
{
    printf("\nElement popped is: %d",arr[top-1]);
    top--;
}

/**
Description: This function displays elements in array
Param: NA
Return: NA
*/
void displayArray()
{
    printf("\n");
    for(int i = 0; i<top; i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int operationName = 0;
    int pushElement = 0;
    int popNum = 0;
    int exitValue = 0;
    //Logic to ask user continuously either to push or pop an element. User can
    //exit also from current program.
    while(1)
    {
        printf("\nWant to exit(1= yes/0 = no): ");
        scanf("%d",&exitValue);
        if(exitValue == 1)
        {
            printf("\nExited!!!");
            break;
        }
        else
        {
            //Logic to push an element
            printf("\nEnter operation (0 = push/ 1 = pop): ");
            scanf("%d",&operationName);
            if(operationName == 0)
            {
                printf("\nEnter element to push: ");
                scanf("%d",&pushElement);
                pushElements(pushElement);
            }
            //Function call to pop an element
            else
            {
                popElements();
            }
        }

        displayArray();
    }
    return 0;
}
