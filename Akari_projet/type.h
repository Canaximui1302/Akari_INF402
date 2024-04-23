#ifndef _TYPE_H_
#define _TYPE_H_
#define TAILLE 5

typedef struct _case {
    int x;
    int y;
    char type;    // type est parmi A, N, I; case noire sans valeur est N avec valeur -1
    int valeur;   // -1, 0, 1, 2, 3, 4 pour type N, une valeur quelconque pour les autres
} Case;

typedef struct tableau_ {
    Case ligne[TAILLE];
    Case Colonne[TAILLE];
} Tableau;



#endif