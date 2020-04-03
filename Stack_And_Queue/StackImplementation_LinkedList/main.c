#include <stdio.h>
#include <stdlib.h>

/**
Structure created to create a linked list
*/
struct Node
{
    int data;
    struct Node *nxt;
}*start;

//Creating global nodes and initializing it
struct Node *displayHead = NULL;
struct Node *tempStart = NULL;
struct Node *tempHead = NULL;

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
Description: This function will push an element in the linked list
Param: integer
Return: NA
*/
void pushElements(int num)
{
    struct Node *newNode = NULL;
    //Logic to check if start node is null, if yes, allocate memory and value
    if(start == NULL)
    {
        start = (struct Node*)malloc(sizeof(struct Node));
        start->data = num;
        start->nxt = NULL;
        //Allocating start node value to all temporary nodes
        tempStart = start;
        displayHead = start;
        tempHead = start;
    }
    //Logic to create a new node whenever new element is to be pushed
    else
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->nxt = NULL;
        //Using tempstart, it will ensure the node to be added is after the latest node
        tempStart->nxt = newNode;
        tempStart = tempStart->nxt;
    }
}

/**
Description: This function will delete the latest element in the linked list
Param: struct
Return: NA
*/
void popElements(struct Node *head)
{
    //printf("\nHead : %d",head->data);
    //Logic to check if there is only 1 element in the list
    if(head->nxt == NULL)
    {
        printf("\nElement popped: %d",head->data);
        free(head);
        displayHead = NULL;
    }
    //Logic to check the last element in the list and delete it. Also it will save the last element
    //in tempStart node. So that latest node is maintained.
    else
    {
        while(head->nxt->nxt != NULL)
        {
            head = head->nxt;
        }
        printf("\nElement popped: %d",head->nxt->data);
        head->nxt = NULL;
        tempStart = head;
    }
}

/**
Description: This function will call all the functions
Param: NA
Return: NA
*/
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
                popElements(tempHead);
            }
        }


    }
    //Logic to check if there is no elements in libked list
    if(displayHead == NULL)
    {
        printf("\nNo elements in the list!!!!");
    }
    //Call function to display list
    else
    {
        displayList(displayHead);
    }

    return 0;
}
