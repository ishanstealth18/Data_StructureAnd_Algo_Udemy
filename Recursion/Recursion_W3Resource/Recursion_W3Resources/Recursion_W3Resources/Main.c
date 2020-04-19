#include <stdio.h>
#include <stdlib.h>

/**
Problem 4
*/
int arr[6];
int x = 0;
int problem4()
{
    
    if (x == 5)
    {
        printf("\na[%d]: %d", x, arr[x]);
        return arr[x];

    }
    else
    {
        printf("\na[%d]: %d", x, arr[x]);
        x++;
        return problem4();
    }
}

//Problem 5//
int count = 0;
int problem5(int num)
{
    
    if (num / 10 == 0)
    {
        count++;
        return count;
    }
    else
    {
        num = num / 10;
        count++;
        return problem5(num);
    }
}

int sum = 0;
int problem6(int num)
{

    if (num / 10 == 0)
    {
        sum = sum + (num % 10);
        return sum;
    }
    else
    {
        sum = sum + (num % 10);
        num = num / 10;
        problem6(num);
        return sum;
    }
}

int problem7(int a, int b)
{
   
    if (b == 0)
    {
        return a;
    }
    else
    {
        return problem7(b, a%b);
    }
}

//Problem 8//
int temp = 0;
int problem8(int* arr8, int size)
{
    if (size == 1)
    {
        if (*arr8 > temp)
        {
            temp = *arr8;
        }
        return temp;
    }
    else
    {
        if (*arr8 > temp)
        {
            temp = *arr8;
        }
        size--;
        problem8((arr8 + 1), size);
        return temp;
    }
}



int problem9(char *str, int size)
{
    if (size == 0)
    {
        printf("%c ", str[size]);
        return 0;   
    }
    else
    {
        printf("%c ", str[size]);
        size--;
        problem9(str,size);
        return 0;
    }
}

int problem10(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * problem10(num - 1);
    }

}

void problem11(int num)
{
    if (num / 2 == 0)
    {
        printf("%d", (num % 2));
        return;
    }
    else
    {
        problem11(num / 2);
        printf("%d", (num % 2));
        return;
    }
}


void problem12(int num, int temp)
{
    if (temp == num)
    {
        printf("\nNumber %d is prime number.", num);
        return;
    }
    else
    {
        if ((num % (temp)) == 0)
        {
            printf("\nNumber %d is not prime!!",num);
            return;
        }
        else
        {
            temp = temp + 1;
            problem12(num,temp);
        }
    }
}

int startNum = 0;
void problem14(int num)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        if (num % 2 == 0)
        {
            printf("\nEven no: %d", num);
        }
        else
        {
            printf("\nOdd no: %d", num);
        }
        problem14(num - 1);
        return;
    }
}

int i16 = 0;
void problem16(char* str, int size)
{
    
    if (str > (str+size))
    {
        return;
    }
    else
    {
        if (*str != (str[size]))
        {
            printf("\nNot palindrome!!");
            return;
        }
        else
        {
            str++;
            size--;
            problem16(str, size);
            printf("\nPalindrome!!!");
            return;
        }
    }
}

int problem17(int num, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return num * problem17(num, p - 1);
    }
}

void problem18(int num)
{
    if (num == 1)
    {
        printf("%d ", num);
        return;
    }
    else
    {
        printf("%d ", num);
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else
        {
            num = (3 * num) + 1;
        }
        return problem18(num);
    }
}

void problem19(char* str1, char *str2, int size)
{
    
    if (size == 0)
    {
        return;
    }
    else
    {
        *str2 = *str1;
        str1++;
        str2++;
        size--;
        problem19(str1, str2, size);
    }

}



int main()
{
    
    /**
    for (int i = 0; i < 6; i++)
    {
        arr[i] = i * 2;
        //printf("%d ",arr[i]);
    }
    //problem4();
    //printf("\nCount: %d", problem5(12345)) ;
    //printf("\nSum Of digits: %d", problem6(1525));
    //printf("\nGCD: %d", problem7(210,45));
    
    int arr8[5];
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        arr8[i] = rand();
        printf("\na[%d]: %d", i, arr8[i]);
    }
    //printf("\nMax num: %d", problem8(arr8, 5));
    
    char string9[50];
    int count9 = 0;
    int i = 1;
    printf("\nEnter any string: ");
    fgets(string9, 50, stdin);
    while (string9[i] != '\0')
    {
        count9++;
        i++;
    }
    problem9(string9, count9 - 1);
    
    int num10 = 0;
    int temp12 = 2;
    printf("\nInput num: ");
    scanf_s("%d", &num10);
    //printf("\nFactorial: %d", problem10(num10));
    //problem11(num10);
    //problem12(num10,temp12);
    
    int num14 = 0;
    printf("\nEnter number: ");
    scanf_s("%d", &num14);
    problem14(num14);
    
    char str16[50];
    printf("\nEnter string: ");
    fgets(str16,50,stdin);
    int count16 = 0;
    int x16 = 0;
    while (str16[x16] != '\0')
    {
        printf("%c ", str16[x16]);
        count16++;
        x16++;
    }
    problem16(str16,count16-1);
    
    int num17 = 0;
    int power17 = 0;
    printf("\nEnter number: ");
    scanf_s("%d", &num17);
    printf("\nEnter power: ");
    scanf_s("%d", &power17);
    printf("\nTotal: %d", problem17(num17, power17));
    
    int num18 = 0;
    printf("\nEnter num: ");
    scanf_s("%d", &num18);
    problem18(num18);
    */
    char str19_1[30];
    char str19_2[30];
    printf("\nEnter first string: ");
    fgets(str19_1, 30, stdin);
    int count19 = 0;
    while (str19_1[count19] != '\0')
    {
        count19++;
    }
    problem19(str19_1, str19_2, count19 - 1);
    printf("\n");
    for (int i = 0; i < count19-1; i++)
    {
        printf("%c ", str19_2[i]);
    }
    


}