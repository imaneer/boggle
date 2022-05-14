/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * CrÃ©ation: 24/03/2022 
 * Modification: 24/03/2022 
*/

#include "Dico.h"
/*Fonction qui ouvre un fichier pour la lecture seulement */
FILE *ouvre_fichier(const char *chemin) {
    FILE *df = fopen(chemin, "r");
    /* Si le fichier n'a pas pu etre ouvert, un message s'affiche dans la sortie d'erreur et on quitte le programme */
    if (df == NULL) {
        fprintf(stderr, "impossible d'ouvrir %s", chemin);
        exit(1);
    }
    return df;
}

/* Fonction qui renvoie 1 si le mot est dans le dico, et 0 sinon */
int recherche_dichotomie(char **dico, int debut, int fin, char *mot){
    int milieu;
    /* milieu est l'indice median entre debut et fin */
    milieu = ((fin - debut) / 2) + debut;
    /* Si debut et fin se sont croises et depasses, ca signifie qu'on n'a pas trouve le mot */
    if (fin == - 1 || debut > fin){
        return 0;
    }
    /* Si debut est egal a fin ou si fin est egal a debut+1 */
    if (milieu == 0){
        /* Si le mot est egal au mot d'indice debut ou au mot d'indice fin, on a trouve le mot */
        if (strcmp(dico[debut], mot) == 0 || strcmp(dico[fin], mot) == 0) {
            return 1;
        }
        /* Sinon, ca signifie que le mot n'existe pas dans le dico */
        return 0;
    }
    /* Si le mot est egal au mot d'indice milieu, alors on a trouve le mot */
    if (strcmp(dico[milieu], mot) == 0) {
        return 1;
    }
    /* recherche dans la partie gauche */
    if (strcmp(dico[milieu], mot) > 0) {
        return recherche_dichotomie(dico, debut, milieu - 1, mot);
    }
    /* recherche dans la partie droite */
    else {
        return recherche_dichotomie(dico, milieu + 1, fin, mot);
    }
}

/* Fonction qui renvoie 1 si le mot est dans le dico, et 0 sinon */
int appartient(char **dico, char *mot){
    /* Recherche dichotomique dans le dico */
    return recherche_dichotomie(dico, 0, NB_MOTS_DICO, mot);
}

/* Fonction qui lit un fichier de mots et renvoie un tableau qui contient tous les mots du fichier */
char** remplir_dico(FILE* f) {
    char mot[50];
    char **dico;
    int i;
    /* Allocation du tableau de mots dico */
    dico = (char**)malloc(sizeof(char*) * NB_MOTS_DICO);
    i = 0;
    /* Si l'allocation a echoue, on renvoie NULL */
    if (dico == NULL) return NULL;
    /* Tant que ce n'est pas la fin du fichier */
    while (fscanf(f, "%s", mot) == 1) {
        /* Allocation d'un tableau de caracteres avec la taille exacte de la chaine de caracteres */
        dico[i] = (char*)malloc(sizeof(char) * strlen(mot) + 1);
        if (dico[i] == NULL) return NULL;
        /* Si l'allocation a reussi, on copie le mot dans le dico */
        strcpy(dico[i], mot);
        i++;
    }
    return dico;
}