#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodABC
{
    int valoare;
    struct NodABC *stang;
    struct NodABC *drept;
} NodABC;

NodABC *creareNod(int valoare)
{
    NodABC *nod = (NodABC *)malloc(sizeof(NodABC));
    nod->valoare = valoare;
    nod->stang = NULL;
    nod->drept = NULL;
    return nod;
}

void inserare(NodABC **radacina, int valoare)
{
    if (*radacina == NULL)
    {
        *radacina = creareNod(valoare);
        return;
    }
    if (valoare < (*radacina)->valoare)
    {
        // insert la stanga
        inserare(&(*radacina)->stang, valoare);
    }
    else if (valoare > (*radacina)->valoare)
    {
        // insert la dreapta
        inserare(&(*radacina)->drept, valoare);
    }
}

int main()
{
    NodABC *radacina = NULL;

    // inserare(&radacina, 50);
    return 0;
}