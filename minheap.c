#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *elemente;
    int dimensiune;
    int capacitate;
} MinHeap;

MinHeap *creareMinHeap(int capacitate)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->dimensiune = 0;
    heap->capacitate = capacitate;
    heap->elemente = (int *)malloc(sizeof(int) * capacitate);
    return heap;
}

int main()
{

    MinHeap *heap = creareHeap(10);
    return 0;
}