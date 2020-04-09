#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_SIZE 10

char arr[Max_SIZE];
int front = -1;
int rear = -1;

void pushElements(char *inp)
{
    int exitFlag = 0;
    if(front == -1)
    {
        front = 0;
    }

    printf("\nUpdated array: ");
    while(*inp != '\0')
    {
        if((*inp == '(') || (*inp == ')') || (*inp == '[') || (*inp == ']')
           || (*inp == '{') || (*inp == '}') )
            {
                rear++;
                arr[rear] = *inp;
            }
        inp++;
        printf("%c ",arr[rear]);
    }

    int i = 0;
    int leftRoundBracketCount = 0;
    int rightRoundBracketCount = 0;
    int leftSquareBracketCount = 0;
    int rightSquareBracketCount = 0;
    int leftCurlyBracketCount = 0;
    int rightCurlyBracketCount = 0;
    printf("\n");
    while(arr[i] != '\0')
    {
        printf("\nFront: %d Rear: %d",front, rear);
        if(arr[i] == '(')
        {
            leftRoundBracketCount++;
        }
        else if(arr[i] == ')')
        {
            rightRoundBracketCount++;
        }
        else if(arr[i] == '[')
        {
            leftSquareBracketCount++;
        }
        else if(arr[i] == ']')
        {
            rightSquareBracketCount++;
        }
        else if(arr[i] == '{')
        {
            leftCurlyBracketCount++;
        }
        else
        {
            rightCurlyBracketCount++;
        }

        i++;
    }

    if((leftRoundBracketCount != rightRoundBracketCount) || (leftSquareBracketCount != rightSquareBracketCount)
        || (leftCurlyBracketCount != rightCurlyBracketCount))
        {
            printf("\nParenthesis check fail!!!");
        }
    else
        {
        printf("\nParenthesis check pass");
        }
}

int main()
{
    char inputStr[10];
    printf("\nEnter input: ");
    scanf("%s",inputStr);
    pushElements(&inputStr);
    return 0;
}
