#include <stdio.h>
#include <stdlib.h>

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

/** \brief : This function deletes a node from the beginning of the list.
 * \param : structure
 * \return : void
 *
 */

void deleteAtBeginning(struct node *head)
{
    /*Declare a node and allocate memory*/
    struct node *deleteTemp = NULL;
    deleteTemp = (struct node*) malloc(sizeof(struct node));
    /*Logic to delete node at beginning of list by allocating next of the node into a
    temporary node and then making next of the node as NULL. Lastly assign temporary node
    as start or head node.*/
    deleteTemp = head->next;
    head->next = NULL;
    start = deleteTemp;
}

/** \brief : This function deletes a node at the end of the list.
 * \param : structure node
 * \return : void
 */
void deleteAtEnd(struct node *head)
{
    /*Logic to find the end of the list*/
    while(head->next != NULL)
    {
        head = head->next;
    }
    /*Logic to delete last node by making next and previous node to NULL*/
    head->prev->next = NULL;
    head->prev = NULL;
}

/** \brief : This function deletes nodes between the list.
 * \param : structure node
 * \return : void
 */

void deleteBetweenNode(struct node *head)
{
    /*Ask user to enter which node to be deleted*/
    printf("\nEnter node number to be deleted: ");
    int deleteNodeNum = 0;
    scanf("%d",&deleteNodeNum);
    int deleteCount = 1;
    /*Logic to check the node to be deleted*/
    while(head != NULL)
    {
        if(deleteNodeNum == deleteCount)
        {
            break;
        }
        deleteCount++;
        head = head->next;
    }
    /*Logic to delete node in between the node by linking the previous node to
    the node next to the head*/
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head->next = NULL;
    head->prev = NULL;
}

int main()
{
    /*Executing all the functions*/
    int numOfNodes = 0;
    printf("Number of nodes to create: ");
    scanf("%d",&numOfNodes);
    createNodes(numOfNodes);
    displayList(start);
    printf("\nAfter deleting 1st node: ");
    deleteAtBeginning(start);
    displayList(start);
    printf("\nDelete last node: ");
    deleteAtEnd(start);
    displayList(start);
    deleteBetweenNode(start);
    displayList(start);
    return 0;
}
