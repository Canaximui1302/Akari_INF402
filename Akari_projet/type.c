#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "type.h"

Tableau tableau_vide(int taille)
{
    if(taille > TAILLE)
    {
        printf("Taille trop grande.\n");
        return tableau_vide(0);
    }
    Tableau t;
    t.taille = taille;
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            t.tab[i][j] = V;
        }
    }
    return t;

}

void affichage_tableau(Tableau t)
{
    for(int i = 0; i < t.taille; i++)
    {
        printf("--");
    }
    printf("-\n");
    for(int i = 0; i < t.taille; i++)
    {
        for(int j = 0; j < t.taille; j++)
        {
            printf("|");
            if(t.tab[i][j] == N) printf("n");
            else if(t.tab[i][j] == N0 || 
            t.tab[i][j] == N1 || 
            t.tab[i][j] == N2 ||
            t.tab[i][j] == N3 ||
            t.tab[i][j] == N4) printf("%d", t.tab[i][j]-1);
            else if(t.tab[i][j] == A) printf("*");
            else if(t.tab[i][j] == B) printf(" ");
            else printf("?");

        }
        printf("|\n");
        for(int k = 0; k < t.taille; k++)
        {
            printf("--");
        }
        printf("-\n");
    }
}

void set_valeur(Tableau *t, int ln, int cl, Cell c)
{
    Cell c_precedente = t->tab[ln][cl];
    if(c == c_precedente) return;
    switch(c_precedente)
    {
        case V:
            t->tab[ln][cl] = c;
            break;
        default:
            printf("Coup invalide.\n");
    }
}

Cell get_valeur(Tableau t, int ln, int cl)
{
    if(ln < 0 || ln >= t.taille || cl < 0 || cl >= t.taille) return N;
    return t.tab[ln][cl];
}

