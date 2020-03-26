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
    insertAtBeginning(head);

}

/**
Description: This function helps in inserting node at beginning of linked list
Param: Node struct
Return: NA
*/
void insertAtBeginning(struct Node *head)
{
    //Declaring variables
    struct Node *endNode1 = NULL;
    struct Node *beginNode = NULL;
    int beginNodeVal = 0;
    endNode1 = head;
    //Logic to iterate to the last node
    while(head->nxt != endNode1)
    {
        //printf("%d ",n->data);
        head = head->nxt;
    }
    //Logic to insert a node to beginning of double linked list
    printf("\nLast node value: %d",head->data);
    beginNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter node value of begin node: ");
    scanf("%d",&beginNodeVal);
    beginNode->data = beginNodeVal;
    beginNode->nxt = head->nxt;
    head->nxt = beginNode;
    head = head->nxt;
    displayList(head);
}

int main()
{
    createLinkedList(start);
    //displayList(start);
    //insertAtBeginning(start);
    return 0;
}
