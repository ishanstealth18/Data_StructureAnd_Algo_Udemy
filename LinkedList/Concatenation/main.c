#include <stdio.h>
#include <stdlib.h>

/**
Creating structure for linked list
*/
struct Node
{
    int data;
    struct Node *nxt;
};

//Declaring structures
struct Node *start1 = NULL;
struct Node *start2 = NULL;

/**
Description: This function displays normal linked list
Param: Structure node
Return: NA
*/
void displayList(struct Node *head)
{
    printf("\nFinal list: ");
    //Logic to iterate through link list
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->nxt;
    }
}

/**
Description: This function displays circular linked list
Param: Structure node
Return: NA
*/
void displayCircularList(struct Node *head)
{
    struct Node *endNode = NULL;
    endNode = head;
    printf("\nFinal list: ");
    //Logic to iterate through cicrular linked list
    while(head->nxt != endNode)
    {
        printf("%d ",head->data);
        head = head->nxt;
        if(head->nxt == endNode)
        {
            printf("%d ",head->data);
            printf("\nNext value: %d ",head->nxt->data);
            break;
        }
    }
    //printf("%d ",head->data);
    //printf("\nTemp next: %d",head->nxt->data);
}

/**
Description: This function create a circular linked list
Param: NA
Return: NA
*/
void createList1()
{
    //Declaring variables and structures
    struct Node *temp1 = NULL;
    struct Node *newNode1 = NULL;
    int numOfNodes1 = 0;
    int newNodeVal1 = 0;
    //Logic to check if first node is empty. And if yes, create a new one
    if(start1 == NULL)
    {
        int startNodeVal = 0;
        start1 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value for node 1: ");
        scanf("%d",&startNodeVal);
        start1->data = startNodeVal;
        start1->nxt = start1;
    }
    temp1 = start1;
    printf("\nEnter number of nodes: ");
    scanf("%d",&numOfNodes1);
    //Logic to create number of nodes in the circular linked list
    for(int i = 2; i<=numOfNodes1; i++)
    {
        newNode1 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value for node %d: ",i);
        scanf("%d",&newNodeVal1);
        newNode1->data = newNodeVal1;
        newNode1->nxt = start1;
        temp1->nxt = newNode1;
        temp1 = temp1->nxt;
    }
}

/**
Description: This function creates normal linked list
Param: NA
Return: NA
*/
void createList2()
{
    //Declaring variables and initializing it
    struct Node *temp2 = NULL;
    struct Node *newNode2 = NULL;
    int numOfNodes2 = 0;
    int newNodeVal2 = 0;
    //Logic to check if 1st node is empty, if yes, create a new one
    if(start2 == NULL)
    {
        int startNodeVal2 = 0;
        start2 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value for node 1: ");
        scanf("%d",&startNodeVal2);
        start2->data = startNodeVal2;
        start2->nxt = NULL;
    }
    temp2 = start2;
    printf("\nEnter number of nodes: ");
    scanf("%d",&numOfNodes2);
    //Logic to create a normal linked list with number of nodes
    for(int i = 2; i<=numOfNodes2; i++)
    {
        newNode2 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value for node %d: ",i);
        scanf("%d",&newNodeVal2);
        newNode2->data = newNodeVal2;
        newNode2->nxt = NULL;
        temp2->nxt = newNode2;
        temp2 = temp2->nxt;
    }
}

/**
Description: This function combines linked list
Param: Structure node, Structure Node
Return: NA
*/
void concatenateList(struct Node *listHead1, struct Node *listHead2)
{
    //Declaring variables and initializing it
    struct Node *endNode2 = NULL;
    endNode2 = listHead1;
    struct Node *tempHead1 = NULL;
    tempHead1 = listHead1;
    //Logic to iterate through 1st linked list
    while(tempHead1->nxt != endNode2)
    {
        tempHead1 = tempHead1->nxt;
    }
    printf("\nTemphead1 :%d",tempHead1->data);
    tempHead1->nxt = listHead2;
    //Logic to iterate through list till start of the list is found
    while(tempHead1->nxt != NULL)
    {
        tempHead1 = tempHead1->nxt;
    }
    //Linkning last node to first one
    tempHead1->nxt = listHead1;
}

int main()
{
    createList1();
    displayCircularList(start1);
    printf("\n\n");
    createList2();
    displayList(start2);
    printf("\n\n");
    concatenateList(start1,start2);
    displayCircularList(start1);
    return 0;
}
