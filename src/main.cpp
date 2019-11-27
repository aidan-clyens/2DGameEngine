#include "global.h"
#include "Game.h"

InputManager *input_manager;
TextureManager *texture_manager;
FontManager *font_manager;

int main() {
    input_manager = new InputManager();
    texture_manager = new TextureManager();
    font_manager = new FontManager();
    Game game;

    game.run();

    delete input_manager;
    delete texture_manager;
    delete font_manager;

    return 0;
}

