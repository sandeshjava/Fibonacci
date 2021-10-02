#include <stdio.h>
#define MAX 4500

char array_1[MAX], array_2[MAX], result[MAX];

void namo(void)
{
    int i, t;
    for (i = 0; i < MAX; i++)
        result[i] = array_1[i] + array_2[i];

    for (i = MAX - 1; i > 0; i--)
    {
        if (result[i] > 9)
        {
            t = result[i];
            result[i] %= 10;
            result[i - 1] += (t / 10);
        }
    }
}

int main()
{
    int a;
    printf("Enter input n to calculate nth fibonacci number: ");
    scanf("%d", &a);
    int i, j, tag = 0;
    for (i = 0; i < MAX; i++)
        array_1[i] = array_2[i] = result[i] = 0;

    array_2[MAX - 1] = 1;

    for (i = 0; i <= a; i++)
    {
        namo();

        if (i == a - 2)
            break;

        for (j = 0; j < MAX; j++)
            array_1[j] = array_2[j]; 

        for (j = 0; j < MAX; j++)
            array_2[j] = result[j]; 
    }

    for (i = 0; i < MAX; i++)
    {
        if (tag || result[i])
        {
            tag = 1;
            printf("%d", result[i]);
        }
    }

    return 1;
}