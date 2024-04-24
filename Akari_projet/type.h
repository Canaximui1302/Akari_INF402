#ifndef _TYPE_H_
#define _TYPE_H_
#define TAILLE 5


//type de cellule:
// Nx pour noire avec x ampoules 0 <= x <= 4
// N pour noire sans valeur
// A pour ampoule
// B pour blanche

// Formule pour un cellule C:
// C = (A * -B * -N * -N0 * -N1 * -N2 * -N3 * -N4) 
// + (-A * B * -N * -N0 * -N1 * -N2 * -N3 * -N4) 
// + (-A * -B * N * -N0 * -N1 * -N2 * -N3 * -N4) 
// + (-A * -B * -N * N0 * -N1 * -N2 * -N3 * -N4) 
// + (-A * -B * -N * -N0 * N1 * -N2 * -N3 * -N4) 
// + (-A * -B * -N * -N0 * -N1 * N2 * -N3 * -N4) 
// + (-A * -B * -N * -N0 * -N1 * -N2 * N3 * -N4) 
// + (-A * -B * -N * -N0 * -N1 * -N2 * -N3 * N4) 

typedef enum 
{
    A, 
    B,
    N,
    N0,
    N1,
    N2,
    N3,
    N4
} Cell;



typedef struct tableau_
{
    int taille;
    Cell tab[TAILLE][TAILLE];
} Tableau;

Tableau init_jeu(int taille);




#endif