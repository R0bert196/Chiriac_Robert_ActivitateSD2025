#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *elemente;
    int dimensiune;
    int capacitate;
} Heap;

Heap *creareHeap(int capacitate)
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->elemente = (int *)malloc(sizeof(int) * capacitate);
    h->dimensiune = 0;
    h->capacitate = capacitate;
    return h;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapifyUp(Heap *h, int index)
{
    if (index == 0)
        return;

    int parinte = (index - 1) / 2;

    if (h->elemente[index] > h->elemente[parinte])
    {
        swap(&h->elemente[index], &h->elemente[parinte]);
        heapifyUp(h, parinte);
    }
}

void inserare(Heap *h, int valoare)
{
    if (h->dimensiune == h->capacitate)
    {
        return;
    }
    h->elemente[h->dimensiune] = valoare;
    heapifyUp(h, h->dimensiune);
    h->dimensiune++;
}

int main()
{
    Heap *heap = creareHeap(20);

    return 0;
}