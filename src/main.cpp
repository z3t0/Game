// Main file
// Copyright (C) Rafi Khan 2016

// Includes
#include "Game.hpp"

// Defines
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Game"

int main() {
    
    Game game (WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    
    game.update();
    
    return 0;
}
