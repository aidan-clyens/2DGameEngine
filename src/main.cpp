#include "Game.h"
#include "global.h"

int main() {
    InputManager *input_manager = new InputManager();
    TextureManager *texture_manager = new TextureManager();
    Game game;

    game.run();

    delete input_manager;
    delete texture_manager;

    return 0;
}

