#include <stdlib.h>
#include <stdio.h>


/*
void show_grid(Board *board) {
    int size = (board->colonne * 2) * board->ligne;
    // on fait size * 2 pour pouvoir mettre des espaces entre les colonnes ; pas entre les lignes
    char **table = malloc(sizeof(char) * (size + 1));
    table[size] = '\0';

    for (int x = 0; x < board->colonne; x++) {
        for (int y = 0; y < board->ligne; y++) {
            if (x == 0 && y == 0) {
                printf(" ");
            }
            if (x == 1 && y == 0) {
                printf("%c", ('A' + x));
            }
            if (y == 1 && x == 0) {
                printf("%c", ('1' + x));
            }
        } //ferme le deuxième for
        if (x % 2) {
            printf(" ");
        }
    }
}
*/