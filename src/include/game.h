#ifndef NOCTURNE_GAME_H
#define NOCTURNE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>

// Variables globales
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int running;


typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
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
