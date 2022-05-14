/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 */
#ifndef __Graphisme__
#define __Graphisme__
#define LARGEUR_GRILLE 4
#define HAUTEUR_GRILLE 4

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste.h"

/* Fonction qui affiche la grille passé en parametre */
void afficher_grille (int grille[][LARGEUR_GRILLE]);
/* Fonction qui change la couleur de la case quand on la selectionne */
void case_selectionnee (int grille[][LARGEUR_GRILLE],int x, int y);
/* Fonction qui remet la couleur initiale dans la case */
void case_deselectionnee (int grille[][LARGEUR_GRILLE],int x, int y);
/* Fonction qui affiche le score actuel, nombre de tentative restante
 * et les mots trouvés */
void affiche_info_joueur(int score, Liste_mot lst, int nb_tentative);
/* Fonction qui affiche un message de fin de partie et le score final */
void affiche_fin_partie(int score);
#endif