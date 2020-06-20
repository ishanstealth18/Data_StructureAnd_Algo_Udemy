/*
 ============================================================================
 Name        : Heap_Sort.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * d
 */
void displayArray(int a1[], int size)
{
	printf("\nFinal array: ");
	for(int i = 1; i<size; i++)
	{
		printf("%d ",a1[i]);
	}
}

/**
description: This function performs operation to check heap priority status in top down approach. This function is used while
deletion in heap. It replaces root node with last index value and then checks for heap priority property in top down fashion.
param: integer array, integer, integer
return: NA
*/
void createHeap(int a1[], int index, int size)
{
	int tempHeap;
	int leftIndex = 2*index;
	int rightIndex = (2*index)+1;
	if((leftIndex > size) || (rightIndex > size))
	{
		return;
	}
	else
	{
		if((a1[index] > a1[leftIndex]) && (a1[index] > a1[rightIndex]))
		{
			return;
		}
		else if(a1[leftIndex] > a1[index] && a1[rightIndex] > a1[index])
		{
			if(a1[leftIndex] > a1[rightIndex])
			{
				tempHeap = a1[index];
				a1[index] = a1[leftIndex];
				a1[leftIndex] = tempHeap;
				createHeap(a1,leftIndex,size);
			}
			else
			{
				tempHeap = a1[index];
				a1[index] = a1[rightIndex];
				a1[rightIndex] = tempHeap;
				createHeap(a1,rightIndex,size);
			}
		}
		else if(a1[leftIndex] > a1[index])
		{
			tempHeap = a1[index];
			a1[index] = a1[leftIndex];
			a1[leftIndex] = tempHeap;
			createHeap(a1,leftIndex,size);
		}
		else if(a1[rightIndex] > a1[index])
		{
			tempHeap = a1[index];
			a1[index] = a1[rightIndex];
			a1[rightIndex] = tempHeap;
			createHeap(a1,rightIndex,size);
		}
		else
		{
			return;
		}
	}
}

/**
description: This function sort the array using heap sort
param: integer array, integer, integer
return: NA
*/
void sortHeap(int arr[], int index, int size)
{
	int tempSort = 0;
	//Logic to do restore down process on heap tree
	while(size > 1)
	{
		//Logic to replace the top element with the lowest one and then perform
		//restore down process
		tempSort = arr[index];
		arr[index] = arr[size];
		arr[size] = tempSort;
		//restore down process
		createHeap(arr,1,size-1);
		size--;
	}

}

int main(void) {

	int a1[] = {999,20,30,13,5,40,65,43,18,70,89};
	int size = 11;

	int ind = 5;
	while(ind >0 )
	{
		createHeap(a1,ind,size);
		ind--;
	}
	displayArray(a1,size);
	sortHeap(a1,ind+1,size-1);
	displayArray(a1,size);

	return 0;
}
