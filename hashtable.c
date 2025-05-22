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

void initHashTable(HashTable *ht)
{
    for (int i = 0; i < SIZE; i++)
        ht->buckets[i] = NULL;
}

void inserare(HashTable *ht, int cheie, int valoare)
{
    Nod *nou = (Nod *)malloc(sizeof(Nod));

    int index = hashFunction(cheie);

    nou->next = ht->buckets[index];
    nou->valoare = valoare;
    nou->cheie = cheie;

    ht->buckets[index] = nou;
}

void afisare(HashTable *ht)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%d]: ", i);
        Nod *curent = ht->buckets[i];

        while (curent != NULL)
        {
            printf("(%d -> %d) ", curent->cheie, curent->valoare);
            curent = curent->next;
        };
        printf("\n");
    }
}

int main()
{
    HashTable ht;
    initHashTable(&ht);
    inserare(&ht, 1, 99);
    inserare(&ht, 2, 199);
    inserare(&ht, 55, 199);
    inserare(&ht, 123, 199);
    inserare(&ht, 555, 199);
    inserare(&ht, 1123, 199);
    inserare(&ht, 123, 199);
    inserare(&ht, 12123, 199);
    inserare(&ht, 1723, 199);
    inserare(&ht, 11923, 199);
    inserare(&ht, 11823, 199);

    afisare(&ht);

    return 0;
}