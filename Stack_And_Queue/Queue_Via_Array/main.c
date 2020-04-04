#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

/**
Declaring and initializing global variables
*/
int arr[MAX_SIZE];
int front = 0;
int rear = 0;

/**
Description: This function is used to display all elements in array
Param: NA
Return: NA
*/
void displayArray()
{
    printf("\nFinal array: ");
    //Logic to iterate through all the elements in list
    for(int i = front ; i<rear; i++)
    {
        printf("%d ",arr[i]);
    }
}

/**
Description: This function is used to add an elements in array
Param: NA
Return: NA
*/
void enqueElements(int num)
{
    //Add an element to rear index
    arr[rear] = num;
    //Increment rear so that next element will be added to new rear
    rear++;
}

/**
Description: This function is used to delete an elements in array
Param: NA
Return: NA
*/
void dequeElements()
{
    printf("\nElement popped: %d",arr[front]);
    //Incrementing front variable
    front++;
}

/**
Description: This function call all the function
Param: NA
Return: NA
*/
int main()
{
    //Declare variables and initialize it
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
                enqueElements(pushElement);
            }
            //Function call to pop an element
            else
            {
                dequeElements();
            }
        }

        displayArray();
    }
    return 0;
}
