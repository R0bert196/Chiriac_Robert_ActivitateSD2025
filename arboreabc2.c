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

int main()
{
    return 0;
}
