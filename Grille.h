/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 */
#ifndef __Grille__
#define __Grille__

#define LARGEUR_GRILLE 4
#define HAUTEUR_GRILLE 4
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Liste.h"
#include "Graphisme.h"

/* Fonction qui remplie la grille */
void init_grille(int grille[][LARGEUR_GRILLE]);
/* Fonction  qui lit un coup et effectue le deroulement du jeu */
int lire_coup(int *x, int *y, Liste_mot *lst, Liste *l,  char** dico, int grille[][LARGEUR_GRILLE], int *tentative, int* score);
/* Fonction qui ajoute une lettre contenue dans une case dans une liste */
int ajouter_dans_liste(int grille[][LARGEUR_GRILLE], Liste *lst, int x, int y);
#endif