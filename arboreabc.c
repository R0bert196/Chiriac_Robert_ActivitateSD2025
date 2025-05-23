#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodABC
{
    int valoare;          
    struct NodABC *stang; 
    struct NodABC *drept; 
} NodABC;