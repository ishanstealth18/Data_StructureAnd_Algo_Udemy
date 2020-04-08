#include <stdio.h>
#include <stdlib.h>

/**
Structure for linked list
*/
struct Node
{
    int data;
    int priority;
    struct Node *nxt;
}*start;

//Declaring nodes and initializing it to NULL
struct Node *displayStart = NULL;
struct Node *iterateNode = NULL;

/**
Description: This function displays all the elements of the list.
param: struct
return: NA
*/
void displayList(struct Node *head)
{
    printf("\nFinal List: ");
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->nxt;
    }
}

/**
Description: This function creates a sorted list as per the priority.
param: NA
return: NA
*/
void createSortedList()
{
    //Declaring nodes and variables and initialising it
    struct Node *tempStart = NULL;
    struct Node *newNode = NULL;
    int numOfNodes = 0;
    int newNodeVal = 0;
    int newNodePriority = 0;

    //Logic to add first node if list is empty
    if(start == NULL)
    {
        int startNodeVal = 0;
        int startNodePriority = 0;
        printf("\nEnter Node 1 value: ");
        scanf("%d",&startNodeVal);
        printf("\nEnter start node priority: ");
        scanf("%d",&startNodePriority);
        start = (struct Node*)malloc(sizeof(struct Node));
        start->data = startNodeVal;
        start->priority = startNodePriority;
        start->nxt = NULL;
    }

    printf("\nEnter number of nodes: ");
    scanf("%d",&numOfNodes);
    //Logic to add n number of nodes
    for(int i = 2; i<=numOfNodes; i++)
    {
        tempStart = start;
        iterateNode = start;
        //Creating new nodes
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter node %d value: ",i);
        scanf("%d",&newNodeVal);
        printf("\nEnter node %d priority: ",i);
        scanf("%d",&newNodePriority);
        newNode->priority = newNodePriority;
        newNode->data = newNodeVal;
        //Logic to insert new node in sorted order
        while(tempStart != NULL)
        {
            //Logic to insert new node at beginning of the list.
            if(newNode->priority <= start->priority)
            {
                newNode->nxt = start;
                start = newNode;
                iterateNode = start;
                break;
            }
            //insert at end
            else if((newNode->priority >= tempStart->priority) && (tempStart->nxt == NULL))
            {
                tempStart->nxt = newNode;
                newNode->nxt = NULL;
                break;
            }
            //Logic to insert node in between 2 nodes
            else if((newNode->priority >= tempStart->priority) && (newNode->priority <= tempStart->nxt->priority))
            {
                newNode->nxt = tempStart->nxt;
                tempStart->nxt = newNode;
                break;
            }
            else
            {
                tempStart = tempStart->nxt;
            }
        }

    }
}

//Main function
int main()
{
    createSortedList();
    displayList(iterateNode);
    return 0;
}
