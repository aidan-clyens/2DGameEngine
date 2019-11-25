#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "global.h"
#include "Player.h"
#include "State.h"
#include "GameState.h"

class Game {
    public:
        Game();
        ~Game();

        void init_window();
        void init_states();

        void run();

        void update();
        void render();
        void poll_events();

    private:
        sf::RenderWindow *m_main_window;
        std::stack<State*> m_states;
};

#endif // GAME_H