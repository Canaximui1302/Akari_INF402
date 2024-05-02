#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "type.h"


// Notre format du fichier input:
// 1ere ligne: un entier representant la taille de la grille
// 2eem ligne: un entier representant le nombre de case noire dans la grille
// et apres sur chaque ligne une case ecrite sous la forme:
// T t x y: T est le type de la case, t est la contrainte de nombre d'ampoule, x et y est indice dans la grille
// Par exemple: N 1 3 4 est une case N(1) a la position (3, 4) dans la grille
// N 5 x y sont les cases noires sans contrainte de nombre d'ampoule.


void lire_input(char *nom_fichier_input, Tableau *t)
{
    FILE *f = fopen(nom_fichier_input, "r");
    int taille;
    int nb_clause;
    fscanf(f, "%d\n", &taille);
    fscanf(f, "%d\n", &nb_clause);
    //printf("%d\n", taille);
    //printf("%d\n", nb_clause);
    t->taille = taille;

    for (int i = 0; i < nb_clause; i++)
    {
        Cell c;
        int val, x, y;
        fscanf(f, "N %d %d %d\n",&val, &x, &y);
        //printf("N %d %d %d\n",val, x, y);
        switch(val)
        {
            case 0:
                c = N0;
                break;
            case 1:
                c = N1;
                break;
            case 2:
                c = N2;
                break;
            case 3:
                c = N3;
                break;
            case 4:
                c = N4;
                break;
            case 5:
                c = N;
                break;
        }

        set_valeur(t, y - 1, x -1, c);
        
    }

    fclose(f);
}


