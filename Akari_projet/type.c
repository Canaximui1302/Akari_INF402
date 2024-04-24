#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "type.h"

Tableau init_jeu(int taille)
{
    Tableau t;
    t.taille = taille;
    
    return t;

}

void mettre_ampoule(Tableau *t, int x, int y)
{
    Cell c = t->tab[y][x];
    switch(c)
    {
        case A:
            break;
        case B:
            t->tab[y][x] = A;
            break;
        default:
            printf("Coup invalide.\n");
            break;
    }
}



