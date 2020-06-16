/*
 ============================================================================
 Name        : Iterative_Merge_Sort.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @description : This function is to display an array elements
 * @param: integer array
 * @return: NA
 */
void displayArray(int arr[], int size)
{
	//Logic to iterate and display elements
	printf("\nFinal Array: ");
	for(int i = 0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}

/**
 * @description : This function is to perform quick sort. First we partition the array
 * and find pivot value. Then we apply quick sort recursively to left and right sub list.
 * @param: integer array, integer, integer, integer
 * @return: NA
 */

void performQuickSort(int arr[], int size, int low, int up)
{

	//Base condition if i crosses j
	if(low >= up)
	{
		return;
	}
	else
	{
		//declare and initialize variables
		int tempQuickSort;
		int pivotVal = low;
		int i = low+1;
		int j = up;

		//Iterate the loop till last value of array
		while(i < j)
		{
			//Logic to increment i till it finds large value than pivot value
			while(i < j)
			{
				if(arr[i] > arr[pivotVal])
				{
					break;
				}
				i++;
			}
			//Logic to decrement j till it finds small value than pivot value
			while(j > i)
			{
				if(arr[j] < arr[pivotVal])
				{
					break;
				}
				j--;
			}
		//logic to swap the elements once proper element is found
		tempQuickSort = arr[i];
		arr[i] = arr[j];
		arr[j] = tempQuickSort;
		}
		//Logic to swap the correct position of pivot after iteration is over.
		tempQuickSort = arr[pivotVal];
		arr[pivotVal] = arr[j-1];
		arr[j-1] = tempQuickSort;

		//Assign pivot value which will be used for recursive call for left and right
		//sub list via quicksort
		pivotVal = j-1;
		//perform quick sort recursively for left and right sub list
		performQuickSort(arr,size,low,pivotVal);
		performQuickSort(arr,size,pivotVal+1,up);

	}
	displayArray(arr,size);
}


int main(void) {

	int a1[] = {50,45,20,60,74,83,43,68,85,10,89,71};
	int size = 12;
	int low = 0;
	int up = size-1;
	performQuickSort(a1,size,low,up);

	return 0;
}
