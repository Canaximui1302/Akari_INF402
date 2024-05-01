#include <stdio.h>
#include <stdlib.h>
#include "solveur.h"
#include "type.h"


int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage: main <nom_fichier_test> <nom_fichier_a_creer>\n"); //./main probleme_file ../MiniSat-C_v1.14.1/test.txt
        exit(1);
    }
    
    Tableau t = tableau_vide(TAILLE_MAX);
    liste_clauses l = liste_vide();
    Tableau_var v = tableau_var_vide(TAILLE_MAX);
    
    lire_input(argv[1], &t);
    //affichage_tableau(t);
    get_var(t, &v);
    affichage_tableau(t);
    affichage_tableau_var(v);
    
    get_clause(t, v, &l);

    creer_dimacs(argv[2], l);
   
    return 0;
}