#include <stdio.h>
#include <stdlib.h>

/**
Structure created for linked list
*/
struct Node
{
    int visitFlag;
    int data;
    struct Node *nxt;
}*start;

/**
Description: This function is to display list
Param: structure Node
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
Description: This function is to find a cycle in list
Param: structure Node
Return: NA
*/
void findCycle(struct Node *head)
{
    //Declaring variables and initializing
    struct Node *tempHead = NULL;
    tempHead = head;
    //Logic to check if the first node is linked to itself
    if(tempHead->nxt == tempHead)
    {
        printf("\nCycle Detected at data : %d !!!",tempHead->data);
        tempHead->nxt = NULL;
    }
    //Logic to check if any node is connected to any previous node forming a cycle.It uses
    //visistFlag variable to keep track of all the nodes visited and updating it.
    else
    {
        while(tempHead != NULL)
        {
            //If the next node has visitFlag updated, it means that it is forming cycle.
            if(tempHead->nxt->visitFlag == 1)
            {
                printf("\nCycle Detected from %d to %d !!!!",tempHead->data,tempHead->nxt->data);
                tempHead->nxt = NULL;
                break;
            }
            //Else continue to iterate through list and update visitFlag
            tempHead->visitFlag = 1;
            tempHead = tempHead->nxt;
        }
    }
}
/**
Description: This function creates cyclic linked list
Param: NA
Return: NA
*/
void createCyclicList()
{
    //Declaring variables and initializing it
    struct Node *tempStart = NULL;
    struct Node *newNode = NULL;
    struct Node *tempNode = NULL;
    int counNode = 1;
    int numOfNodes = 0;
    int nodeVal = 0;
    //Logic to check if start node is NULL
    if(start == NULL)
    {
        int startVal = 0;
        start = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value of 1st node: ");
        scanf("%d",&startVal);
        start->data = startVal;
        start->visitFlag = 0;
        start->nxt = NULL;
    }
    //Assigning start node to 2 temporary nodes
    tempStart = start;
    tempNode = start;
    printf("\nEnter no. of nodes: ");
    scanf("%d",&numOfNodes);
    //Logic to create linked list for n number of nodes
    for(int i = 2;i<=numOfNodes; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value for new node: ");
        scanf("%d",&nodeVal);
        newNode->data = nodeVal;
        newNode->visitFlag = 0;
        newNode->nxt = NULL;
        tempStart->nxt = newNode;
        tempStart = tempStart->nxt;
    }
    //Logic to iterate through linked list and link the last node with any one of the nodes
    //between start to end of the list
    while(tempNode != NULL)
    {
        if(counNode == 4)
        {
            break;
        }
        counNode++;
        tempNode = tempNode->nxt;
    }
    tempStart->nxt = tempNode;
}

//Main function to call other functions
int main()
{
    createCyclicList();
    findCycle(start);
    displayList(start);
    return 0;
}
