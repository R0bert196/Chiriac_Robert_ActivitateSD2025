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

void afiseaza(Coada *c)
{
    Nod *temp = c->first;
    while (temp != NULL)
    {
        printf("%d \n", temp->valoare);
        temp = temp->next;
    }
}

int dequeue(Coada *c)
{
    if (c->first == NULL)
    {
        return -1;
    }

    Nod *temp = c->first;
    c->first = c->first->next;

    if (c->first == NULL)
    {
        c->last = NULL;
    }
    int val = temp->valoare;
    free(temp);
    return val;
}

int main()
{
    Coada *c = malloc(sizeof(Coada));
    c->first = NULL;
    c->last = NULL;
    enqueue(c, 12);
    enqueue(c, 14);
    enqueue(c, 13);
    afiseaza(c);
    int found = dequeue(c);
    printf("%d\n", found);
    afiseaza(c);
    return 0;
}