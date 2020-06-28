/*
 ============================================================================
 Name        : Binary_Search.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @description: This function is used to do binary search using recursive function
 * @param: integer array, integer, integer, integer
 * @return: integer
 */
int binarySearch(int arr[], int searchVal, int lo, int hi)
{
	//Find the middle element
	int middleVal = (lo+hi)/2;
	//Base condition 1: if element is found at middle
	if(arr[middleVal] == searchVal)
	{
		return middleVal;
	}
	//Base  condition 2: if function reaches either lo or hi value in recursive loops
	else if(middleVal == lo || middleVal == hi)
	{
		return -1;
	}
	else
	{
		//Recursive call if element is less than middle value, search in left sublist
		if(searchVal < arr[middleVal])
		{
			binarySearch(arr,searchVal,lo,middleVal-1);
		}
		else
		{
			//Recursive call if element is greater than middle value, search in right sublist
			binarySearch(arr,searchVal,middleVal+1,hi);
		}
	}
}

/**
 * @description: This function is used to call binary function
 * @param: integer array, integer
 * @return: NA
 */
void performBinarySearch(int arr[], int size)
{
	int searchNum = 0;
	printf("\n");
	printf("Enter number to be searched: ");
	scanf("%d",&searchNum);
	int low = 0;
	int high = size-1;
	int indexNum = binarySearch(arr,searchNum,low,high);
	if(indexNum > -1)
	{
		printf("\nValue found at index : %d",indexNum);
	}
	else
	{
		printf("\nValue not found.");
	}

}

int main(void) {

	int a1[] = {10,13,25,32,40,46,52,63,70,75,81,84,88,90,93,96,99};
	int size = 17;
	performBinarySearch(a1,size);
	return 0;
}
