#ifndef TYPE_H
#define TYPE_H
#define TAILLE_MAX 10
#define TAILLE_CLAUSE_MAX 50


//type de cellule:
// Nx pour noire avec x ampoules 0 <= x <= 4
// N pour noire sans valeur
// A pour ampoule
// B pour blanche
// I pour illuminee



typedef enum 
{
    B=0,
    N0=1,
    N1=2,
    N2=3,
    N3=4,
    N4=5,
    N=6,
    I=7,
    A=8 
} Cell;



typedef struct tableau_
{
    int taille;
    Cell tab[TAILLE_MAX][TAILLE_MAX];
} Tableau;

typedef struct tableau_var_
{
    int taille;
    int tab[TAILLE_MAX][TAILLE_MAX];
} Tableau_var;

typedef struct clause_ 
{
    int nb_var;
    int var[TAILLE_CLAUSE_MAX];
} Clause;

typedef struct clauses_
{
    int nb_var;
    int nb_clause;
    Clause c[TAILLE_CLAUSE_MAX];
} liste_clauses;

liste_clauses liste_vide();

Tableau tableau_vide(int taille);

Tableau_var tableau_var_vide(int taille);

void affichage_tableau(Tableau t);

void affichage_tableau_var(Tableau_var v);

void set_valeur(Tableau *t, int ln, int cl, Cell c);

Cell get_valeur(Tableau t, int ln, int cl);


#endif
