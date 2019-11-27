#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "State.h"
#include "Button.h"
#include "global.h"

class MainMenuState : public State {
    public:
        MainMenuState(sf::RenderWindow &render_window);
        virtual ~MainMenuState();

        void check_for_quit();

        void quit_state();

        void update();
        void render();
    
    private:
        sf::RectangleShape m_background;
        Button *m_start_button;

        std::string m_font_name;
};

#endif // MAIN_MENU_STATE_H