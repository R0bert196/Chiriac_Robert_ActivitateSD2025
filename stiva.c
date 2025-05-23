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
    nou->next = *varf;
    *varf = nou;
}

int pop(Nod **varf)
{
    if (*varf == NULL)
    {
        return -1;
    }
    Nod *temp = *varf;
    *varf = temp->next;
    int val = temp->valoare;
    free(temp);
    return val;
}

void afiseaza(Nod *varf)
{
    while (varf != NULL)
    {
        printf("%d", varf->valoare);
        varf = varf->next;
    }
}



int main()
{
    Nod *stiva = NULL;

    push(&stiva, 33);
    push(&stiva, 3);
    push(&stiva, 22);

    afiseaza(stiva);
    return 0;
}