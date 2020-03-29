#include <stdio.h>
#include <stdlib.h>

//Creating structure for linked list
struct Node
{
    int data;
    struct Node *nxt;
}*start;

struct Node *start2 = NULL;

/**
Description : This function displays the linked list
Param: struct Node
Return: NA
*/
void displayList(struct Node *head)
{
    printf("\nFinal List: ");
    //Logic to itereate through linked list and display data
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->nxt;
    }
}

/** \brief : This function will create a linked list with n
 *          number of nodes.
 * \param : NA
 * \return : NA
 */

void createLinkedList()
{
    //Declare variables and inititalize it
    struct Node *temp = NULL;
    struct Node *newNode = NULL;
    int startNodeVal = 0;
    int numOfNodes = 0;
    int newNodeVal = 0;
    //Condition to check if starting node is NULL
    if(start == NULL)
    {
        start = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value of node 1: ");
        scanf("%d",&startNodeVal);
        start->data = startNodeVal;
        start->nxt = NULL;
    }
    //Assign start node to temp node
    temp = start;
    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&numOfNodes);
    //Logic to create list of n number of nodes
    for(int i = 2;i<=numOfNodes; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value of new node: ");
        scanf("%d",&newNodeVal);
        newNode->data = newNodeVal;
        newNode->nxt = NULL;
        temp->nxt = newNode;
        temp = temp->nxt;
    }
}


void createLinkedList2()
{
    //Declare variables and inititalize it
    struct Node *temp2 = NULL;
    struct Node *newNode2 = NULL;
    int startNodeVal2 = 0;
    int numOfNodes2 = 0;
    int newNodeVal2 = 0;
    //Condition to check if starting node is NULL
    if(start2 == NULL)
    {
        start2 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value of node 1: ");
        scanf("%d",&startNodeVal2);
        start2->data = startNodeVal2;
        start2->nxt = NULL;
    }
    //Assign start node to temp node
    temp2 = start2;
    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&numOfNodes2);
    //Logic to create list of n number of nodes
    for(int i = 2;i<=numOfNodes2; i++)
    {
        newNode2 = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter value of new node: ");
        scanf("%d",&newNodeVal2);
        newNode2->data = newNodeVal2;
        newNode2->nxt = NULL;
        temp2->nxt = newNode2;
        temp2 = temp2->nxt;
    }
}


/**
Description: This function takes starting node and sorts the whole linked list in ascending order
Param: struct Node
Return: NA
*/
void sortList(struct Node *head)
{
    //Declare variables and inititalize it
    int tempData = 0;
    int count  = 0;
    struct Node *tempNode = NULL;
    struct Node *tempHead = NULL;
    tempHead = head;
    //Logic to sorth the libked list in ascending order using nested while loop
    while(tempHead != NULL)
    {
        tempNode = tempHead->nxt;
        /**Logic to start iterating from 2nd node and compare all the node values
        with first node value. If found valid, swap the values.
        */
        while(tempNode != NULL)
        {
            if(tempNode->data <= tempHead->data)
            {
                tempData = tempHead->data;
                tempHead->data = tempNode->data;
                tempNode->data = tempData;
            }
            tempNode = tempNode->nxt;
        }
        tempHead = tempHead->nxt;
    }

}

/**
Description: This function takes starting node and inserts a number in sorted manner.
Param: struct Node
Return: NA
*/
void insertNumber(struct Node *head)
{
    //Declare variables and initialize it
    struct Node *tempHead = NULL;
    struct Node *newNode = NULL;
    int insertNum = 0;
    tempHead = head;
    printf("\nEnter number to be inserted: ");
    scanf("%d",&insertNum);
    //Logic to insert number at beginning it it is the smallest in whole list
    if(insertNum < tempHead->data)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = insertNum;
        newNode->nxt = tempHead;
        start = newNode;
    }
    //Logic to insert number in the remaining list if it is not the smallest
    else
    {
        while(tempHead != NULL)
        {
            /**Logic to check if it is the last node while iterating. This means the number
            is largest in whole list.Add it at last of the list.
            */
            if(tempHead->nxt == NULL)
            {
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = insertNum;
                newNode->nxt = NULL;
                tempHead->nxt = newNode;
                break;
            }
            //Logic to insert the number if the number fits withing the list, in sorted manner.
            if(insertNum < tempHead->nxt->data)
            {
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = insertNum;
                newNode->nxt = tempHead->nxt;
                tempHead->nxt = newNode;
                break;
            }
            tempHead = tempHead->nxt;
        }
    }

}

/**
Description: This function merges two different sorted linked lists into one list.
Param: struct Node, struct Node
Return: NA
*/
void mergeSortedList(struct Node *head1, struct Node *head2)
{
    //declare variables and inititalize it
    struct Node * tempStart = NULL;
    tempStart = head1;
    //Logic to iterate to last node of the first list
    while(tempStart->nxt != NULL)
    {
        tempStart = tempStart->nxt;
    }
    printf("\nTempstrt: %d",tempStart->data);
    //Logic to connect the last node of the first list to first node of second list
    tempStart->nxt = head2;
    //Calling function to sort the merged linked list in ascending order.
    sortList(start);
}

//Main function, calling all other functions
int main()
{
    createLinkedList();
    //displayList(start);
    sortList(start);
    printf("\nSorted list: ");
    displayList(start);
    //printf("\n");
    //insertNumber(start);
    //displayList(start);
    printf("\n");
    createLinkedList2(start2);
    sortList(start2);
    displayList(start2);
    printf("\n");
    mergeSortedList(start,start2);
    displayList(start);

    return 0;
}
