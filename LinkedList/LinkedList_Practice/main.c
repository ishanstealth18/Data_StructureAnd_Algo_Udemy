#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*start;

void createList(int nodeNum)
{

}

void findMiddle()
{

}

int main()
{
    int numOfNode = 0;
    printf("Enter number of nodes: ");
    scanf("%d",numOfNode);
    createList(numOfNode);
    return 0;
}
