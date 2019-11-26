#ifndef STATE_H
#define STATE_H

#include "global.h"

class State {
    public:
        State(sf::RenderWindow &render_window);
        virtual ~State();

        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        sf::RenderWindow &m_render_window;
};

#endif // STATE_H