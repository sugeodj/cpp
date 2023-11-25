#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string input = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentences = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z'))
        {
            letters++;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ')
        {
            words++;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }

    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
