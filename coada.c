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

void enqueue(Coada *c, int valoare)
{
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    nou->valoare = valoare;
    nou->next = NULL;

    if (c->sfarsit == NULL)
    {
        c->inceput = c->sfarsit = nou;
    }
    else
    {
        c->sfarsit->next = nou;
        c->sfarsit = nou;
    }
}

int dequeue(Coada *coada)
{
    if (coada->inceput == NULL)
    {
        return -1;
    }

    Nod *temp = coada->inceput;

    coada->inceput = coada->inceput->next;
    int val = temp->valoare;

    coada->inceput = coada->inceput->next;

    if (coada->inceput == NULL)
        coada->sfarsit = NULL;

    free(temp);
    return val;
}

void afiseazaCoada(Coada *coada)
{
    Nod *temp = coada->inceput;
    printf("Coada: ");
    while (temp != NULL)
    {
        printf("%d ", temp->valoare);
        temp = temp->next;
    }
    printf("\n");
}

int peek(Coada *coada)
{
    if (coada->inceput == NULL)
    {
        printf("Coada este goala!\n");
        return -1;
    }
    return coada->inceput->valoare;
}

int main()
{
    Coada c;
    initCoada(&c);

    enqueue(&c, 20);
    enqueue(&c, 30);

    afiseazaCoada(&c);

    printf("Primul element: %d\n", peek(&c));

    printf("Scos din coada: %d\n", dequeue(&c));
    afiseazaCoada(&c);
    return 0;
}