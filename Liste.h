/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 */
#ifndef __LISTE__
#define __LISTE__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Dico.h"
#include <ctype.h>
#include <ncurses.h>

/* Liste simplement chainee qui represente le mot qui est en train d'etre forme */
typedef struct cellule {
    char lettre;
    int case_x;
    int case_y;
    struct cellule *suivant;
} Cellule, *Liste;

/* Liste simplement chainee qui contient tous les mots formés */
typedef struct cellule_mot {
    char *mot;
    struct cellule_mot *suivant;
} Cellule_mot, *Liste_mot;

/* Fonction qui ajoute la lettre c de coordonnées x et y dans la liste l */
int ajoute_lettre (Liste *lst, char c, int x, int y);
/* Fonction qui supprime le debut de la lsite passée en paramètre */
int supprime_tete(Liste *l);
/* Fonction qui construit un char* a partir des lettres stockees dans la liste lst */
void construire_mot (Liste lst, char tab[], int *taille);
/* Fonction qui inverse le contenu d'un tab de char */
void inverser (char tab1[], char tab2 [], int taille );
/* Fonction qui ajoute le mot mot a la liste des mots lst après l'avoir trouver dans dico 
 * elle renvoie 1 si le mot est ajouté à la liste et 0 sinon */
int ajoute_mot(Liste_mot *lst, char *mot, char **dico);
/* Fonction qui cherche une lettre en cherchant sa case dans la liste passée 
 * en parametre , elle renvoie 1 si la lettre est trouvée et 0 sinon*/
int recherche_lettre(Liste lst, int x, int y);
#endif