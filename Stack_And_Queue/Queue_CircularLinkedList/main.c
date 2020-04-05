#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
}*start;

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *temp = NULL;

/**
Description: This function will  display all the elements in the linked list
Param: struct
Return: NA
*/
void displayList(struct Node *head)
{
    struct Node *endNode = NULL;
    endNode = head;
    printf("\nFinal List: ");
    //Logic to iterate through linked list
    while(head->nxt != endNode)
    {
        printf("%d ",head->data);
        head = head->nxt;
        if(head->nxt == endNode)
        {
            printf("%d ",head->data);
            break;
        }
    }
    printf("\nNext element: %d",head->nxt->data);
}

/**
Description: This function will add an element in the circular linked list
Param: integer
Return: NA
*/
void enqueElements(int num)
{
    struct Node *newNode = NULL;
    //Logic to check if start is NULL, if yes allocate memory and assign value
    if(start == NULL)
    {
        start = (struct Node*)malloc(sizeof(struct Node));
        start->data = num;
        start->nxt = NULL;
        //Allocating start node to both front and rear
        front = start;
        rear = start;
    }
    else
    {
        //Logic to create a new node in circular linked list
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        //Linking new node with the first node
        newNode->nxt = front;
        //Link the last node with new node
        rear->nxt = newNode;
        //Increment rear node
        rear = rear->nxt;
    }
}

/**
Description: This function will delete an element from the linked list
Param: NA
Return: NA
*/
void dequeElements()
{
    //Allocating front node to temp
    temp = front;
    printf("\nElement popped: %d",front->data);
    //increment front node
    front = front->nxt;
    free(temp);
    //Link the last node to the first node after deletion
    rear->nxt = front;
}

int main()
{
    //Declare variables and initialize it.
    int operationName = 0;
    int pushElement = 0;
    int popNum = 0;
    int exitValue = 0;

    //Logic to ask user continuously either to push or pop an element. User can
    //exit also from current program.
    while(1)
    {
        printf("\nWant to exit(1= yes/0 = no): ");
        scanf("%d",&exitValue);
        if(exitValue == 1)
        {
            printf("\nExited!!!");
            break;
        }
        else
        {
            //Logic to push an element
            printf("\nEnter operation (0 = push/ 1 = pop): ");
            scanf("%d",&operationName);
            if(operationName == 0)
            {
                printf("\nEnter element to push: ");
                scanf("%d",&pushElement);
                enqueElements(pushElement);
            }
            //Function call to pop an element
            else
            {
                dequeElements();
            }
        }


    }
    //Logic to check if there is no elements in libked list
    if(front == NULL)
    {
        printf("\nNo elements in the list!!!!");
    }
    //Call function to display list
    else
    {
        displayList(front);
    }

    return 0;
}
