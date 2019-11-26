#include "State.h"

State::State(sf::RenderWindow &render_window):
m_render_window(render_window),
m_quit(false)
{

}

State::~State() {
    
}

bool State::get_quit() const {
    return m_quit;
}