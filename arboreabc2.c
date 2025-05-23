#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Farmacie
{
    char *nume;
    char *adresa;
} Farmacie;

typedef struct Nod
{
    Farmacie farmacie;
    struct Nod *stanga;
    struct Nod *dreapta;
} Nod;

int main()
{
    return 0;
}
