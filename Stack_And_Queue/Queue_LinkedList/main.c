#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
}*start;

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *temp = NULL;

/**
Description: This function will  display all the elements in the linked list
Param: struct
Return: NA
*/
void displayList(struct Node *head)
{
    printf("\nFinal List: ");
    //Logic to iterate through linked list
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->nxt;
    }
}

/**
Description: This function will insert an element in the linked list
Param: integer
Return: NA
*/
void enqueElements(int num)
{
    struct Node *newNode = NULL;
    //Logic to check if start node is null. If yes, allocate memory and insert data
    if(start == NULL)
    {
        start = (struct Node*)malloc(sizeof(struct Node));
        start->data = num;
        start->nxt = NULL;
        //Storing first node ini both front and rear node
        front = start;
        rear = start;
    }
    //Logic to create a new node, incrementing rear node so that next time new node will be added
    //after rear node
    else
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->nxt = NULL;
        rear->nxt = newNode;
        rear = rear->nxt;
    }
}

/**
Description: This function will delete an element from the linked list
Param: NA
Return: NA
*/
void dequeElements()
{
    printf("\nElement popped: %d",front->data);
    //Storing front node in to temp node and then increment front node to next node in the list.
    //So that next time node deleted will be next one.
    temp = front;
    front = front->nxt;
    free(temp);
}

//Main function to call all the functions
int main()
{
    //Declare variables and initialize it.
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


    }
    //Logic to check if there is no elements in libked list
    if(front == NULL)
    {
        printf("\nNo elements in the list!!!!");
    }
    //Call function to display list
    else
    {
        displayList(front);
    }

    return 0;
}
