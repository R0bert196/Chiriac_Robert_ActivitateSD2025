#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod
{
    int valoare;
    struct Nod *next;
} Nod;

typedef struct Coada
{
    struct Nod *first;
    struct Nod *last;
} Coada;

void enqueue(Coada *c, int valoare)
{
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    nou->valoare = valoare;
    nou->next = NULL;

    // daca coada goala
    if (c->last == NULL)
    {
        c->last = c->first = nou;
    }
    else
    {
        c->last->next = nou;
        c->last = nou;
    }
}

int main()
{
    return 0;
}