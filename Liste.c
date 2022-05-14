/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 */
#include "Liste.h"

/*Fonction qui alloue une cellule */
Liste alloue_cellule(char lettre, int x, int y) {
    Liste tmp;
    tmp = (Liste)malloc(sizeof(Cellule));
    if (tmp == NULL) { /* gestion des erreurs d'allocation */
        return NULL;
    }
    tmp->lettre = lettre;
    tmp->suivant = NULL;
    tmp->case_x = x;
    tmp->case_y = y;
    return tmp;
}

/* Fonction qui alloue une cellule_mot */
Liste_mot alloue_cellule_mot(char *mot) {
    Liste_mot tmp;
    tmp = (Liste_mot)malloc(sizeof(Cellule_mot));
    if (!tmp) exit(EXIT_FAILURE); /* gestion des erreurs d'allocation */
    tmp->mot = (char *)malloc(sizeof(char) * strlen(mot) + 1);
    if (!tmp->mot) exit(EXIT_FAILURE);
    strcpy(tmp->mot, mot); /* on copie le mot dans le champs mot */
    tmp->suivant = NULL;
    return tmp;
}

/* Fonction qui cherche une lettre en cherchant sa case dans la liste passée 
 * en parametre , elle renvoie 1 si la lettre est trouvée et 0 sinon*/
int recherche_lettre(Liste lst, int x, int y) {
    /* si la liste est vide on renvoie  0*/
    if (lst == NULL)
        return 0;
    /* on parcourt la liste */
    while (lst){
        /* si on trouve la case qui contient la lettre */
        if (lst->case_x == x && lst->case_y == y)
            /* on renvoie 1 */
            return 1;
        lst = lst->suivant;
    }
    /* on renvoie 0 sinon */
    return 0;
}

/* Fonction qui ajoute la lettre c de coordonnées x et y dans la liste l */
int ajoute_lettre(Liste *l, char c, int x, int y){
    Liste tmp;
    /* on alloue une cellule */ 
    tmp = alloue_cellule(c,x, y);
    /* si la lettre n'est pas deja dans la liste */
    if(recherche_lettre(*l, x, y)== 0) {
        /* on l'ajoute */ 
        if (tmp != NULL){ /*gestion d'erreur d'allocation */
            tmp->suivant = *l;
            *l = tmp;
            /* on renvoie 1 dans ce cas */
            return 1;
        }
        /* et 0 sinon */
        return 0;
    }
    return 0;
}

/* Fonction qui supprime le debut de la lsite passée en paramètre */
int supprime_tete(Liste *l){
    Liste tmp;
    /* si la liste est vide on renvoie 0 */
    if(*l == NULL)
        return 0;
    /* sinon on supprime le debut et on renvoie 1 */
    tmp = *l;
    *l = (*l)->suivant;
    free(tmp);
    return 1;
}

/* Fonction qui construit un char* a partir des lettres stockees dans la liste lst */
void construire_mot (Liste lst, char tab[],int *taille) {
    int indice;
    *taille = 0;
    indice = 0;
    /* on parcourt la liste et on stocke chaque char dans tab */
    while (lst) {
        tab[indice] = lst->lettre;
        lst = lst->suivant;
        /* on augmente la taille pour pouvoir l'utiliser apres */
        *taille += 1;
        indice++;
    }
}

/* Fonction qui inverse le contenu d'un tab de char */
void inverser (char tab1[], char tab2 [], int taille ) {
    int i, j;
    /* on parcourt le premier a partir de son dernier elem et on stocke chaque lettre dans tab2 */
    for (i = taille - 1, j = 0; i >= 0; i-- , j++) 
        tab2[j] = tab1[i];
}

/*Fonction qui cherche le mot mot passée en paramètre dans lst_mot
 * elle renvoie 1 si le mot est dans la liste et 0 sinon 
 */
int recherche_mot(Liste_mot lst_mot, char *mot) {
    /* on parcourt la liste */
    while (lst_mot != NULL) {
        /* si on trouve le mot on renvoie 1 */
        if (strcmp(lst_mot->mot, mot) == 0) {
            return 1;
        }
        lst_mot = lst_mot->suivant;
    }
    /* on renvoie 0 sinon */
    return 0;
}

/* Fonction qui transforme les maj en min */
void Maj_to_Min(char *mot) {
    int i;
    i = 0;
    /* On parcourt caractere par caractere le mot, et on convertit tous les caracteres en minuscules */
    while (mot[i] != '\0') {
        mot[i] = tolower(mot[i]);
        i++;
    }
}

/* Fonction qui ajoute le mot mot a la liste des mots lst après l'avoir trouver dans dico 
 * elle renvoie 1 si le mot est ajouté à la liste et 0 sinon 
 */
int ajoute_mot(Liste_mot *lst, char *mot, char **dico) {
    Liste_mot tmp;
    /* on covertit les maj en min car le dictionnnaire contient que des min */
    Maj_to_Min(mot);
    /* on teste si le mot est dans le dictionnaire */
    if (appartient(dico, mot) == 1) {
        /* on teste s'il n'est pas deja dans la liste */
        if (recherche_mot(*lst, mot) == 0) {
            tmp = alloue_cellule_mot(mot);
            if (tmp != NULL){ /* gestion d'erreur d'allocation */
                /* on ajoute le mot dans la liste et on renvoie 1 */
                tmp->suivant = *lst;
                *lst = tmp;
                return 1;
            } 
        }
    }
    /* on renvoie 0 sinon */
    return 0;
}
