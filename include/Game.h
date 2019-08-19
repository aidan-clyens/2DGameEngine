#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "global.h"

class Game {
    public:
        Game();
        ~Game();

        void run();

    private:
        void poll_events();

        sf::RenderWindow m_main_window;
};

#endif // GAME_H