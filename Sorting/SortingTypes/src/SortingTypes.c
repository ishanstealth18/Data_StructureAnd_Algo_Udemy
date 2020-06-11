/*
 ============================================================================
 Name        : SortingTypes.c
 Author      : Ishan Kansara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

# include <stdio.h>
#include <stdlib.h>

void displayArray(int a2[], int size)
{
	printf("\nFinal Array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a2[i]);
	}
}



void performSelectionSort(int a1[], int size)
{
	int tempVal = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a1[j] < a1[i])
			{
				tempVal = a1[i];
				a1[i] = a1[j];
				a1[j] = tempVal;
			}
		}
	}
}

int validateArray(int a4[], int size)
{
	int flag = 0;
	for (int i = 0; i < size-1; i++)
	{
		if (a4[i] > a4[i + 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void performBubbleSort(int a3[], int size)
{
	int checkFlag = validateArray(a3, size);
	if (checkFlag == 0)
	{
		return;
	}
	else
	{
		int bubbleTemp = 0;
		for (int i = 0; i < size-1; i++)
		{
			if (a3[i + 1] < a3[i])
			{
				bubbleTemp = a3[i];
				a3[i] = a3[i + 1];
				a3[i + 1] = bubbleTemp;
			}
		}
		performBubbleSort(a3, size);
	}
}

void performInsertionSort(int a6[], int size)
{
	int insertTemp = 0;
	int x = 0;
	for (int i = 1; i < size; i++)
	{
		x = i;
		for (int j = (i - 1); j >= 0; j--)
		{
			if (a6[x] < a6[j])
			{
				insertTemp = a6[j];
				a6[j] = a6[x];
				a6[x] = insertTemp;
				x--;
			}
		}
		displayArray(a6, size);
	}
}


void performShellSort(int a7[], int size, int increment)
{
	int shellTemp = 0;

	while (increment > 0)
	{
		if(increment == 1)
		{
			performInsertionSort(a7,size);
		}
		else
		{
			for (int i = 0; i <= (increment-1); i++)
			{
				for (int j = (i+increment); j < size; j=j+increment)
				{
					for (int k = j; k >= i; k= (k-increment))
					{
						if(k == i)
						{
							break;
						}
						else if(a7[k] < a7[k-increment])
						{
							shellTemp = a7[k - increment];
							a7[k - increment] = a7[k];
							a7[k] = shellTemp;
						}
					}
				}
				displayArray(a7, size);
			}
		}
		increment = increment - 2;
	}
}

int main()
{
	int arr1[] = { 21,60,2,7,8,11,1,19,9,4,48,3,5,17,16,13,59 };

	printf("\nInitial Array: ");
	//displayArray(arr1, 7);
	//performSelectionSort(arr1,6);
	//displayArray(arr1, 6);
	//performBubbleSort(arr1, 6);
	//performInsertionSort(arr1, 6);
	performShellSort(arr1, 17, 5);
	displayArray(arr1, 17);
	return 0;
}
