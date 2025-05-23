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

void afisare(NodABC *radacina)
{
    if (radacina != NULL)
    {
        afisare(radacina->stang);
        printf("%d", radacina->valoare);
        afisare(radacina->drept);
    }
}

NodABC *cautare(NodABC *radacina, int valoare)
{
    if (radacina == NULL || radacina->valoare == valoare)
    {
        return radacina;
    }
    if (valoare < radacina->valoare)
    {
        return cautare(radacina->stang, valoare);
    }
    if (valoare > radacina->valoare)
    {
        return cautare(radacina->drept, valoare);
    }
}

int main()
{
    NodABC *radacina = NULL;

    inserare(&radacina, 50);
    inserare(&radacina, 30);
    inserare(&radacina, 70);
    inserare(&radacina, 20);

    afisare(radacina);

    NodABC *gasit = cautare(radacina, 40);
    if (gasit != NULL)
    {
        printf("Valoarea %d a fost gasita.\n", gasit->valoare);
    }
    else
    {
        printf("Valoarea nu a fost gasita.\n");
    }

    return 0;
}