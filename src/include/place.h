#ifndef NOCTURNE_PLACE_H
#define NOCTURNE_PLACE_H

#include "game.h"

typedef struct {
    SDL_Rect rect;
    int isSelected;
} Tile;


void initPlace();

void handlePlaceInput();

void updatePlace();

void drawPlace();

void drawCursor();

void cleanPlace();


static SDL_Rect cursorRect = {0, 0, 20, 20};

#endif //NOCTURNE_PLACE_H
