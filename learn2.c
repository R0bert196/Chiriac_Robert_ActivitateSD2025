#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// VECTOR

typedef struct
{
    int *elemente;
    int dimensiune;
} Vector;

void inserareFinal(Vector *v, int valoare)
{
    v->elemente = (int *)realloc(v->elemente, (v->dimensiune + 1) * sizeof(int));
    v->elemente[v->dimensiune] = valoare;
    v->dimensiune++;
}

void inserareInceput(Vector *v, int valoare)
{
    v->elemente = (int *)realloc(v->elemente, (v->dimensiune + 1) * sizeof(int));

    for (int i = v->dimensiune; i > 0; i--)
    {
        v->elemente[i] = v->elemente[i - 1];
    }
    v->elemente[0] = valoare;
    v->dimensiune++;
}

void afisareVector(Vector *v)
{
    for (int i = 0; i < v->dimensiune; i++)
    {
        printf("%d", v->elemente[i]);
    }
    printf("\n");
}

// MATRICE

int **creareMatriceDinamica(int linii, int coloane)
{
    int **matrice = (int **)malloc(sizeof(int *) * linii);
    for (int i = 0; i < linii; i++)
    {
        matrice[i] = (int *)malloc(sizeof(int) * coloane);
    }
    return matrice;
}

void afisareMatrice(int **m, int linii, int coloane)
{
    for (int i = 0; i < linii; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

void inserareInMatrice(int **matrice, int linie, int coloana, int valoare)
{
    matrice[linie][coloana] = valoare;
}

// LINKED LIST

typedef struct Nod
{
    int valoare;
    struct Nod *next;
} Nod;

void inserareLaInceputLL(Nod **cap, int valoare)
{
    Nod *nodNou = (Nod *)malloc(sizeof(Nod));
    nodNou->valoare = valoare;
    nodNou->next = *cap;
    *cap = nodNou;
}

void afisareLL(Nod *cap)
{
    while (cap)
    {
        printf("%d", cap->valoare);
        cap = cap->next;
    }
    printf("\n");
}

int main()
{
    // VECTOR
    Vector v;
    v.dimensiune = 0;
    v.elemente = NULL;

    inserareInceput(&v, 10);
    inserareInceput(&v, 13);
    inserareInceput(&v, 23);

    afisareVector(&v);

    inserareFinal(&v, 999);

    afisareVector(&v);

    free(v.elemente);

    // MATRICE
    int **matrice = creareMatriceDinamica(3, 4);

    inserareInMatrice(matrice, 0, 0, 2);
    inserareInMatrice(matrice, 0, 2, 2);
    inserareInMatrice(matrice, 2, 3, 2);

    afisareMatrice(matrice, 3, 4);

    // LINEKDLIST

    Nod *lista = NULL;
    inserareLaInceputLL(&lista, 33);
    inserareLaInceputLL(&lista, 3);
    inserareLaInceputLL(&lista, 32);

    afisareLL(lista);

    return 0;
}
