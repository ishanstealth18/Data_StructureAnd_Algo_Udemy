/*
 ============================================================================
 Name        : MergeSortedArrays.c
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
 * @description : This function is to perform a merge sort with 2 different sorted arrays
 * @param: integer array, integer array, integer array
 * @return: NA
 */
void performMergeSortArray(int a1[], int a2[], int a3[])
{
	//declaring and initializing variables
	int j = 0;
	int k = 0;
	//Logic to sort and merge 2 sorted arrays
	for(int i = 0; i<5; i++)
	{
		if(j > 1)
		{
			a3[i] = a2[k];
			k++;

		}
		else if(k > 2)
		{
			a3[i] = a2[k];
			k++;

		}
		else if(a1[j] < a2[k])
		{
			a3[i] = a1[j];
			j++;
		}
		else
		{
			a3[i] = a2[k];
			k++;
		}

	}
	//displayArray(a3);
}

/**
 * @description : This function is to perform a merge sort within an array with 2 sorted sub lists
 * @param: integer array, integer array, integer array
 * @return: NA
 */

void performMergeSortWithinArray(int a1[] , int a2[])
{
	//declaring and initializing variables
	int lw1 = 0;
	int up2 = 13;
	int lw2 = 0;
	int up1 = 0;
	//Logic to find lower and upper bounds from  a given array
	for(int i = 0; i<14; i++)
	{
		if(a1[i+1] < a1[i])
		{
			up1 = i;
			lw2 = i+1;
			break;
		}
	}
	printf("\nUpper bound1: %d",up1);
	printf("\nLower bound2: %d",lw2);

	//Logic to merge 2 sorted arrays within 1 array
	for(int j = 0; j<14; j++)
	{
		//Condition if 1 sub array length is smaller than others
		if((lw1 > up1) && (lw2 <= up2))
		{
			a2[j] = a1[lw2];
			lw2++;
		}
		//Condition if other sub array length is smaller than others
		else if((lw2 > up2) && (lw1 <= up1))
		{
			a2[j] = a1[lw1];
			lw1++;
		}
		else if(a1[lw2] < a1[lw1])
		{
			a2[j] = a1[lw2];
			lw2++;
		}
		else
		{
			//(a1[lw2] > a1[lw1])
			a2[j] = a1[lw1];
			lw1++;
		}

	}
	//displayArray(a2);
}

/**
 * @description : This function is to perform a merge sort with 2 different arrays
 * @param: integer array, integer, integer, integer, integer
 * @return: NA
 */
void mergeSubArray(int a1[], int low, int middle, int high, int size)
{
	//Calculating size of temp arrays
	int arr1Size = middle - low + 1;
	int arr2Size = high - middle;

	//Declaring 2 temp arrays
	int tempArr1[arr1Size];
	int tempArr2[arr2Size];

	//Copying elements of original array into 2 temp arrays from arr[low...medium]
	//and arr[medium+1 to up]
	for(int i = 0; i<arr1Size; i++)
	{
		tempArr1[i] = a1[low+i];
	}
	for(int j = 0; j<arr2Size; j++)
	{
		tempArr2[j] = a1[middle+1+j];
	}

	//Declaring and initializing variables
	int x = 0;
	int y = 0;
	int z = low;

	//Logic to store the small number after comparison from values of
	//2 temp arrays into original array
	while((x<arr1Size) && (y<arr2Size))
	{
		if(tempArr1[x] <= tempArr2[y])
		{
			a1[z] = tempArr1[x];
			x++;
		}
		else
		{
			a1[z] = tempArr2[y];
			y++;
		}
		z++;
	}

	//Condition in case if there are any remaining elements in the temp array
	//to be copied to original array
	while(x<arr1Size)
	{
		a1[z] = tempArr1[x];
		x++;
		z++;
	}
	//Condition in case if there are any remaining elements in the temp array
	//to be copied to original array
	while(y<arr2Size)
	{
		a1[z] = tempArr2[y];
		y++;
		z++;
	}
	displayArray(a1,size);
}

/**
 * @description : This function is to perform a recursive operation to divide array into
 * sub arrays and then call function to merge it after sorting.
 * @param: integer array, integer, integer, integer
 * @return: NA
 */
void performRecursiveMergeSort(int arr[], int size, int lo, int up)
{
	int middle;
	//Base case for recursion
	if(lo == up)
	{
		return;
	}
	else
	{
		//Calculating middle number to divide array into half
		middle = lo + (up - lo)/2;
		//Perform recursive operation from arr[low..middle] and from arr[middle +1...up]
		performRecursiveMergeSort(arr,size,lo,middle);
		performRecursiveMergeSort(arr,size,middle+1,up);
		mergeSubArray(arr,lo,middle,up,size);
	}
}

int main(void) {

	//int a1[] = {9,11,15,31,39,43};
	//int a2[] = {2,10,17,29,40,45,67,79};
	//int a3[14];
	//int a4[] = {9,11,15,31,39,43,2,10,17,29,40,45,67,79};
	//performMergeSortArray(a1,a2,a3);
	//performMergeSortWithinArray(a4,a3);
	int size = 6;
	int a5[] = {6,5,12,10,9,1};

	//displayArray(a5);

	int low = 0;
	int high = size-1;
	performRecursiveMergeSort(a5,size,low,high);
	//displayArray(a5,size);
	return 0;
}
