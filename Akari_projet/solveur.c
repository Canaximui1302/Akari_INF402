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

int check_0(Tableau t, int x, int y)
{
    if (t.tab[y][x+1] != A && t.tab[y][x-1] != A && t.tab[y+1][x] != A && t.tab[y-1][x] != A)
        return 1;
   
    return 0;
}

int check_1(Tableau t, int x, int y)
{
    if (t.tab[y][x+1] == A && t.tab[y][x-1] != A && t.tab[y+1][x] != A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] == A && t.tab[y+1][x] != A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] != A && t.tab[y+1][x] == A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] != A && t.tab[y+1][x] != A && t.tab[y-1][x] == A)
        return 1;
    
    return 0;
}

int check_2(Tableau t, int x, int y)
{
    if (t.tab[y][x+1] == A && t.tab[y][x-1] == A && t.tab[y+1][x] != A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] == A && t.tab[y][x-1] != A && t.tab[y+1][x] == A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] == A && t.tab[y][x-1] != A && t.tab[y+1][x] != A && t.tab[y-1][x] == A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] == A && t.tab[y+1][x] == A && t.tab[y-1][x] != A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] == A && t.tab[y+1][x] != A && t.tab[y-1][x] == A)
        return 1;
    else if (t.tab[y][x+1] != A && t.tab[y][x-1] != A && t.tab[y+1][x] == A && t.tab[y-1][x] == A)
        return 1;

    return 0;

}

int check_3(Tableau t, int x, int y)
{
    if (t.tab[y][x+1] != A && t.tab[y][x-1] == A && t.tab[y+1][x] == A && t.tab[y-1][x] == A)
        return 1;
    else if (t.tab[y][x+1] == A && t.tab[y][x-1] != A && t.tab[y+1][x] == A && t.tab[y-1][x] == A)
        return 1;
    else if (t.tab[y][x+1] == A && t.tab[y][x-1] == A && t.tab[y+1][x] != A && t.tab[y-1][x] == A)
        return 1;
    else if (t.tab[y][x+1] == A && t.tab[y][x-1] == A && t.tab[y+1][x] == A && t.tab[y-1][x] != A)
        return 1;

    return 0;
}

int check_4(Tableau t, int x, int y)
{
    if (t.tab[y][x+1] == A && t.tab[y][x-1] == A && t.tab[y+1][x] == A && t.tab[y-1][x] == A)
        return 1;
    return 0;
}