#include "include/game.h"
#include "include/board.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);

    // Initialiser le jeu
    if (initGame() != 0) {
        return 1;
    }

    // Boucle principale du jeu
    // gameLoop();

    // Quitter proprement
    cleanupGame();


    return 0;
}

