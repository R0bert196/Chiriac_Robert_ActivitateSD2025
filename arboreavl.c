typedef struct NodAVL
{
    int valoare;
    int inaltime; // Înălțimea subarborelui
    struct NodAVL *stang;
    struct NodAVL *drept;
} NodAVL;
