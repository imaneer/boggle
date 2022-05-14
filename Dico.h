/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Creation: 24/03/2022 
 * Modification: 24/03/2022 
*/

#ifndef __DICO__
#define __DICO__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_MOTS_DICO 370103

/* Fonction qui ouvre un fichier pour la lecture seulement */
FILE *ouvre_fichier(const char *chemin);
/* Fonction qui renvoie 1 si le mot est dans le dico, et 0 sinon */
int recherche_dichotomie(char **dico, int debut, int fin, char *mot);
/* Fonction qui renvoie 1 si le mot est dans le dico, et 0 sinon */
int appartient(char **dico, char *mot);
/* Fonction qui lit un fichier de mots et renvoie un tableau qui contient tous les mots du fichier */
char** remplir_dico(FILE* f);

#endif