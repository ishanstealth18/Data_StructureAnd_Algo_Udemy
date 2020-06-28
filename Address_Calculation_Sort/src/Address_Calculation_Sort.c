/*
 ============================================================================
 Name        : Address_Calculation_Sort.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	float data;
	int setNum;
	struct Node *nxt;
	struct Node *prev;
}*start = NULL;

struct Node *newNode = NULL;
struct Node *tempNode = NULL;
struct Node *tempNode1 = NULL;

void displayArray(int a1[], int size)
{
	printf("\nFinal Array: ");
	for(int i = 0; i<size; i++)
	{
		printf("%d ",a1[i]);
	}
}

void findFX(float arr[], int size)
{
	int fxArray[size];
	float tempLargeVal = 0.00;
	for(int i = 0; i<size; i++)
	{
		if(arr[i] > tempLargeVal)
		{
			tempLargeVal = arr[i];
		}
	}
	printf("\nLArgest val: %f\n",tempLargeVal);

	for(int i = 0 ;i<size; i++)
	{
		fxArray[i] = (arr[i]/tempLargeVal)*5.00;

	}
	displayArray(fxArray,size);

	if(start == NULL)
	{
		start = (struct Node*)malloc(sizeof(struct Node));
		start->setNum = fxArray[0];
		start->data = arr[0];
		start->nxt = NULL;
		//start->prev = NULL;
	}
	tempNode = start;
	for(int i = 1; i<size; i++)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->setNum = fxArray[i];
		newNode->data = arr[i];
		tempNode->nxt = newNode;
		newNode->nxt = NULL;
		tempNode = tempNode->nxt;
	}

	tempNode = start;

	int setVal = 0;
	int nodeVal = 0;
	while(tempNode != NULL)
	{
		tempNode1 = tempNode->nxt;
		while(tempNode1 != NULL)
		{
			if(tempNode1->data <= tempNode->data)
			{
				setVal = tempNode1->setNum;
				nodeVal = tempNode1->data;
				tempNode1->setNum = tempNode->setNum;
				tempNode1->data = tempNode->data;
				tempNode->setNum = setVal;
				tempNode->data = nodeVal;
			}
			tempNode1 = tempNode1->nxt;
		}
		tempNode = tempNode->nxt;
	}
	printf("\n");

	while(start != NULL)
	{
		printf("|%d,%f| ->",start->setNum,start->data);
		start = start->nxt;
	}


}

void performAddressCalculationSort(int a1[],int size)
{

	findFX(a1,size);
}

int main(void) {
	float a1[] = {360.00,289.00,589.00,467.00,699.00,75.00,11.00,700.00,133.00,233.00,6.00};
	int size = 11;
	performAddressCalculationSort(a1,size);
	return 0;
}
