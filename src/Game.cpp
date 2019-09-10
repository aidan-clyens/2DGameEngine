#include "Game.h"

Game::Game():
m_main_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test"),
m_game_world(new World(m_main_window))
{
    m_game_world->add_game_object(new Player("res/player.bmp"));
}

Game::~Game() {
    delete m_game_world;
}

void Game::run() {
    while (m_main_window.isOpen()) {
        // Poll events
        poll_events();

        m_game_world->update();

        // Update screen
        m_main_window.clear();
        m_game_world->draw();
        m_main_window.display();
    }
}

void Game::poll_events() {
    sf::Event event;

    while (m_main_window.pollEvent(event)) {    
        if (event.type == sf::Event::Closed) {
            m_main_window.close();
        }

        else if (event.type == sf::Event::KeyPressed) {
            input_manager->set_last_key_pressed(event.key.code);
        }

        else if (event.type == sf::Event::KeyReleased) {
            input_manager->set_last_key_released(event.key.code);
        }
    }
}