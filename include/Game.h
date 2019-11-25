#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "global.h"
#include "World.h"
#include "Player.h"

class Game {
    public:
        Game();
        ~Game();

        void run();

        void update();
        void render();
        void poll_events();

    private:
        sf::RenderWindow m_main_window;
        World *m_game_world;
};

#endif // GAME_H