/*
 ============================================================================
 Name        : Binary_Sorting.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Creating structure for linked list
struct Node{
	struct Node* right;
	struct Node* left;
	int data;
}*start;

//Declare and initialize nodes
struct Node *newNode = NULL;
struct Node *parentNode = NULL;
struct Node *tempNode = NULL;

/**
 * description: This function creates a binary tree with numbers inserted
 * param: integer
 * return:NA
 */
void createBinaryTree(int val)
{
	//Creating root node
	if(start == NULL)
	{
		start = (struct Node*)malloc(sizeof(struct Node));
		start->data = val;
		start->right = NULL;
		start->left = NULL;
	}
	else
	{
		//Logic to iterate through left or right sub tree depending on the values
		tempNode = start;
		while(tempNode != NULL)
		{
			if(val < tempNode->data)
			{
				parentNode = tempNode;
				tempNode = tempNode->left;
			}
			else
			{
				parentNode = tempNode;
				tempNode = tempNode->right;
			}
		}
		//Once iterator reaches null value, the below logic will allocate new node to be inserted
		//at correct position
		if(val < parentNode->data)
			{
				newNode = (struct Node*)malloc(sizeof(struct Node));
				parentNode->left = newNode;
				newNode->data = val;
				newNode->left = NULL;
				newNode->right = NULL;

			}
			else
			{
				newNode = (struct Node*)malloc(sizeof(struct Node));
				parentNode->right = newNode;
				newNode->data = val;
				newNode->left = NULL;
				newNode->right = NULL;

			}
	}

}

/**
 * description: This function traverse a binary tree
 * param: structure
 * return:NA
 */
void traverseBinaryTree(struct Node *n1)
{
	//Base condition
	if(n1 == NULL)
	{
		return;
	}
	else
	{
		traverseBinaryTree(n1->left);
		printf("%d ",n1->data);
		traverseBinaryTree(n1->right);
	}

}

int main(void) {

	//,56,38,63,19,41,32,77,59
	int a1[] = {47,35,29,56,38,63,19,41,32,77,59};
	int size = 11;
	for(int i = 0 ;i<size; i++)
	{
		createBinaryTree(a1[i]);
	}
	traverseBinaryTree(start);
	return 0;
}
