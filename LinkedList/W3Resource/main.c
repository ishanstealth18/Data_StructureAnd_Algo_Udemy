#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
}*first;

void displayList(struct Node *n)
{
	printf("\nFinal List: ");
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
}

/**
Description: This function creates a new linked list and displays all the elements of the list.
Param: NA
Return: NA
*/
void problem1()
{
	/*Declare variables*/
	int numOfNodes = 0;
	printf("Enter number of nodes: ");
	scanf("%d",&numOfNodes);
	printf("\nNo of nodes: %d",numOfNodes);
	/*Creating the first node manually*/
	first = NULL;
	first = (struct Node*) malloc(sizeof(struct Node));
	if(first == NULL)
	{
		return 1;
	}
	printf("\nEnter value of 1st node: ");
	int firstNodeValue = 0;
	scanf("%d",&firstNodeValue);

	first->data = firstNodeValue;
	first->next = NULL;
	/*Storing first node in temp node*/
	struct Node *node_t = NULL;
	node_t = first;
	/*Logic to create number of nodes automatically and linking them with previous one*/
	for(int i = 2; i<=numOfNodes; i++)
	{

		int nodeValue = 0;
        struct Node *tempNode = NULL;
        tempNode = (struct Node*) malloc(sizeof(struct Node));
        printf("\nEnter %d node value: ",i);
        scanf("%d",&nodeValue);
        tempNode->data = nodeValue;
        tempNode->next = NULL;
        node_t->next = tempNode;
        node_t = tempNode;
	}

	displayList(first);


}

/**
Description: This function reverses a linked list and displays all the elements of the list.
Param: NA
Return: NA
*/
void reverseList(struct Node *n1)
{
	/*Declaring variables*/
	struct Node *prev, *nxt;
	prev = NULL;

	/*Reversing the linked list*/
    while(n1 != NULL)
    {
		/*First store next node in 'nxt'*/
		nxt = n1->next;
		/*Making the link of current node to previous node*/
		n1->next = prev;
		/*Storing the current node address in previous node address, so the next time successor node links to previous node*/
		prev = n1;
		/*Storing next node address in current node address, just to complete whole iteration*/
		n1 = nxt;
    }
    /*Storing previous node in current/last node*/
    n1 = prev;
    /*Print reverse list
    */
    printf("\nReverse List: ");
    while(n1 != NULL)
    {
		printf("%d ",n1->data);
		n1 = n1->next;
    }

}

/**
Description: This function counts number of nodes in a linked list.
Param: NA
Return: NA
*/
void problem3(struct Node *n2)
{
    int count = 0;
	/*Logic to count number of nodes*/
    while(n2 != NULL)
    {
		count++;
		n2 = n2->next;
    }
    /*Print total nodes in linked list*/
    printf("\nTotal Count: %d",count);
}

/**
Description: This function inserts new node in beginning of a linked list.
Param: NA
Return: NA
*/
struct Node *problem4(struct Node *n3)
{
	/*Declare variables*/
    struct Node *temp = NULL;
    temp = (struct Node*) malloc(sizeof(struct Node));
    /*Logic to insert new node in beginning of list*/
    temp->next = n3;
    int newNodeValue = 0;
    printf("\nEnter new node value: ");
    scanf("%d",&newNodeValue);
    temp->data = newNodeValue;
    return temp;
}

/**
Description: This function inserts new node in end of a linked list.
Param: NA
Return: NA
*/
void problem5(struct Node *n4)
{
	/*Logic to reach the last node*/
	while(n4->next != NULL)
    {
        n4 = n4->next;
    }
	/*Create a new node*/
    int nodeValue5 = 0;
    struct Node *temp5 = NULL;
    temp5 = (struct Node*) malloc(sizeof(struct Node));
	/*Link the secondlast node to last node*/
	n4->next = temp5;
	/*Ask user to enter value for last node*/
    printf("\nEnter last node value: ");
    scanf("%d",&nodeValue5);
    /*Assign value to last node*/
    temp5->data = nodeValue5;
    printf("\nLast node: %d",temp5->data);
    /*Link last node to NULL value*/
    temp5->next = NULL;
    displayList(first);
}

/**
Description: This function inserts new node in middle of a linked list.
Param: NA
Return: NA
*/
void problem6(struct Node *n5)
{
	/*Declare variables*/
	int count6 = 1;
	int position6 = 0;
	int nodeValue6 = 0;
	printf("\nEnter position at which node is to be inserted: ");
	scanf("%d",&position6);
	printf("\nEnter node value: ");
	scanf("%d",&nodeValue6);
	/*Logic to iterate through list and find the position before which new node is to be inserted*/
    while(n5->next != NULL)
    {
		if(count6 == (position6-1))
        {
            break;
        }
        count6++;
        n5 = n5->next;
    }
    /*Create a new node*/
    struct Node *temp6 = NULL;
    temp6 = (struct Node*) malloc(sizeof(struct Node));
	/*Assign value to new node*/
    temp6->data = nodeValue6;
    /*Link the new node to its next node*/
    temp6->next = n5->next;
    /*Link current node to new node*/
    n5->next = temp6;
    displayList(first);
}

/**
Description: This function deletes node from the beginning of linked list.
Param: NA
Return: NA
*/
struct Node *problem7(struct Node *n6)
{
	n6 = n6->next;
    return n6;
}

/**
Description: This function deletes node from the end of linked list.
Param: NA
Return: NA
*/
void problem8(struct Node *n7)
{
	/*Logic to reach second last node in the list*/
	while(n7->next->next != NULL)
	{
        n7 = n7->next;
	}
	/*Delete last node by linking second last node to NULL value */
	n7->next = NULL;
	displayList(first);
}


int main()
{
    problem1();
    //reverseList(first);
    //problem3(first);
    first = problem4(first);
    displayList(first);
    problem5(first);
    problem6(first);
    first = problem7(first);
    displayList(first);
    problem8(first);
    return 0;
}
