#ifndef NOCTURNE_MENU_H
#define NOCTURNE_MENU_H
#include "game.h"


typedef struct {
    SDL_Rect rect; // Position et taille du bouton
    const char *text; // Texte du bouton
    int isSelected; // Indique si le bouton est sélectionné (pour la navigation clavier)
} Button;

// Initialiser le menu
void initMenu();

// Gérer les entrées du menu
void handleMenuInput();

// Mettre à jour le menu (animations, etc.)
void updateMenu();

// Dessiner le menu
void drawMenu();

// Nettoyer les ressources du menu
void cleanupMenu();


#endif //NOCTURNE_MENU_H
