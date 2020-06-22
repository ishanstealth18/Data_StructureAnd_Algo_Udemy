/*
 ============================================================================
 Name        : Radix_Sort.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for linnked list
struct Node{
	int data;
	int qNum;
	struct Node *nxt;
};

/**
 * @description: This function displays elements of an array
 * @param: integer array, integer
 * @return: NA
 */
void displayArray(int a1[], int size)
{
	printf("\nQArray: ");
	//Iterate through all the elements of an array
	for(int i = 0;i<size;i++)
	{
		printf("%d ",a1[i]);
	}
}

/**
 * @description: This function sorts elements of an array
 * @param: integer array, integer
 * @return: NA
 */

void sortQNumArray(int a1[], int size)
{
	int tempVar = 0;
	//Logic to sort number in array
	for(int i = 0 ;i<size; i++)
	{
		for(int j = i+1; j<size;j++)
		{
			if(a1[j] < a1[i])
			{
				tempVar = a1[i];
				a1[i] = a1[j];
				a1[j] = tempVar;
			}
		}
	}
}

/**
 * @description: This function deletes elements of an linked list
 * @param: structure
 * @return: NA
 */

void deleteList(struct Node *n1)
{
	struct Node *current = n1;
	struct Node *next;

	//Logic to delete linked list
	while(current != NULL)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
	free(n1);


}

/**
 * @description: This function performs radix sort or bucket sort
 * @param: integer array, integer, integer, integer
 * @return: NA
 */

void performRadixSort(int arr[], int size, int divider, int msb)
{
	//Declaring and initializing structure
	struct Node *start = NULL;
	struct Node *tempNode = NULL;
	struct Node *tempNode2 = NULL;
	struct Node *newNode = NULL;

	//Base condition
	if(msb < 1)
	{
		return;
	}
	else
	{
		//Logic to create start node if null
		if(start == NULL)
		{
			start = (struct Node*)malloc(sizeof(struct Node));
			start->data = arr[0];
			start->qNum = arr[0]%divider;
			start->nxt = NULL;
		}
		tempNode = start;
		tempNode2 = start;
		//Creating linked list out of an array
		for(int i = 1; i<size; i++)
		{
			newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = arr[i];
			newNode->qNum = arr[i]%divider;
			newNode->nxt = NULL;
			tempNode->nxt = newNode;
			tempNode = tempNode->nxt;
		}
		//Declare variables and initialize it
		int qNumArray[size];
		int x = 0;
		//Logic to store qNum from linked list into another array, so that we can relate elements of linked list using
		//sorted q numbers
		while(tempNode2 != NULL)
		{
			qNumArray[x] = tempNode2->qNum;
			tempNode2 = tempNode2->nxt;
			x++;
		}
		//Sort q numbers
		sortQNumArray(qNumArray,size);

		//Logic to map the elements of linked list using sorted q numbers from array in which we stored previously
		for(int i = 0; i<size; i++)
		{
			tempNode2 = start;
			while(tempNode2 != NULL)
			{
				if(qNumArray[i] == tempNode2->qNum)
				{
					arr[i] = (tempNode2->data);
				}
				tempNode2 = tempNode2->nxt;
			}
		}

		tempNode2 = start;
		//Delete the previous list and all nodes created to have fresh start in 2nd round
		deleteList(tempNode2);
		free(start);
		displayArray(arr,size);
		//Divide every time the number in multiple of 10 (unit, yens, hundred...)
		divider = divider*10;
		msb--;
		//Call recursively till your reach least significant bit
		performRadixSort(arr,size,divider,msb);

	}
}


int main(void) {

	int a1[] = {86,940,519,41,7,5,3,98,22,123};
	int size = 10;
	int mostSigBit = 3;
	int div = 10;
	performRadixSort(a1,size,div,mostSigBit);
	//displayArray(a1,size);
	return 0;
}
