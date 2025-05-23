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




int main()
{
    Heap *heap = creareHeap(20);


    return 0;
}