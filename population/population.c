#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Starting population size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Ending population size: ");
    }
    while (end < n);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (n < end)
    {
        n = n + (n / 3) - (n / 4);
        years = years + 1;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
