#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodDublu
{
    char *valoare;
    NodDublu *next;
    NodDublu *prev;
} NodDublu;

void inserareLaInceput(NodDublu **cap, char *valoare)
{
    NodDublu *nou = (NodDublu *)malloc(sizeof(NodDublu));
    nou->valoare = valoare;

    nou->next = *cap;
    nou->prev = NULL;

    if (*cap != NULL)
    {
        (*cap)->prev = nou;
    }
    *cap = nou;
}

int main()
{

    NodDublu *cap = NULL;

    return 0;
}
