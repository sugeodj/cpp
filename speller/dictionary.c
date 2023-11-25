// Implements a dictionary's functionality

#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;
unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if(strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int index = 0;
    unsigned int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        index = index + 37 * tolower(word[i]);
    }
    index = index % N;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary,"r");
    if (file == NULL)
    {
        return false;
    }
    char aWord[LENGTH + 1];
    while(fscanf(file,"%s", aWord) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n -> word, aWord);
        n -> next = NULL;
        int index = hash(aWord);

        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            n -> next = table[index];
            table[index] = n;
        }
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    while (table[i] != NULL)
    {
        node *tmp = table[i] ->next;
        free(table[i]);
        table[i] = tmp;
    }
    return true;
}
