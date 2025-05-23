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

int main()
{
    Nod *stiva = NULL;
    return 0;
}