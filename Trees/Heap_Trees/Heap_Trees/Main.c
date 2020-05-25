#include <stdio.h>;
#include <stdlib.h>;

//Declaring and initializing global variables
int i = 2;
int tempVal = 0;

/**
description: This function performs operation to check heap priority status. It will make sure parent key is
greater than both it's children keys
param: integer array, integer
return: NA
*/
void restoreUp(int a1[], int index)
{
	//Base condition for recursion
	if (index == 1)
	{
		return;
	}
	else
	{
		//Logic to check if child key is greater than parent, swap it.
		if (a1[index] > a1[(index / 2)])
		{
			printf("\ni/2: %d", a1[index / 2]);
			tempVal = a1[index / 2];
			a1[index / 2] = a1[index];
			a1[index] = tempVal;
		}
		//Divide index by 2 to get parent key
		index = index / 2;
		//recursion
		restoreUp(a1, index);
	}
}

/**
description: This function performs operation to insert new keys in max heap style. Whenever new key is inserted, it will
check both structure and heap priority properties.
param: integer array
return: NA
*/
void insertHeap(int a4[])
{
	//Declaration and initialisation of variables
	a4[0] = 999;
	int insertVal = 0;
	int turn = 1;
	//Logic to insert 14 keys in max heap style.
	while (turn < 14)
	{
		printf("\nEnter value to be inserted: ");
		scanf_s("%d", &insertVal);
		a4[turn] = insertVal;
		//Logic to call function to check heap priority property
		restoreUp(a4, turn);
		turn++;
	}
	

}

/**
description: This function performs operation to convert given array in heap tree.
param: integer array, integer
return: NA
*/
void createHeap(int a[], int size)
{
	//Logic to iterate through every key and check heap priority property
	while (i <= size)
	{
		restoreUp(a, i);
		i++;
	}
}

int restoreTemp = 0;
/**
description: This function performs operation to check heap priority status in top down approach. This function is used while 
deletion in heap. It replaces root node with last index value and then checks for heap priority property in top down fashion.
param: integer array, integer, integer
return: NA
*/
void restoreDown(int a6[], int size, int index)
{
	//Declaring and initializing variables. Here left index and right index will always be in form 2i and 2i+1 (where i is index)
	int leftIndex = 2 * index;
	int rightIndex = (2 * index) + 1;
	//Base condition
	if (leftIndex > size || rightIndex > size)
	{
		return;
	}
	else
	{
		//Case where both children keys are smaller than parent key
		if (a6[index] > a6[rightIndex] && a6[index] > a6[leftIndex])
		{
			return;
		}
		//Case where both children are greater than parent key
		else if(a6[leftIndex] > a6[index] && a6[rightIndex] > a6[index])
		{
			//Logic to check if left index is greater than right index
			if (a6[leftIndex] > a6[rightIndex])
			{
				restoreTemp = a6[index];
				a6[index] = a6[leftIndex];
				a6[leftIndex] = restoreTemp;
				restoreDown(a6, size, leftIndex);
			}
			else
				//Logic to check if left index is smaller than right index
			{
				restoreTemp = a6[index];
				a6[index] = a6[rightIndex];
				a6[rightIndex] = restoreTemp;
				restoreDown(a6, size, rightIndex);
			}
		}
		//Case  where left child is larger than parent key
		else if(a6[leftIndex] > a6[index])
		{
			restoreTemp = a6[index];
			a6[index] = a6[leftIndex];
			a6[leftIndex] = restoreTemp;
			restoreDown(a6, size, leftIndex);
		}
		//Case  where right child is larger than parent key
		else if (a6[rightIndex] > a6[index])
		{
			restoreTemp = a6[index];
			a6[index] = a6[rightIndex];
			a6[rightIndex] = restoreTemp;
			restoreDown(a6, size, rightIndex);
		}
		else
		{
			return;
		}
	}
}

/**
description: This function performs operation to delete a key from heap. Ususally we delete the root key of the heap.
param: integer array
return: NA
*/
void deleteHeap(int a5[])
{
	int startIndex = 1;
	//First copy the last index value to root key
	a5[1] = a5[13];
	//Logic to check heap priority property in top down fashion
	restoreDown(a5, 13, startIndex);
}

int main()
{
	int arr[] = { 9999,20,33,15,6,40,60,45,16,75,10,80,12 };
	int a2[50];
	//createHeap(arr, 13);
	insertHeap(&a2);
	printf("\n");
	for (int i = 0; i < 14; i++)
	{
		printf("%d ", a2[i]);
	}
	deleteHeap(a2);
	printf("\n");
	for (int i = 0; i < 14; i++)
	{
		printf("%d ", a2[i]);
	}
	return 0;
}