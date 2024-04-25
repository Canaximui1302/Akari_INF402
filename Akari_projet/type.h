#ifndef TYPE_H
#define TYPE_H
#define TAILLE 10


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
    V=0,
    N0=1,
    N1=2,
    N2=3,
    N3=4,
    N4=5,
    N=6,
    B=7,
    A=8 
} Cell;



typedef struct tableau_
{
    int taille;
    Cell tab[TAILLE][TAILLE];
} Tableau;

Tableau tableau_vide(int taille);

void affichage_tableau(Tableau t);

void set_valeur(Tableau *t, int ln, int cl, Cell c);

Cell get_valeur(Tableau t, int ln, int cl);


#endif
