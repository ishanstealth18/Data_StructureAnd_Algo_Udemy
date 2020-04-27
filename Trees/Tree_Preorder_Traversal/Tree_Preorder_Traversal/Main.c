#include <stdlib.h>
#include <stdio.h>

struct  node
{
	struct node* lChild;
	char info; 
	struct node* rChild;
}*root;

void createTree()
{
	root = (struct node*)malloc(sizeof(struct node));
	struct node* nodeA = NULL;
	struct node* nodeX = NULL;
	struct node* nodeS = NULL;
	struct node* nodeE = NULL;
	nodeA = (struct node*)malloc(sizeof(struct node));
	nodeX = (struct node*)malloc(sizeof(struct node));
	nodeS = (struct node*)malloc(sizeof(struct node));
	nodeE = (struct node*)malloc(sizeof(struct node));
	nodeA->info = 'A';
	nodeX->info = 'X';
	nodeS->info = 'S';
	nodeE->info = 'E';
	root->info = 'T';
	root->lChild = nodeA;
	root->rChild = nodeX;
	nodeA->lChild = nodeS;
	nodeA->rChild = nodeE;
	root->rChild = nodeX;
	nodeS->lChild = NULL;
	nodeS->rChild = NULL;
	nodeE->lChild = NULL;
	nodeE->rChild = NULL;
	nodeX->lChild = NULL;
	nodeX->rChild = NULL;

}


void printPostorderTree(struct node* n3)
{
	if (n3 == NULL)
	{
		return;
	}
	else
	{
		printPostorderTree(n3->lChild);
		printPostorderTree(n3->rChild);
		printf("%c ", n3->info);
		return;
	}

}

void printInorderTree(struct node* n2)
{
	if (n2 == NULL)
	{
		return;
	}
	else
	{
		printInorderTree(n2->lChild);
		printf("%c ", n2->info);
		printInorderTree(n2->rChild);
		return;
	}
}


int countTreeHeight(struct node* n5)
{
	int lHeight,rHeight = 0;

	if (n5 == NULL)
	{
		return;
	}

}

void printPreOrderTree(struct node *n1)
{
	if (n1 == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", n1->info);
		printPreOrderTree(n1->lChild);
		printPreOrderTree(n1->rChild);
		return;
	}
}

int main()
{
	createTree();
	//printPreOrderTree(root);
	//printInorderTree(root);
	//printPostorderTree(root);
	countTreeHeight(root);
	return 0;
}
