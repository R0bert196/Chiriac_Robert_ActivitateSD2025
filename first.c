#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Articol
{
    int cod;
    char *denumire;
    int nrProduse;
    float *preturi;
} Articol;

Articol citesteArticol()
{
    Articol a;

    // Citirea codului
    printf("Introduceti codul articolului: ");
    scanf("%d", &a.cod);

    // Citirea denumirii
    a.denumire = (char *)malloc(100 * sizeof(char));
    printf("Introduceti denumirea articolului: ");
    scanf(" %99[^\n]", a.denumire);

    // Citirea numarului de produse
    printf("Introduceti numarul de produse: ");
    scanf("%d", &a.nrProduse);

    // Alocarea dinamica a unui vector de preturi
    a.preturi = (float *)malloc(a.nrProduse * sizeof(float));
    printf("Introduceti preturile produselor:\n");
    for (int i = 0; i < a.nrProduse; i++)
    {
        printf("Pretul produsului %d: ", i + 1);
        scanf("%f", &a.preturi[i]);
    }

    return a;
}

float calculeazaMedia(Articol a)
{
    float suma = 0;
    for (int i = 0; i < a.nrProduse; i++)
    {
        suma += a.preturi[i];
    }
    return suma / a.nrProduse;
}

int main() {

    Articol a = citesteArticol();

    // Media preturilor
    float media = calculeazaMedia(a);
    printf("Media preturilor: %.2f\n", media);

    return 0;
}

