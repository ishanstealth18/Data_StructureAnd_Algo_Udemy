#include <stdio.h>
#include <stdlib.h>
#define Max_SIZE 10

/**
Declaring global variables and initializing it
*/
int arr[Max_SIZE];
int front = -1;
int rear = -1;

/**
Description: This function displays all elements in an array
param: NA
Return: NA
*/
void displayArray()
{
    printf("\nFinal List: ");
    //Logic to display elements from front to rear
    if(front <= rear)
    {
        for(int i = front; i<=rear; i++)
        {
            printf("%d ",arr[i]);
        }
    }
    else
    {
        //Logic to print elements first from front to end of array and then print elements
        //from start of an array to rear.
        for(int i = front; i<Max_SIZE; i++)
        {
            printf("%d ",arr[i]);
        }
        for(int j = 0; j<=rear ;j++)
        {
            printf("%d ",arr[j]);
        }
    }
}

/**
Description: This function inserts an element at rear in an array
param: integer
Return: NA
*/
void rearInsert(int num)
{
    if(front == -1)
    {
        front = 0;
        arr[rear] = num;
    }

    if(rear == (Max_SIZE-1))
    {
        rear = 0;
        arr[rear] = num;
    }
    else
    {
        rear++;
        arr[rear] = num;
    }
    printf("\nRear: %d",rear);
    printf("\nFront : %d",front);
}

/**
Description: This function deletes an element from rear in an array
param: NA
Return: NA
*/
void rearDelete()
{
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = (Max_SIZE-1);
    }
    else
    {
        rear--;
    }
    printf("\nRear: %d",rear);
    printf("\nFront : %d",front);

}

/**
Description: This function inserts an element at front in an array
param: integer
Return: NA
*/
void frontInsert(int num)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
        arr[front] = num;
    }
    else if(front == 0)
    {
        front = (Max_SIZE-1);
        arr[front] = num;
    }
    else
    {
        front--;
        arr[front] = num;
    }
    printf("\nRear: %d",rear);
    printf("\nFront : %d",front);
}

/**
Description: This function deletes an element from front in an array
param: NA
Return: NA
*/
void frontDelete()
{
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == (Max_SIZE-1))
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("\nRear: %d",rear);
    printf("\nFront : %d",front);

}

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
            printf("\nEnter operation (0 = Rear insert/1 = Rear delete/2 = Front insert/3 = Front delete): ");
            scanf("%d",&operationName);
            if(operationName == 0)
            {
                printf("\nEnter element to push at rear: ");
                scanf("%d",&pushElement);
                rearInsert(pushElement);
            }
            else if(operationName == 1)
            {
                rearDelete();
            }
            else if(operationName == 2)
            {
                printf("\nEnter element to push at front: ");
                scanf("%d",&pushElement);
                frontInsert(pushElement);
            }
            //Function call to pop an element
            else
            {
                frontDelete();
            }
        }

        displayArray();
    }
    return 0;
}
