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

void afiseazaArticol(Articol a)
{
    printf("Cod articol: %d\n", a.cod);
    printf("Denumire: %s\n", a.denumire);
    printf("Numar produse: %d\n", a.nrProduse);
    printf("Preturi:\n");
    for (int i = 0; i < a.nrProduse; i++)
    {
        printf("Produs %d: %.2f\n", i + 1, a.preturi[i]);
    }
}

void modificaPret(Articol *a, int index, float noulPret)
{
    if (index >= 0 && index < a->nrProduse && noulPret > 0.0)
    {
        a->preturi[index] = noulPret;
        printf("Pret modificat cu success");
    }
    else
    {
        printf("Input invalid");
    }
}

int main()
{

    Articol a = citesteArticol();

    afiseazaArticol(a);

    // Media preturilor
    float media = calculeazaMedia(a);
    printf("Media preturilor: %.2f\n", media);

    int index;
    float noulPret;

    printf("Introduceti indexul produsului pe care doriti sa-l modificati: ");
    scanf("%d", &index);

    printf("Introduceti noul pret: ");
    scanf("%f", &noulPret);
    
    modificaPret(&a, index - 1, noulPret);

    afiseazaArticol(a);

    return 0;
}
