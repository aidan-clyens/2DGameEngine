#ifndef STATE_H
#define STATE_H

#include "global.h"

class State {
    public:
        State(sf::RenderWindow &render_window);
        virtual ~State();

        bool get_quit() const;

        virtual void check_for_quit() = 0;

        virtual void quit_state() = 0;

        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        sf::RenderWindow &m_render_window;

        bool m_quit;
};

#endif // STATE_H