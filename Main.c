/* Auteurs: Sarah ENG, Imane ERRAHMANI 
 * CrÃ©ation: 24/03/2022 
 * Modification: 30/03/2022 
 */
#include "Dico.h"
#include "Grille.h"
#include "Graphisme.h"
#include <time.h>

int main (int argc, char* argv[]) {
    FILE* f;
    int x, y;
    char** dico;
    int grille[HAUTEUR_GRILLE][LARGEUR_GRILLE];
    Liste lst;
    Liste_mot l_mot = NULL;
    int tentative, score;
    srand(time(NULL));
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS
    | REPORT_MOUSE_POSITION, NULL);
    start_color();

    /* Lecture du fichier de mots (dictionnaire) et remplissage du tableau dico avec ces mots */
    f = ouvre_fichier(argv[1]);
    dico = remplir_dico(f);
    /* Initialisation de la liste de lettres, du nombre de tentatives restantes et du score */
    lst = NULL;
    tentative = 4;
    score = 0;
    
    /* Initialisation des couleurs des cases de la grille et des cases selectionnees */
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);  
    init_pair(2, COLOR_BLACK, COLOR_WHITE); 
    init_pair(3, COLOR_BLACK, COLOR_CYAN); /* couleur de selection */
    /* Initialisation de la grille avec des lettres generees aleatoirement (ponderee) */
    init_grille(grille);
    /* Affichage de la grille, du score, des tentatives restantes et des mots valides qui existent dans le dico */
    afficher_grille(grille);
    affiche_info_joueur(score, l_mot, tentative);
    /* Tant qu'il reste des tentatives */
    while (tentative != 0) {
        /* Lecture et gestion du coup du joueur */
        lire_coup(&x, &y, &l_mot,&lst, dico, grille, &tentative, &score);
        /* Actualisation de l'affichage */
        affiche_info_joueur(score, l_mot, tentative);
        refresh();
    
    }
    /* Affichage du message de fin de partie et du score final */
    clear();
    affiche_fin_partie(score);
    sleep(3);

    refresh();
    endwin();
    return 0;
    
}