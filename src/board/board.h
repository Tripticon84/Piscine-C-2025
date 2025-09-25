#ifndef NOCTURNE_GAME_H
#define NOCTURNE_GAME_H
#include "../game/game.h"


#endif //NOCTURNE_GAME_H

typedef struct Board {
    int colonne;
    int ligne;
    //  Boat *boats;
    //faut intégré une liste de boat dans le board mais pour l'instant il ne le reconnait pas malgré l'intégration de game.h
} Board;

void show_grid(Board *board);
