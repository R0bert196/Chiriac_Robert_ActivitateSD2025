#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 10 // dimensiunea tabelei hash

typedef struct Nod
{
    int cheie;
    int valoare;
    struct Nod *next;
} Nod;

typedef struct HashTable
{
    Nod *buckets[SIZE];
} HashTable;

// functia de hash
int hashFunction(int cheie)
{
    return cheie % SIZE;
}



int main()
{
    return 0;
}