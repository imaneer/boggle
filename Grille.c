/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 */
#include "Grille.h"

/* Fonction qui remplie la grille */
void init_grille(int grille[][LARGEUR_GRILLE]) {
    int i, j, tmp;
    /* on remplie un tab de char avec les lettres en respectant le tableau des proba */
    char alphabet[101] = "AAAAAAABBCCCDDDDEEEEEEEEEEEFFGGHHHHHIIIIIIIJKLLLLMMMNNNNNNNOOOOOOOPPQRRRRRRSSSSSSSTTTTTTTTUUUVWWXYYZ";
    for (i = 0 ; i < HAUTEUR_GRILLE ; i++) {
        for (j = 0 ; j < LARGEUR_GRILLE ; j++) {
            /* on tire un chiffre aleatoirement */
            tmp = rand() % 100;
            /* on remplie la case pas la lettre convenable */
            grille[i][j] = alphabet[tmp];
        }
    }
}

/* Fonction qui calcule le score */
void actu_score(int *score, char* mot, char **dico) {
    int i, puissance, cmp;
    if (appartient(dico, mot) == 1) {
        puissance = strlen(mot) - 3;
        cmp = 1;
        if (puissance >= 0) {
            for (i = 0 ; i < puissance ; i++) {
                cmp *= 2;
            }
            *score += cmp;
        }
    }
}

/* Fonction  qui lit un coup et effectue le deroulement du jeu */
int lire_coup(int *x, int *y, Liste_mot *lst, Liste *l,  char** dico, int grille[][LARGEUR_GRILLE], int *tentative, int *score) {
    char tab2[HAUTEUR_GRILLE*LARGEUR_GRILLE];
    char *tab;
    int touche, ajout;

    MEVENT ev;
    int taille;
    while (1) {
        /* on prend une touche */
        touche = getch();
        if (touche == '\n') {
            /* \n sert à valider un mot */
            if (*l)
                /* on construit le mot */
                construire_mot(*l, tab2,&taille);
            tab = (char*)malloc(sizeof(char)*taille);
            if (!tab) exit(EXIT_FAILURE);/*gestion d'erreurs d'allocation */
            /* on stocke dans tab le mot dans le bon ordre */
            inverser (tab2, tab, taille);
            /* si le mot s'est ajouté a la liste des mots */
            if (ajoute_mot(lst, tab, dico)){ 
                /* on update le score */
                actu_score(score, tab, dico);
                /* on vide la liste */
                *l = NULL;
                /* on affiche la grille sans couleur de selection */
                afficher_grille(grille);
                /* on diminue le nombre de tentative */
                *tentative -= 1;
                return 1;
            }
            /* sinon on diminue le nombre de tentative et on remet la liste a null */
            *tentative -= 1;
            *l = NULL;
            /* on affiche la grille sans couleur de selection */
            afficher_grille(grille);
            return 1;

        }
        if (touche != KEY_MOUSE || getmouse(&ev) != OK)
            continue;
        *x = ev.x;
        *y = ev.y;
        /* avec chaque clic on ajoute la lettre a la liste des lettres */
        ajout = ajouter_dans_liste(grille, l, *x/5, *y);
        if (ajout == 1) {
            /* si l'ajout s'est bien passé on selectionne la case */
            case_selectionnee(grille, *x/5, *y);
        }
        else if (ajout == 2) {
            /* si on clique sur la meme case une 2eme fois on enlève la couleur de selection */
            case_deselectionnee(grille, *x/5, *y);
            /* et on supprime cette lettre */
            supprime_tete(l);
        }

        return 1;
    }
}

/* Fonction qui verifie la selection d'une case */
int verifie_selection(int x_precedent, int y_precedent, int case_x, int case_y) {
    /* x_precedent, y_precedent, case_x et case_y sont les indices du tableau qui represente la grille */
    /* x sont les colonnes (j), y sont les lignes (i) */
    /* En haut à gauche (diagonale) */
    if (x_precedent - 1 == case_x && y_precedent - 1 == case_y)
        return 1;
    /* En haut */
    if (x_precedent == case_x && y_precedent - 1 == case_y)
        return 1;
    /* En haut à droite (diagonale) */
    if (x_precedent + 1 == case_x && y_precedent - 1 == case_y)
        return 1;
    /* A gauche */
    if (x_precedent - 1 == case_x && y_precedent == case_y)
        return 1;
    /* A droite */
    if (x_precedent + 1 == case_x && y_precedent == case_y)
        return 1;
    /* En bas à gauche (diagonale) */
    if (x_precedent - 1 == case_x && y_precedent + 1 == case_y)
        return 1;
    /* En bas */
    if (x_precedent == case_x && y_precedent + 1 == case_y)
        return 1;
    /* En bas à droite (diagonale) */
    if (x_precedent + 1 == case_x && y_precedent + 1 == case_y)
        return 1;
    /* Meme case ou case trop eloignee */
    return 0;
} 

/* Fonction qui ajoute une lettre contenue dans une case dans une liste */
int ajouter_dans_liste(int grille[][LARGEUR_GRILLE], Liste *lst, int x, int y) {
    /* si on clique en dehors de la grille on renvoie 0 */
    if (x*5 < 0 || y < 0 || x*5 > (LARGEUR_GRILLE - 1) * 5 || y > (HAUTEUR_GRILLE - 1))
        return 0;
    /* si la liste est vide on ne doit rien vérifier on ajoute la lettre et on renvoie 1 */
    else if (*lst == NULL){
        ajoute_lettre(lst, grille[y][x], x*5, y);
        return 1;
    }
    /* si on clique sur la meme case 2 fois */
    else if ((*lst)->case_x/5 == x && (*lst)->case_y == y) {
        /* on renvoie 2 */
        return 2;
    }
    /* on verifie si la case choisie est une case voisine et on l'ajoute */
    else if (verifie_selection((*lst)->case_x/5, (*lst)->case_y, x, y) == 1) {
        ajoute_lettre(lst, grille[y][x], x*5, y);
        /* on renvoie 1 dans ce cas */
        return 1;
    }
    return 0;

}
