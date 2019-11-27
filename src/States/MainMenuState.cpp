#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow &render_window):
State(render_window)
{
    m_background.setSize((sf::Vector2f)render_window.getSize());
    m_background.setFillColor(sf::Color::Cyan);
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::check_for_quit() {
    if (input_manager->get_key_pressed()) {
        for (sf::Keyboard::Key key : input_manager->get_last_keys_pressed()) {
            if (key == sf::Keyboard::Escape) {
                m_quit = true;
            }
        }
    }
}

void MainMenuState::quit_state() {

}

void MainMenuState::update() {
    
}

void MainMenuState::render() {
    m_render_window.draw(m_background);
}
