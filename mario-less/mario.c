#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    do
    {
       n = get_int("Pick a number between 1 - 8: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int d = n-1; d > i; d = d - 1)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}