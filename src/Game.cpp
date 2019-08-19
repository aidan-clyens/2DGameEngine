#include "Game.h"

Game::Game():
m_main_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test")
{
    // Empty
}

Game::~Game() {

}

void Game::run() {
    while (m_main_window.isOpen()) {
        // Poll events
        sf::Event event;

        while (m_main_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_main_window.close();
            }
        }

        // Update screen
        m_main_window.clear();
        m_main_window.display();
    }
}