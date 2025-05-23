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

int main()
{
    return 0;
}