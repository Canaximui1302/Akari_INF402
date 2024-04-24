#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "type.h"

int check_ampoule(Tableau t, int x, int y)
{
    for (int i = 0; i < t.taille; i++)
    {
        if (t.tab[y][i] == A) {
            printf("Il y a une ampoule sur cette ligne.\n");
            return 0;
        }
    }

    for (int i = 0; i < t.taille; i++)
    {
        if (t.tab[i][x] == A) {
            printf("Il y a une ampoule sur cette colonne.\n");
            return 0;
        }
    }

    return 1;
}