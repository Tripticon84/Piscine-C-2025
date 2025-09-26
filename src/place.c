#include "include/place.h"

#define ROW_TILES = 10;
static int row_tiles = 10;
static int selectedButtonX = 0;
static int selectedButtonY = 0;
static TTF_Font *font = NULL;
Tile **buttons;

void initPlace() {
    if (TTF_Init() == -1) {
        printf("Erreur TTF init: %s\n", TTF_GetError());
        return;
    }

    font = TTF_OpenFont("../src/assets/PixelOperator8.ttf", 24);
    if (!font) {
        printf("Erreur police menu: %s\n", TTF_GetError());
        return;
    }

    buttons = malloc(row_tiles * sizeof(Button *));
    if (!buttons) {
        return;
    }

    for (int i = 0; i < row_tiles; i++) {
        buttons[i] = malloc(row_tiles * sizeof(Button));
        if (!buttons[i]) {
            return;
        }
    }

    int buttonWidth = 40; // Taille du tile modifiée
    int buttonHeight = 40; // Taille du tile modifiée
    int spacing = 0;
    int totalWidth = row_tiles * buttonWidth + (row_tiles - 1) * spacing;
    int totalHeight = row_tiles * buttonHeight + (row_tiles - 1) * spacing;
    int windowWidth = 1240;
    int windowHeight = 640;
    int startY = (windowHeight - totalHeight) / 2; // Centrage vertical
    int startX = (windowWidth - totalWidth) / 2; // Centrage horizontal

    for (int i = 0; i < row_tiles; i++) {
        for (int j = 0; j < row_tiles; j++) {
            if (i == 0 && j == 0) {
                buttons[i][j].isSelected = 1;
            }
            buttons[i][j].isSelected = 0;
            buttons[i][j].rect.w = buttonWidth;
            buttons[i][j].rect.h = buttonHeight;
            buttons[i][j].rect.x = startX + j * (buttonWidth + spacing);
            buttons[i][j].rect.y = startY + i * (buttonHeight + spacing);
        }
    }
}

void drawCuror() {
    unsigned char r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &cursorRect);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}


void handlePlaceInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = 0;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    selectedButtonY = (selectedButtonY - 1 + row_tiles) % row_tiles;
                    break;
                case SDLK_DOWN:
                    selectedButtonY = (selectedButtonY + 1) % row_tiles;
                    break;
                case SDLK_LEFT:
                    selectedButtonX = (selectedButtonX - 1 + row_tiles) % row_tiles;
                    break;
                case SDLK_RIGHT:
                    selectedButtonX = (selectedButtonX + 1) % row_tiles;
                    break;
                case SDLK_RETURN:
                case SDLK_SPACE:
                    if (selectedButtonX == 0 && selectedButtonY == 0) {
                        currentGameState = GAME_STATE_PLACE_P1;
                    } else if (selectedButtonX == 1 && selectedButtonY == 0) {
                        running = 0;
                    }
                    break;
                case SDLK_ESCAPE:
                    currentGameState = GAME_STATE_MENU;
                    break;
                default: break;
            }
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                for (int i = 0; i < row_tiles; i++) {
                    for (int j = 0; j < row_tiles; j++) {
                        if (x >= buttons[i][j].rect.x && x <= buttons[i][j].rect.x + buttons[i][j].rect.w &&
                            y >= buttons[i][j].rect.y && y <= buttons[i][j].rect.y + buttons[i][j].rect.h) {
                            selectedButtonX = j;
                            selectedButtonY = i;
                            if (selectedButtonX == 0 && selectedButtonY == 0) {
                                currentGameState = GAME_STATE_PLACE_P1;
                            } else if (selectedButtonX == 1 && selectedButtonY == 0) {
                                running = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void updatePlace() {
    for (int i = 0; i < row_tiles - 1; i++) {
        for (int j = 0; j < row_tiles - 1; j++) {
            buttons[i][j].isSelected = (i == selectedButtonY && j == selectedButtonX);
        }
    }
}

void drawPlace() {
    for (int i = 0; i < row_tiles - 1; i++) {
        for (int j = 0; j < row_tiles - 1; j++) {
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            if (buttons[i][j].isSelected) {
                SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
            }
            SDL_RenderFillRect(renderer, &buttons[i][j].rect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &buttons[i][j].rect);

            if (font) {
                SDL_Color textColor = {255, 255, 255, 255};
                if (buttons[i][j].isSelected) {
                    textColor.r = 255;
                    textColor.g = 255;
                    textColor.b = 0;
                }
            }
        }
    }
}

void cleanPlace() {
    if (font) {
        TTF_CloseFont(font);
        font = NULL;
    }

    for (int i = 0; i < row_tiles; i++) {
        free(buttons[i]);
    }
    free(buttons);
}
