#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief :This function creates a structure for double linked list.
 *  It has one previous node, one next node and data.
 * \param : NA
 * \return : NA
 */

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

/*Declaring global variable start node*/
struct node *start = NULL;

/** \brief : This function creates a new double linked list as per the user's input
 *  for number of nodes.
 * \param : integer numOfNodes
 * \return : void
 */

void *createNodes(int numOFNode)
{
    /*Declaring variables*/
    int nodeData1 = 0;
    /*Creating a node and allocating space*/
    start = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data for node 1: ");
    scanf("%d",&nodeData1);
    /*Checking if start node is allocated memory*/
    if(start == NULL)
    {
        printf("\nNo memory allocated");
    }
    /*Logic to create 1st node. Both prev and next will be NULL in this case*/
    start->next = NULL;
    start->data = nodeData1;
    start->prev = NULL;
    /*Creating another node which will be used to crete n number of nodes*/
    struct node *insertNode = NULL;
    struct node *temp = start;
    /*Logic to create nodes as per user's input and makinig them doubly linked list*/
    for(int i = 2; i<=numOFNode; i++)
    {
        int nodeData = 0;
        /*Allocating memory to node*/
        insertNode = (struct node*) malloc(sizeof(struct node));
        printf("\nEnter data for node %d: ",i);
        scanf("%d",&nodeData);
        /*Logic to link the node with the previous node and make it double linked list.
        Pointing next of node to NULL and prev to previous node*/
        insertNode->data = nodeData;
        insertNode->next = NULL;
        insertNode->prev = temp;
        /*Linking the previous node to new node inserted*/
        temp->next = insertNode;
        /*Moving to the next node*/
        temp = temp->next;
    }
}

/** \brief : This function is used to display the final linked list.
 * \param : start node
 * \return : void
 */

void displayList(struct node *head)
{
    /*Logic to iterate over the list and print data*/
    printf("\nFinal List: ");
    while(head != NULL)
    {
        printf("\nData: %d",head->data);
        /*Condition to check the previous data as it is double link list*/
        if(head->prev == NULL)
        {
            printf(" Prev: %d",0);
        }
        else
        {
            printf(" Prev: %d",head->prev->data);
        }
        head = head->next;
    }

}

/** \brief : This function inserts new node in the doubly linked list.
 * \param : start node
 * \return : void
 */

void insertBetweenNodes(struct node *head)
{
    /*Creating a new node and allocating memory to it*/
    struct node *betweenNode = NULL;
    betweenNode = (struct node*) malloc(sizeof(struct node));
    int whichNode = 0;
    /*Ask user to enter node number after which new node is to be inserted*/
    printf("\nEnter the node after which you want to insert: ");
    scanf("%d",&whichNode);
    int betweenNodeValue = 0;
    /*Ask user to enter node value*/
    printf("\nEnter the value of node in between: ");
    scanf("%d",&betweenNodeValue);
    int nodeCount = 0;
    /*Logic to reach to the node after whihc new node is to be inserted*/
    while(head->next != NULL)
    {
        nodeCount++;
        if(nodeCount == whichNode)
        {
            break;
        }
        head = head->next;
    }
    /*Logic to link new node in doubly linked list. Next of new node will be linked to successor node,
    prev of new node will be linked to predecessor node, next of predecessor node is linked to new node,
    prev of successor node is linked to new node*/
    betweenNode->next = head->next;
    head->next->prev = betweenNode;
    betweenNode->prev = head;
    head->next = betweenNode;
    betweenNode->data = betweenNodeValue;
}

/** \brief : This function inserts new node at the beginning of the linked list.
 * \param : start node
 * \return : void
 */

void insertAtBeginning(struct node *head)
{
    /*Check condition if head is null*/
    if(head == NULL)
    {
        printf("\nList is empty.");
    }
    /*Create a new node and allocate memory to it*/
    struct node *beginNode = NULL;
    beginNode = (struct node*) malloc(sizeof(struct node));
    /*Enter node value by the user*/
    printf("\nEnter value for node: ");
    int beginNodeValue = 0;
    scanf("%d",&beginNodeValue);
    /*Logic to link new node at the beginning. prev of thei new node will be NULL and next will be linked
    to head. At last we will store new node in start/head node*/
    beginNode->data = beginNodeValue;
    beginNode->prev = NULL;
    beginNode->next = head;
    head->prev = beginNode;
    start = beginNode;
}

/** \brief : This function will insefrt node at the end of the doubly linked list.
 * \param : start node
 * \return :void
 */

void insertAtEnd(struct node *head)
{
    /*Condition to check if head is null*/
    if(head == NULL)
    {
        printf("List is empty.");
    }
    /*Logic to iterate over the linked list and find the last node after which new node is to
    be inserted*/
    while(head->next != NULL)
    {
        head = head->next;
    }
    /*Create a new node and allocate memory to it*/
    struct node *endNode = NULL;
    int endNodeValue = 0;
    endNode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter value of end Node: ");
    scanf("%d",&endNodeValue);
    /*Link the last node. next of the new node to be inserted will be NULL as it will be last node. prev
    will be linked to the previous node and next of previous node will be linked to new node/last node*/
    endNode->data = endNodeValue;
    endNode->next = NULL;
    head->next = endNode;
    endNode->prev = head;
}

/** \brief : Main function will execute all the functions in this class.
 * \param : NA
 * \return : integer
 */

int main()
{
    /*Executing all the functions*/
    int numOfNodes = 0;
    printf("Number of nodes to create: ");
    scanf("%d",&numOfNodes);
    createNodes(numOfNodes);
    displayList(start);
    insertAtBeginning(start);
    displayList(start);
    insertAtEnd(start);
    displayList(start);
    insertBetweenNodes(start);
    displayList(start);
    return 0;
}

