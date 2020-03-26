#include <stdio.h>
#include <stdlib.h>

/**
Creating structure
*/
struct Node
{
    int data;
    struct Node *nxt;
}*start;


/**
Description: This function helps in displaying linked list
Param: Node struct
Return: NA
*/
void displayList(struct Node *n)
{
    struct Node *stopNode = NULL;
    stopNode = n;
    printf("\nFinal List: ");
    //Logic to iterate over double linked list
    while(n->nxt != stopNode)
    {
        printf("%d ",n->data);
        n = n->nxt;
        //Logic to stop iteration
        if(n->nxt == stopNode)
        {
            printf("%d ",n->data);
            printf("\nNext value: %d",n->nxt->data);
            break;
        }
    }
}

/**
Description: This function helps in creating double linked list
Param: Node struct
Return: NA
*/
void createLinkedList(struct Node *head)
{
    //Declaring variables
    struct Node *temp = NULL;
    struct Node *newNode = NULL;
    int numOfNodes = 0;
    int nodeVal = 0;
    //Creating first node in the list, if list is empty
    if(head == NULL)
    {
        int firstNodeValue = 0;
        head = (struct Node*)malloc(sizeof(struct Node));
        if(head == NULL)
        {
            printf("\nMemory not allocated.");
        }
        printf("\nEnter value of node 1: ");
        scanf("%d",&firstNodeValue);
        head->data = firstNodeValue;
        head->nxt = NULL;
    }
    temp = head;

    printf("\nEnter number of nodes: ");
    scanf("%d",&numOfNodes);
    //Creating number of nodes in the double linked list
    for(int i = 2; i<=numOfNodes; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("\nMemory not allocated.");
        }
        printf("\nEnter value for node %d: ",i);
        scanf("%d",&nodeVal);
        newNode->data = nodeVal;
        newNode->nxt = NULL;
        temp->nxt = newNode;
        temp = temp->nxt;
    }
    temp->nxt = head;
    displayList(head);
    insertAtEnd(head);
    deleteEndNode(head);
    deleteStartNode(head);
}

/**
Description: This function inserts node at the end of the double linked list
Param: struct Node
Return: NA
*/
void insertAtEnd(struct Node *head)
{
    struct Node *nodeAtEnd = NULL;
    int nodeVal1 = 0;
    printf("\nValue of head: %d",head->data);
    struct Node *endNode1 = head;
    while(head->nxt != endNode1)
    {
        head = head->nxt;
    }
    printf("\nValue of head: %d",head->data);
    nodeAtEnd = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter last node value: ");
    scanf("%d",&nodeVal1);
    nodeAtEnd->data = nodeVal1;
    nodeAtEnd->nxt = head->nxt;
    head->nxt = nodeAtEnd;
    head = head->nxt;
    displayList(head->nxt);
}

/**
Description: This function deletes node at the end of the double linked list
Param: struct Node
Return: NA
*/
void deleteEndNode(struct Node *head)
{
    struct Node *endNode2 = NULL;
    endNode2 = head;
    //Logic to iterate to last node
    while(head->nxt->nxt != endNode2)
    {
        head = head->nxt;
    }
    //Logic to delete last node of the list
    printf("\nHead Value: %d",head->data);
    head->nxt = head->nxt->nxt;
    printf("\nNext value: %d",head->nxt->data);
    head = head->nxt;
    displayList(head);

}

/**
Description: This function deletes node at the start of the double linked list
Param: struct Node
Return: NA
*/
void deleteStartNode(struct Node *head)
{
    struct Node *endNode3 = NULL;
    endNode3 = head;
    //Logic to iterate to last node of the list
    while(head->nxt != endNode3)
    {
        head = head->nxt;
    }
    //Logic to delete first node of the list
    printf("\nhead value: %d",head->data);
    head->nxt = head->nxt->nxt;
    head = head->nxt;
    displayList(head);
}

int main()
{
    createLinkedList(start);
    return 0;
}
