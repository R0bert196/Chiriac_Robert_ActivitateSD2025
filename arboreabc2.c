#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Farmacie
{
    char *nume;
    char *adresa;
} Farmacie;

typedef struct NodABC
{
    Farmacie farmacie;
    struct NodABC *stanga;
    struct NodABC *dreapta;
} NodABC;

NodABC *creareNod(char *numeF, char *adresaF)
{
    NodABC *nod = (NodABC *)malloc(sizeof(NodABC));
    nod->farmacie.adresa = (char *)malloc(strlen(adresaF) + 1);
    nod->farmacie.nume = (char *)malloc(strlen(numeF) + 1);

    strcpy(nod->farmacie.adresa, adresaF);
    strcpy(nod->farmacie.nume, numeF);

    nod->stanga = nod->dreapta = NULL;

    return nod;
}

void inserare(NodABC **radacina, char *nume, char *adresa)
{
    if (*radacina == NULL)
    {
        *radacina = creareNod(nume, adresa);
        return;
    }
    if (strcmp(nume, (*radacina)->farmacie.nume) < 0)
    {
        inserare(&(*radacina)->stanga, nume, adresa);
    }
    else
    {
        inserare(&(*radacina)->dreapta, nume, adresa);
    }
}

void afisare(NodABC *nod)
{
    if (nod != NULL)
    {
        afisare(nod->stanga);
        printf("Nume farmacie: %s, adresa: %s ", nod->farmacie.nume, nod->farmacie.adresa);
        printf("\n");
        afisare(nod->dreapta);
    }
}

void citireDinFisier(NodABC **radacina, const char *numeFisier)
{
    FILE *f = fopen(numeFisier, "r");
    if (!f)
    {
        return;
    }

    char linie[256];
    while (fgets(linie, sizeof(linie), f))
    {
        char *token = strtok(linie, ",");
        char *nume = token;

        token = strtok(NULL, ",");
        char *adresa = token;

        inserare(radacina, nume, adresa);
    }

    fclose(f);
}

int main()
{
    NodABC *radacina = NULL;

    citireDinFisier(&radacina, "farmacii.txt");

    printf("Farmaciile in ordine alfabetica:\n");
    afisare(radacina);
    return 0;
}
