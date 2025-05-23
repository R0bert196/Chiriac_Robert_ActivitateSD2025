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
    Nod *inceput;
    Nod *sfarsit;
} Coada;

void initCoada(Coada *c)
{
    c->inceput = NULL;
    c->sfarsit = NULL;
}

void enquue(Coada **c, int valoare)
{
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    nou->valoare = valoare;
    nou->next = NULL;

    if ((*c)->sfarsit == NULL)
    {
        (*c)->inceput = (*c)->sfarsit = nou;
    }
    else
    {
        (*c)->sfarsit->next = nou;
        (*c)->sfarsit = nou;
    }
}

int main()
{
    Coada c;
    initCoada(&c);

    // enqueue(&c, 5);
    return 0;
}