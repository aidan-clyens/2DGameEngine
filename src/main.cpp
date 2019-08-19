#include "Game.h"
#include "global.h"

int main() {
    TextureManager *texture_manager = new TextureManager();
    Game game;

    game.run();

    delete texture_manager;

    return 0;
}

