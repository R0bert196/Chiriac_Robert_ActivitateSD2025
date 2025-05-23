#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nume;
    char *adresa;
} Farmacie;

typedef struct NodDublu
{
    Farmacie farmacie;
    struct NodDublu *next;
    struct NodDublu *prev;
} NodDublu;

void inserareLaInceput(NodDublu **cap, char *nume, char *adresa)
{
    NodDublu *nou = (NodDublu *)malloc(sizeof(NodDublu));

    nou->farmacie.nume = (char *)malloc(strlen(nume) + 1);
    nou->farmacie.adresa = (char *)malloc(strlen(adresa) + 1);

    strcpy(nou->farmacie.nume, nume);
    strcpy(nou->farmacie.adresa, adresa);

    nou->next = *cap;
    nou->prev = NULL;

    if (*cap != NULL)
    {
        (*cap)->prev = nou;
    }
    *cap = nou;
}

void inserareLaFinal(NodDublu **cap, char *nume, char *adresa)
{
    NodDublu *nou = (NodDublu *)malloc(sizeof(NodDublu));

    nou->farmacie.nume = (char *)malloc(strlen(nume) + 1);
    nou->farmacie.adresa = (char *)malloc(strlen(adresa) + 1);

    strcpy(nou->farmacie.nume, nume);
    strcpy(nou->farmacie.adresa, adresa);

    if (*cap == NULL)
    {
        nou->next = NULL;
        nou->prev = NULL;
        *cap = nou;
        return;
    }

    NodDublu *temp = *cap;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nou;
    nou->prev = temp;
    nou->next = NULL;
}



void afisare(NodDublu *cap)
{
    while (cap != NULL)
    {
        printf("%s  %s", cap->farmacie.adresa, cap->farmacie.nume);
        printf("\n");
        cap = cap->next;
    }
}

int main()
{

    NodDublu *cap = NULL;

    inserareLaInceput(&cap, "Catena", "Str. Libertatii 12");
    inserareLaInceput(&cap, "Helpnet", "Str.  12");
    inserareLaFinal(&cap, "Helpnet", "Str.  12");

    afisare(cap);

    return 0;
}
