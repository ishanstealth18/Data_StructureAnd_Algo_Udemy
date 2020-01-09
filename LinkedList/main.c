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
		printf("\n%d",n->info);
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


int main() {

	/*Declare variables*/
	int numOfNodes = 0;
	int searchNum = 0;
	printf("Enter number of nodes: ");
	scanf("%d",&numOfNodes);
	/*Calling methods to create node, traverse list and search element*/
	createList(numOfNodes);
	traverseList(start);

	printf("\nNumber to be searched: ");
	scanf("%d",&searchNum);
	searchNumMethod(searchNum,start);

}
