#ifndef NOCTURNE_GAME_H
#define NOCTURNE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "menu.h"


// Variables globales
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int running;


typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_LOCAL_MODE,
    GAME_STATE_PLACE_P1,
    GAME_STATE_PLACE_P2,
    GAME_STATE_PLAY_P1,
    GAME_STATE_WAIT_P2,
    GAME_STATE_PLAY_P2,
    GAME_STATE_WAIT_P1,
    GAME_STATE_OVER,
} GameState;

typedef struct Position {
    int x;
    int y;
} Position;

typedef enum BoatOrientation {
    BOAT_HORIZONTAL,
    BOAT_VERTICAL
} BoatOrientation;

typedef struct Boat {
    Position position;
    int length;
    int orientation;
    int hit;
    int sunk;
} Boat;

// Fonctions globales du jeu
int initGame();

void gameLoop();

void cleanupGame();


#endif //NOCTURNE_GAME_H
