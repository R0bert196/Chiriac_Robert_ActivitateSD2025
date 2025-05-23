#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod
{
    int valoare;
    struct Nod *next;
} Nod;

void push(Nod **varf, int valoare)
{
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    nou->valoare = valoare;

    Nod *temp = *varf;

    nou->next = temp;

    *varf = nou;
}

int pop(Nod **varf)
{
    if (*varf == NULL)
    {
        return -1;
    }
    Nod *temp = *varf;
    int val = temp->valoare;

    *varf = (*varf)->next;
    free(temp);
    return val;
}

void afiseaza(Nod *varf)
{
    while (varf != NULL)
    {
        printf("%d ", varf->valoare);
        varf = varf->next;
    }
}

int main()
{
    Nod *varf = NULL;

    push(&varf, 25);
    push(&varf, 27);
    push(&varf, 12);
    push(&varf, 5);

    afiseaza(varf);

    return 0;
}