#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct NodAVL
{
    int valoare;
    int inaltime; // Înălțimea subarborelui
    struct NodAVL *stang;
    struct NodAVL *drept;
} NodAVL;

int inaltime(NodAVL *nod)
{
    if (nod == NULL)
        return 0;
    return nod->inaltime;
}

int factorEchilibru(NodAVL *nod)
{
    if (nod == NULL)
        return 0;
    return inaltime(nod->stang) - inaltime(nod->drept);
}

NodAVL *rotireDreapta(NodAVL *radacina)
{
    NodAVL *nouaRacina = radacina->stang;
    radacina->stang = nouaRacina->drept;
    nouaRacina->drept = radacina;
    radacina->inaltime = max(inaltime(radacina->stang), inaltime(radacina->drept)) + 1;
    nouaRacina->inaltime = max(inaltime(nouaRacina->stang), inaltime(nouaRacina->drept)) + 1;
    return nouaRacina;
}

NodAVL *rotireStanga(NodAVL *radacina)
{
    NodAVL *nouaRacina = radacina->drept;
    radacina->drept = nouaRacina->stang;
    nouaRacina->stang = radacina;
    radacina->inaltime = max(inaltime(radacina->stang), inaltime(radacina->drept)) + 1;
    nouaRacina->inaltime = max(inaltime(nouaRacina->stang), inaltime(nouaRacina->drept)) + 1;
    return nouaRacina;
}

NodAVL *rotireDreaptaStanga(NodAVL *radacina)
{
    radacina->stang = rotireStanga(radacina->stang);
    return rotireDreapta(radacina);
}

NodAVL *rotireStangaDreapta(NodAVL *radacina)
{
    radacina->drept = rotireDreapta(radacina->drept);
    return rotireStanga(radacina);
}

NodAVL *inserare(NodAVL *radacina, int valoare)
{
    if (radacina == NULL)
    {
        NodAVL *nod = (NodAVL *)malloc(sizeof(NodAVL));
        nod->valoare = valoare;
        nod->stang = nod->drept = NULL;
        nod->inaltime = 1;
        return nod;
    }

    if (valoare < radacina->valoare)
        radacina->stang = inserare(radacina->stang, valoare);
    else if (valoare > radacina->valoare)
        radacina->drept = inserare(radacina->drept, valoare);

    radacina->inaltime = 1 + max(inaltime(radacina->stang), inaltime(radacina->drept));

    int balance = factorEchilibru(radacina);

    // Daca arborele devine dezechilibrat, rotim

    // Rotire dreapta
    if (balance > 1 && valoare < radacina->stang->valoare)
        return rotireDreapta(radacina);

    // Rotire stanga
    if (balance < -1 && valoare > radacina->drept->valoare)
        return rotireStanga(radacina);

    // Rotire stanga-dreapta
    if (balance > 1 && valoare > radacina->stang->valoare)
        return rotireDreaptaStanga(radacina);

    // Rotire dreapta-stanga
    if (balance < -1 && valoare < radacina->drept->valoare)
        return rotireStangaDreapta(radacina);

    return radacina;
}

void afisareInOrdine(NodAVL *radacina)
{
    if (radacina != NULL)
    {
        afisareInOrdine(radacina->stang);
        printf("%d ", radacina->valoare);
        afisareInOrdine(radacina->drept);
    }
}

int main()
{
    NodAVL *radacina = NULL;

    radacina = inserare(radacina, 10);
    radacina = inserare(radacina, 20);

    printf("Arborele AVL in ordine: ");
    afisareInOrdine(radacina);
    printf("\n");

    return 0;
}