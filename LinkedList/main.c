#include <stdio.h>
#include <stdlib.h>

/*This is structure called Node which contains fields necessary to create a node*/
struct Node
{
	int info;
	struct Node* link;
}*start;

/**
Description: This function takes starting node as input parameters and traverse the whole
linked list. Also it prints out all the node values.
Param: pointer of type struct
Return: NA
*/
void traverseList(struct Node* n)
{
	while(n  != NULL)
	{
		printf("%d ",n->info);
		n = n->link;
	}
}

/**
Description: This function takes an integer number to create that many nodes. This function
first creates a node and allocates memory and data to it. Also it points to NULL value.
Then using for loop it creates remaining nodes and allocates data to it. All this nodes are
then linked to previous nodes by linking them.
Param: integer n
Return: NA
*/
void createList(int n)
{
	struct Node *temp, *newNode;
	int data = 0;
	start = (struct Node *) malloc( sizeof(struct Node) );

	if(start == NULL)
	{
		printf("\nNo memory allocated.");
	}
	printf("\nEnter data for node 1: ");
	printf("\nValue of node 1: ");
	scanf("%d",&data);

	start->link = NULL;
	start->info = data;

	temp = start;
	for(int i = 2; i<=n; i++)
	{

		newNode = (struct Node *) malloc( sizeof(struct Node) );

		 if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

		printf("\nValue of node %d: ",i);
		scanf("%d",&data);
		newNode->info = data;
		newNode->link = NULL;

		temp->link = newNode;
		temp = temp->link;
	}

}

/**
Description: This function takes starting node and integer number to search as input parameters and traverse the whole
linked list to search it. When it finds integer it breaks the loop and returns.
Param: integer number num and starting node of type struct.
Return: NA
*/
void searchNumMethod(int num, struct Node *startNode)
{
	int searchFlag = 0;
	while(startNode != NULL)
	{
		if(startNode->info == num)
		{
			searchFlag = 1;
			printf("\n%d is present in the list.",num);
			break;
		}
		//printf("\n%d",startNode->info);
		startNode = startNode->link;
	}
	if(searchFlag == 0)
	{
		printf("%d is not present in the list.",num);
	}
}

/**
Description: This function add a new node at beginning of the linked list.
Param: NA
Return: NA
*/
void insertAtBeginning()
{
	/*Declare variables for new node to be inserted*/
	int data1 = 0;
	struct Node* temp1;
	printf("\nEnter value for node at start: ");
	scanf("%d",&data1);
	/*Allocating space for new node*/
	temp1 = (struct Node *) malloc( sizeof(struct Node) );
	/*Storing data in the new node*/
	temp1->info = data1;
	/*Linking the new node with the start node as address of second node is stored in start node*/
	temp1->link = start;
	printf("Updated list: ");
	traverseList(temp1);
	insertAtEnd(temp1);
	traverseList(temp1);
	insertNodeBetween(temp1);
	traverseList(temp1);
	deleteNodeBetween(temp1);
	traverseList(temp1);
	reverseList(temp1);
}

/**
Description: This function add a new node at end of the linked list.
Param: variable of type Node
Return: NA
*/
void insertAtEnd(struct Node* n2)
{
	/*Declare variables for new node to be inserted*/
	int data2 = 0;
	struct Node* temp2;
	printf("\nEnter value for last node: ");
	scanf("%d",&data2);
	/*Allocating space for new node*/
	temp2 = (struct Node *) malloc( sizeof(struct Node) );
	temp2->info = data2;
	/*Logic to fins the end of the linked list where new node can be inserted*/
    while(n2->link != NULL)
    {
        n2 = n2->link;
    }
    /*Linking second last node to last node*/
    n2->link = temp2;
    /*Linking the last node to NULL value as it do not contain any links further*/
    temp2->link = NULL;
}

/**
Description: This function add a new node between 2 nodes in linked list.
Param: variable of type Node
Return: NA
*/
void insertNodeBetween(struct Node* n3)
{
	/*Declare variables for new node to be inserted*/
	int data3 = 0;
	int insertNum = 0;
	struct Node* temp3;
	printf("\nAfter what value number is to be inserted? ");
	scanf("%d",&insertNum);
	printf("\nEnter value for node in between: ");
	scanf("%d",&data3);
	/*Allocating space for new node*/
	temp3 = (struct Node *) malloc( sizeof(struct Node) );
	temp3->info = data3;
	/*Logic to find node after which node is to be inserted*/
	while(n3->info != insertNum)
	{
		n3 = n3->link;
	}
	/*Linking the new node to the next node*/
	temp3->link = n3->link;
	/*Linking the previous node with the current node*/
	n3->link = temp3;
}

/**
Description: This function deletes a node from a linked list.
Param: variable of type Node
Return: NA
*/
void deleteNodeBetween(struct Node* n4)
{
	/*Declareing variables*/
	int deleteNum = 0;
	printf("\nInput value of node to be deleted: ");
	scanf("%d",&deleteNum);
	/*Logic to find the node, to delete the next node after that*/
	while(n4->link->info != deleteNum)
	{
		n4 = n4->link;
	}
	/*Logic to link the current node with next to next node bypassing the node to be deleted*/
	n4->link = n4->link->link;
}

/**
Description: This function reverses a linked list.
Param: variable of type Node
Return: NA
*/
void reverseList(struct Node* n5)
{
    /*Declare variables*/
    struct Node *prev,*nxt;
    prev = NULL;
    /*Logic to make the existing linked list in reverse order*/
    while(n5->link != NULL)
    {
        nxt = n5->link;
        n5->link = prev;
        prev = n5;
        n5 = nxt;

    }
    n5->link = prev;
    /*Print linked list*/
    printf("\nReverse order: ");
    while(n5 != NULL)
    {
        printf("%d ",n5->info);
        n5 = n5->link;
    }


}

int main() {

	/*Declare variables*/
	int numOfNodes = 0;
	int searchNum = 0;
	printf("Enter number of nodes: ");
	scanf("%d",&numOfNodes);
	/*Calling methods to create node, traverse list and search element*/
	createList(numOfNodes);
	traverseList(start);
	insertAtBeginning();


	printf("\nNumber to be searched: ");
	scanf("%d",&searchNum);
	searchNumMethod(searchNum,start);
}
