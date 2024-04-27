#ifndef _SOLVEUR_H_
#define _SOLVEUR_H_
#include "type.h"

void lire_input(char*nom_fichier_input, Tableau *t);

void get_var(Tableau t, int *(v[TAILLE_MAX][TAILLE_MAX]), liste_clauses *l);

void clause_N0(Tableau t, int x, int y, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l, int *indice);

void clause_N1(Tableau t, int x, int y, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l, int *indice);

void clause_N2(Tableau t, int x, int y, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l, int *indice);

void clause_N3(Tableau t, int x, int y, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l, int *indice);

void clause_N4(Tableau t, int x, int y, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l, int *indice);

void get_clause(Tableau t, int v[TAILLE_MAX][TAILLE_MAX], liste_clauses *l);

void creer_dimacs(char *nom_fichier, liste_clauses l);

//int check_ampoule(Tableau t, int x, int y);

int check_0(Tableau t, int x, int y);

int check_1(Tableau t, int x, int y);

int check_2(Tableau t, int x, int y);

int check_3(Tableau t, int x, int y);

int check_4(Tableau t, int x, int y);




#endif