/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * Création: 24/03/2022 
 * Modification: 30/03/2022 
 */
#include "Graphisme.h"

/* Fonction qui affiche la grille passé en parametre */
void afficher_grille (int grille[][LARGEUR_GRILLE]) {
    int i, j;
    for (i = 0 ; i < HAUTEUR_GRILLE ; i++) {
        move(i, 0);
        for (j = 0 ; j < LARGEUR_GRILLE ; j++) {
            /* on alterne entre 2 couleurs */
            if ((i + j) % 2 == 0) { /* les cases dont la somme des cordonnées est pair */
                attron(COLOR_PAIR(1));
                printw("  %c  ", grille[i][j]);
                attroff(COLOR_PAIR(1));
            }
            else {
                attron(COLOR_PAIR(2));
                printw("  %c  ", grille[i][j]);
                attroff(COLOR_PAIR(2));
            }
        }
    }
}

/* Fonction qui change la couleur de la case quand on la selectionne */
void case_selectionnee (int grille[][LARGEUR_GRILLE],int x, int y) {
    attron(COLOR_PAIR(3));
    mvprintw(y, x*5,"  %c  ", grille[y][x]);
    attroff(COLOR_PAIR(3));
    refresh();
}

/* Fonction qui remet la couleur initiale dans la case */
void case_deselectionnee (int grille[][LARGEUR_GRILLE],int x, int y) {

    if (((x*5) + y) % 2 == 0) { /* les cases dont la somme des cordonnées est pair */
        attron(COLOR_PAIR(1));
        mvprintw(y,x*5,"  %c  ", grille[y][x]);
        attroff(COLOR_PAIR(1));
    }
    else {
        attron(COLOR_PAIR(2));
        mvprintw(y,x*5,"  %c  ", grille[y][x]);
        attroff(COLOR_PAIR(2));
    }
    refresh();
}

/* Fonction qui affiche le score actuel, nombre de tentative restante
 * et les mots trouvés */
void affiche_info_joueur(int score, Liste_mot lst, int nb_tentative) {
    int i;
    i = 1;
    /* on affiche le nombre de tentatives restantes en premier */
    mvprintw(1, LARGEUR_GRILLE * 5 + 5, "Tentatives restantes : %d", nb_tentative);
    /* puis le score */
    mvprintw(2, LARGEUR_GRILLE * 5 + 5, "Score : %d", score);
    /* et finalement on parcourt la liste des mots pour afficher 
     * les mots trouvés */
    while (lst != NULL) {
        mvprintw(2 + i, LARGEUR_GRILLE * 5 + 5, "%s", lst->mot);
        lst = lst->suivant;
        i++;
    }
    refresh();
}


/* Fonction qui affiche un message de fin de partie et le score final */
void affiche_fin_partie(int score) {
    mvprintw((LINES - 1) / 2, (COLS - 1) / 2 - strlen("Fin de la partie") / 2, "Fin de la partie");
    mvprintw((LINES - 1) / 2 + 1, (COLS - 1) / 2 - strlen("Score final :   ") / 2, "Score final : %d", score);
    refresh();
}