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

void heapifyDown(Heap *h, int index)
{
    int st = 2 * index + 1;
    int dr = 2 * index + 2;
    int max = index;

    if (st < h->dimensiune && h->elemente[st] > h->elemente[max])
    {
        max = st;
    }
    if (dr < h->dimensiune && h->elemente[dr] > h->elemente[max])
    {
        max = dr;
    }

    if (max != index)
    {
        swap(&h->elemente[index], &h->elemente[max]);
        heapifyDown(h, max);
    }
}

int extrageMax(Heap *h)
{
    if (h->dimensiune <= 0)
    {
        printf("Heap-ul este gol.\n");
        return -1;
    }
    int maxim = h->elemente[0];
    h->elemente[0] = h->elemente[h->dimensiune - 1];
    h->dimensiune--;
    heapifyDown(h, 0);
    return maxim;
}

void afisareHeap(Heap *h)
{
    for (int i = 0; i < h->dimensiune; i++)
    {
        printf("%d ", h->elemente[i]);
    }
    printf("\n");
}

int main()
{
    Heap *heap = creareHeap(20);

    inserare(heap, 10);
    inserare(heap, 5);
    inserare(heap, 30);
    inserare(heap, 20);
    inserare(heap, 40);

    printf("Heap-ul este:\n");
    afisareHeap(heap);

    printf("Extragere max: %d\n", extrageMax(heap));
    printf("Heap-ul după extragere:\n");
    afisareHeap(heap);

    // nu uita sa eliberezi memoria la final
    free(heap->elemente);
    free(heap);

    return 0;
}