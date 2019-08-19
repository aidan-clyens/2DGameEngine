#include "global.h"
#include "Game.h"

InputManager *input_manager;
TextureManager *texture_manager;

int main() {
    input_manager = new InputManager();
    texture_manager = new TextureManager();
    Game game;

    game.run();

    delete input_manager;
    delete texture_manager;

    return 0;
}