void get_var(Tableau t, Tableau_var *v, liste_clauses *l)
{
    int v0 = 1;
    v->taille = t.taille;
    printf("%d\n", v->taille);

    for (int i = 0; i < v->taille;i++)
    {
        for (int j = 0; j < v->taille; j++)
        {
            Cell cell = t.tab[i][j];
            switch(cell)
            {
                case N:
                case N0:
                case N1:
                case N2:
                case N3:
                case N4:
                    v->tab[i][j] = -1;
                    break;
                default:
                    break;
            }
        }
    }


    for (int i = 0; i < v->taille;i++)
    {
        for (int j = 0; j < v->taille; j++)
        {
            Cell cell = t.tab[i][j];
            switch(cell)
            {
                case N:
                case N0:
                case N1:
                case N2:
                case N3:
                case N4:
                    if (i + 1 < t.taille) {
                        if (v->tab[i + 1][j] == 0) {
                            v->tab[i + 1][j] = v0;
                            //printf("%d\n", v->tab[i+1][j]);
                            v0++;
                        }
                    }
                    if (j + 1 < t.taille) {
                        if (v->tab[i][j + 1] == 0) {
                            v->tab[i][j + 1] = v0;
                            //printf("%d\n", v->tab[i+1][j]);
                            v0++;
                        }
                    }
                    if (i - 1 >= 0) {
                        if (v->tab[i - 1][j] == 0) {
                            v->tab[i - 1][j] = v0;
                            //printf("%d\n", v->tab[i+1][j]);
                            v0++;
                        }
                    }
                    if (j - 1 >= 0) {
                        if (v->tab[i][j - 1] == 0) {
                            v->tab[i][j - 1] = v0;
                            //printf("%d\n", v->tab[i+1][j]);
                            v0++;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    l->nb_var = v0 - 1;
}


// On construit une clause a partir des variables, 
// ici les variables sont les cases ou on doit mettre les ampoules
// les ampoules a b c d sont en position comme ci-dessous
//      __a __
//   d |_cell_| b
//        c 

void clause_N0(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille){
        b = v.tab[y][x+1];
        }
    if (x - 1 >= 0){
        d = v.tab[y][x-1];
        }
    if (y + 1 < v.taille){
        c = v.tab[y+1][x];
        }
    if (y - 1 < t.taille){
        a = v.tab[y-1][x];
        }

    if (a != 0){
    Clause c1;
    c1.nb_var = 1;
    c1.var[0] = -a;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (b != 0) {
    Clause c2;
    c2.nb_var = 1;
    c2.var[0] = -b;
    l->c[*indice] = c2;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (c != 0){ 
    Clause c3;
    c3.nb_var = 1;
    c3.var[0] = -c;
    l->c[*indice] = c3;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (d != 0){
    Clause c4;
    c4.nb_var = 1;
    c4.var[0] = -d;
    l->c[*indice] = c4;
    l->nb_clause++;
    *indice = *indice + 1;
    }
}

void clause_N1(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille)
    {
        b = v.tab[y][x + 1];
    }
    if (x - 1 >= 0)
    {
        d = v.tab[y][x - 1];
    }
    if (y + 1 < v.taille)
    {
        c = v.tab[y + 1][x];
    }
    if (y - 1 < t.taille)
    {
        a = v.tab[y - 1][x];
    }

    Clause c1;
    int i = 0;

    if (a != 0){
    c1.var[i] = a;
    i++;}

    if (b!= 0) {
    c1.var[i] = b;
    i++;}

    if (c!= 0) {
    c1.var[i] = c;
    i++;}

    if (d!= 0) {
    c1.var[i] = d;
    i++;}

    c1.nb_var = i;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c2;
    i = 0;
    if (a != 0)
    {
        c2.var[i] = -a;
        i++;
    }
    if (b != 0)
    {
        c2.var[i] = -b;
        i++;
    }
    c2.nb_var = i;
    l->c[*indice] = c2;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c3;
    i = 0;
    if (a != 0)
    {
        c3.var[i] = -a;
        i++;
    }
    if (c != 0)
    {
        c3.var[i] = -c;
        i++;
    }
    c3.nb_var = i;
    l->c[*indice] = c3;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c4;
    i = 0;
    if (a != 0)
    {
        c4.var[i] = -a;
        i++;
    }
    if (d != 0)
    {
        c4.var[i] = -d;
        i++;
    }
    c4.nb_var = i;
    l->c[*indice] = c4;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c5;
    i = 0;
    if (b != 0)
    {
        c5.var[i] = -b;
        i++;
    }
    if (c != 0)
    {
        c5.var[i] = -c;
        i++;
    }
    c5.nb_var = i;
    l->c[*indice] = c5;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c6;
    i = 0;
    if (b != 0)
    {
        c6.var[i] = -b;
        i++;
    }
    if (d != 0)
    {
        c6.var[i] = -d;
        i++;
    }
    c6.nb_var = i;
    l->c[*indice] = c6;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c7;
    i = 0;
    if (c != 0)
    {
        c7.var[i] = -c;
        i++;
    }
    if (d != 0)
    {
        c7.var[i] = -d;
        i++;
    }
    c7.nb_var = i;
    l->c[*indice] = c7;
    l->nb_clause++;
    *indice = *indice + 1;

}

void clause_N2(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille)
    {
        b = v.tab[y][x + 1];
    }
    if (x - 1 >= 0)
    {
        d = v.tab[y][x - 1];
    }
    if (y + 1 < v.taille)
    {
        c = v.tab[y + 1][x];
    }
    if (y - 1 < t.taille)
    {
        a = v.tab[y - 1][x];
    }

    Clause c1;
    int i = 0;
    if (a != 0)
    {
        c1.var[i] = -a;
        i++;
    }
    if (b != 0)
    {
        c1.var[i] = -b;
        i++;
    }
    if (c != 0)
    {
        c1.var[i] = -c;
        i++;
    }
    c1.nb_var = i;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c2;
    i = 0;
    if (a != 0)
    {
        c2.var[i] = -a;
        i++;
    }
    if (b != 0)
    {
        c2.var[i] = -b;
        i++;
    }
    if (d != 0)
    {
        c2.var[i] = -d;
        i++;
    }
    c2.nb_var = i;
    l->c[*indice] = c2;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c3;
    i = 0;
    if (a != 0)
    {
        c3.var[i] = -a;
        i++;
    }
    if (c != 0)
    {
        c3.var[i] = -c;
        i++;
    }
    if (d != 0)
    {
        c3.var[i] = -d;
        i++;
    }
    c3.nb_var = i;
    l->c[*indice] = c3;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c4;
    i = 0;
    if (b != 0)
    {
        c4.var[i] = -b;
        i++;
    }
    if (c != 0)
    {
        c4.var[i] = -c;
        i++;
    }
    if (d != 0)
    {
        c4.var[i] = -d;
        i++;
    }
    c4.nb_var = i;
    l->c[*indice] = c4;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c5;
    i = 0;
    if (a != 0)
    {
        c5.var[i] = a;
        i++;
    }
    if (b != 0)
    {
        c5.var[i] = b;
        i++;
    }
    if (c != 0)
    {
        c5.var[i] = c;
        i++;
    }
    c5.nb_var = i;
    l->c[*indice] = c5;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c6;
    i = 0;
    if (a != 0)
    {
        c6.var[i] = a;
        i++;
    }
    if (b != 0)
    {
        c6.var[i] = b;
        i++;
    }
    if (d != 0)
    {
        c6.var[i] = d;
        i++;
    }
    c6.nb_var = i;
    l->c[*indice] = c6;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c7;
    i = 0;
    if (a != 0)
    {
        c7.var[i] = a;
        i++;
    }
    if (c != 0)
    {
        c7.var[i] = c;
        i++;
    }
    if (d != 0)
    {
        c7.var[i] = d;
        i++;
    }
    c7.nb_var = i;
    l->c[*indice] = c7;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c8;
    i = 0;
    if (b != 0)
    {
        c8.var[i] = b;
        i++;
    }
    if (c != 0)
    {
        c8.var[i] = c;
        i++;
    }
    if (d != 0)
    {
        c8.var[i] = d;
        i++;
    }
    c8.nb_var = i;
    l->c[*indice] = c8;
    l->nb_clause++;
    *indice = *indice + 1;
}

void clause_N3(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille)
    {
        b = v.tab[y][x + 1];
    }
    if (x - 1 >= 0)
    {
        d = v.tab[y][x - 1];
    }
    if (y + 1 < v.taille)
    {
        c = v.tab[y + 1][x];
    }
    if (y - 1 < t.taille)
    {
        a = v.tab[y - 1][x];
    }

    Clause c1;
    int i = 0;

    if (a != 0){
    c1.var[i] = -a;
    i++;}

    if (b!= 0) {
    c1.var[i] = -b;
    i++;}

    if (c!= 0) {
    c1.var[i] = -c;
    i++;}

    if (d!= 0) {
    c1.var[i] = -d;
    i++;}

    c1.nb_var = i;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c2;
    i = 0;
    if (a != 0)
    {
        c2.var[i] = a;
        i++;
    }
    if (b != 0)
    {
        c2.var[i] = b;
        i++;
    }
    c2.nb_var = i;
    l->c[*indice] = c2;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c3;
    i = 0;
    if (a != 0)
    {
        c3.var[i] = a;
        i++;
    }
    if (c != 0)
    {
        c3.var[i] = c;
        i++;
    }
    c3.nb_var = i;
    l->c[*indice] = c3;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c4;
    i = 0;
    if (a != 0)
    {
        c4.var[i] = a;
        i++;
    }
    if (d != 0)
    {
        c4.var[i] = d;
        i++;
    }
    c4.nb_var = i;
    l->c[*indice] = c4;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c5;
    i = 0;
    if (b != 0)
    {
        c5.var[i] = b;
        i++;
    }
    if (c != 0)
    {
        c5.var[i] = c;
        i++;
    }
    c5.nb_var = i;
    l->c[*indice] = c5;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c6;
    i = 0;
    if (b != 0)
    {
        c6.var[i] = b;
        i++;
    }
    if (d != 0)
    {
        c6.var[i] = d;
        i++;
    }
    c6.nb_var = i;
    l->c[*indice] = c6;
    l->nb_clause++;
    *indice = *indice + 1;

    Clause c7;
    i = 0;
    if (c != 0)
    {
        c7.var[i] = c;
        i++;
    }
    if (d != 0)
    {
        c7.var[i] = d;
        i++;
    }
    c7.nb_var = i;
    l->c[*indice] = c7;
    l->nb_clause++;
    *indice = *indice + 1;

}

void clause_N4(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille)
    {
        b = v.tab[y][x + 1];
    }
    if (x - 1 >= 0)
    {
        d = v.tab[y][x - 1];
    }
    if (y + 1 < v.taille)
    {
        c = v.tab[y + 1][x];
    }
    if (y - 1 < t.taille)
    {
        a = v.tab[y - 1][x];
    }

    if (a != 0){
    Clause c1;
    c1.nb_var = 1;
    c1.var[0] = a;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (b != 0) {
    Clause c2;
    c2.nb_var = 1;
    c2.var[0] = b;
    l->c[*indice] = c2;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (c != 0){ 
    Clause c3;
    c3.nb_var = 1;
    c3.var[0] = c;
    l->c[*indice] = c3;
    l->nb_clause++;
    *indice = *indice + 1;
    }

    if (d != 0){
    Clause c4;
    c4.nb_var = 1;
    c4.var[0] = d;
    l->c[*indice] = c4;
    l->nb_clause++;
    *indice = *indice + 1;

    }
}

void clause_N(Tableau t, int x, int y, Tableau_var v, liste_clauses *l, int *indice)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (x + 1 < v.taille)
    {
        b = v.tab[y][x + 1];
    }
    if (x - 1 >= 0)
    {
        d = v.tab[y][x - 1];
    }
    if (y + 1 < v.taille)
    {
        c = v.tab[y + 1][x];
    }
    if (y - 1 < t.taille)
    {
        a = v.tab[y - 1][x];
    }

    Clause c1;
    int i = 0;
    if (a != 0)
    {
        c1.var[i] = a;
        i++;
    }
    if (b != 0)
    {
        c1.var[i] = b;
        i++;
    }
    if (c != 0)
    {
        c1.var[i] = c;
        i++;
    }
    if (d != 0)
    {
        c1.var[i] = d;
        i++;
    }
    c1.nb_var = i;
    l->c[*indice] = c1;
    l->nb_clause++;
    *indice = *indice + 1;
}



void get_clause(Tableau t, Tableau_var v, liste_clauses *l)
{
    int indice = 0;
    for (int i = 0; i < t.taille; i++)
    {
        for (int j = 0; j < t.taille; j++)
        {
            Cell c = t.tab[i][j];
            switch(c)
            {
                case N0:
                    clause_N0(t, i, j, v, l, &indice);
                    break;
                case N1:
                    clause_N1(t, i, j, v, l, &indice);
                    break;
                case N2:
                    clause_N2(t, i, j, v, l, &indice);
                    break;
                case N3:
                    clause_N3(t, i, j, v, l, &indice);
                    break;
                case N4:
                    clause_N4(t, i, j, v, l, &indice);
                    break;
                case N:
                    clause_N(t, i, j, v, l, &indice);
                    break;
                default:
                    break;

            }
        }
    }

}


void creer_dimacs(char *nom_fichier, liste_clauses l)
{
    FILE *f = fopen(nom_fichier, "w");
    fprintf(f, "p cnf %d %d\n", l.nb_var, l.nb_clause);

    

    for (int i = 0; i < l.nb_clause; i++)
    {
        int t = l.c[i].nb_var;
        for (int j = 0; j < t; j++)
        {
            fprintf(f, "%d ", l.c[i].var[j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}















/*int check_ampoule(Tableau t, int x, int y)
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
} */

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