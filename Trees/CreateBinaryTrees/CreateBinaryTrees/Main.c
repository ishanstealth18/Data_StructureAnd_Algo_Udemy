#include <stdio.h>
#include <stdlib.h>

/**
Created structure for nodes
*/
struct Node
{
	struct Node* nxt;
	struct Node* lChild;
	struct Node* rChild;
	int data;
}*root;

//Inititalized all the nodes
struct Node* tempNode = NULL;
struct Node* parentNode = NULL;
struct Node* par = NULL;
struct Node* ch = NULL;

/**
Description: Code to create binary tree
Param: integer
@return: void
*/
void createBinaryTree(int num)
{
	//struct Node* tempNode = NULL;
	struct Node* newNode = NULL;

	//Create root node if null
	if (root == NULL)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = num;
		root->nxt = NULL;
		root->lChild = NULL;
		root->rChild = NULL;
		tempNode = root;
		printf("\nRoot value: %d", tempNode->data);
	}
	else
	{
		//Logic to iterte through the tree to insert new node at correct position.If number is less than root
		//iterate through left sub tree otherwise iterate through right sub tree.
		while (tempNode != NULL)
		{
			if (num < tempNode->data)
			{
				parentNode = tempNode;
				tempNode = tempNode->lChild;
			}
			else if (num > tempNode->data)
			{
				parentNode = tempNode;
				tempNode = tempNode->rChild;
			}
			else
			{
				printf("\nDuplicate value!!");
				break;
			}
		}
		//Insert right child if number is greater than parent node
		if (num > parentNode->data)
		{
			printf("\nRight Child: Num: %d Node: %d", num, parentNode->data);
			newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = num;
			parentNode->rChild = newNode;
			newNode->nxt = NULL;
			newNode->lChild = NULL;
			newNode->rChild = NULL;
		}
		else
		{
			//If number is less than parent node, insert left child
			printf("\nLeft Child: Num: %d Node: %d", num, parentNode->data);
			newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = num;
			parentNode->lChild = newNode;
			newNode->nxt = NULL;
			newNode->lChild = NULL;
			newNode->rChild = NULL;
		}
	}
}

/**
@description: Function to iterate through a binary tree recursively
@param: structure 
@return: void
*/
void traverseTree(struct Node *n1)
{
	//Base condition, if node is leaf node, return.
	if (n1 == NULL)
	{
		return;
	}
	else
	{
		//Logic to print nodes with different conditions
		if ((n1->lChild) == NULL && (n1->rChild) == NULL)
		{
			printf("\nRoot: %d", n1->data);
		}
		else if (n1->lChild == NULL)
		{
			printf("\nRoot: %d rChild: %d", n1->data, n1->rChild->data);
		}
		else if(n1->rChild == NULL)
		{
			printf("\nRoot: %d lChild: %d", n1->data, n1->lChild->data);
		}
		else
		{
			printf("\nRoot: %d lChild: %d rChild: %d", n1->data, n1->lChild->data, n1->rChild->data);
		}
		//First traverse left subtree and then traverse right subtree
		traverseTree(n1->lChild);
		traverseTree(n1->rChild);
	}
}

/**
@description: Function to find a minimum key from binary tree
@param: structure
@return: integer

*/
int findMinimumKey(struct Node *n2)
{
	//If leaf node found on extreme left side of the binary tree, return the key, that will be minimum
	if ((n2->lChild) == NULL && (n2->rChild) == NULL)
	{
		return n2->data;
	}
	else
	{
		//Traverse continuously on left side
		findMinimumKey(n2->lChild);
	}

}

/**
@description: Function to maximum key from binary tree
@param: structure
@return: void
*/
int findMaximumKey(struct Node* n3)
{
	//If leaf node found on extreme right side of the binary tree, return the key, that will be maximum
	if ((n3->lChild) == NULL && (n3->rChild) == NULL)
	{
		return n3->data;
	}
	else
	{
		//Traverse continuously on right side
		findMaximumKey(n3->rChild);
	}

}

int findKeyFlag = 0;
/*
@description: Function to delete key from binary tree
@param: structure,integer
@return: void
*/
void deleteKey(struct Node* n4, int key)
{
	//Base condition, if key is equal to node, return
	if (n4->data == key)
	{
		findKeyFlag = 1;
		return;
	}
	else
	{
		//Logic to traverse through the binary tree to find key
		if (key < n4->data)
		{
			n4 = n4->lChild;
			deleteKey(n4, key);
		}
		else
		{
			n4 = n4->rChild;
			deleteKey(n4, key);
		}
	}

	//Validation if key not found
	if (findKeyFlag == 0)
	{
		printf("Key not found!!");
	}
	else
	{
		//Logic if key is found it will have 3 conditions 1.A node can have both left and right nodes 2. A node can have only 1
		//node either left or right 3. A node can have no chuld means a leaf node
		if ((n4->lChild) == NULL && (n4->rChild) == NULL)
		{
			printf("\nn4: %d", n4->data);
			free(n4);
		}
		//if node have both left and right child, we first select the right child of that node and then continuously traverse through
		//left node to find the last left node of that sub tree
		else if((n4->lChild) != NULL && (n4->rChild) != NULL)
		{
			ch = n4->rChild;
			while (ch != NULL)
			{
				printf("\nch:%d", ch->data);
				ch = ch->lChild;
				if (ch->lChild->lChild == NULL)
				{
					tempNode = ch;
					break;
				}
			}
			n4->data = tempNode->lChild->data;
			//Logic to handle if the last left node have a right child
			if (tempNode->lChild->rChild != NULL)
			{
				tempNode->lChild = tempNode->lChild->rChild;
			}
			else
			{
				tempNode->lChild = NULL;
			}
			printf("\n2 children: n4: %d", n4->data);
		}
		else
		{
			//Logic in case node has either left or right child
			if ((n4->lChild) == NULL && (n4->rChild) != NULL)
			{
				n4->data = n4->rChild->data;
				printf("Right child: n4: %d", n4->data);
				free(n4->rChild);
			}
			else
			{
				n4->data = n4->lChild->data;
				printf("Left child: n4: %d", n4->data);
				free(n4->lChild);
			}
		}
	}

}

//Main function
int main()
{
	int i = 0;
	int nodeVal = 0;
	int deleteKeyVal = 0;
	while (i<15)
	{
		printf("Enter node value to be inserted: ");
		scanf_s("%d", &nodeVal);
		createBinaryTree(nodeVal);
		tempNode = root;
		printf("\nRoot: %d", tempNode->data);
		i++;
	}
	//traverseTree(tempNode);
	tempNode = root;
	//printf("\n\nMin key: %d", findMinimumKey(tempNode));
	//tempNode = root;
	//printf("\n\nMax key: %d", findMaximumKey(tempNode));
	//tempNode = root;
	printf("\nEnter key to delete: ");
	scanf_s("%d", &deleteKeyVal);
	deleteKey(tempNode,deleteKeyVal);
	tempNode = root;
	traverseTree(tempNode);
	return 0;
}