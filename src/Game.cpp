#include "Game.h"

Game::Game()
{
    init_window();
    init_states();
}

Game::~Game() {
    while (!m_states.empty()) {
        delete m_states.top();
        m_states.pop();
    }

    delete m_main_window;
}

void Game::init_window() {
    m_main_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test");
}

void Game::init_states() {
    GameState *game_state = new GameState(*m_main_window);
    game_state->load_level(new Level());
    game_state->add_game_object(new Player("res/player.bmp"));
    
    m_states.push(game_state);
}

void Game::run() {
    m_main_window->setFramerateLimit(60);

    while (m_main_window->isOpen()) {
        // Poll events
        poll_events();

        // Update screen
        update();
        render();
    }
}

void Game::update() {
    if (!m_states.empty()) {
        m_states.top()->update();
    }
}

void Game::render() {
    m_main_window->clear();

    if (!m_states.empty()) {
        m_states.top()->render();
    }

    m_main_window->display();
}

void Game::poll_events() {
    sf::Event event;

    while (m_main_window->pollEvent(event)) {    
        if (event.type == sf::Event::Closed) {
            m_main_window->close();
        }

        else if (event.type == sf::Event::KeyPressed) {
            input_manager->set_last_key_pressed(event.key.code);
        }

        else if (event.type == sf::Event::KeyReleased) {
            input_manager->set_last_key_released(event.key.code);
        }
    }
}