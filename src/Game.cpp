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
    std::ifstream config_file(WINDOW_CONFIG_FILE);
    
    // Set default window settings
    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    bool fullscreen = false;
    unsigned framerate_limit = 60;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    // Load settings from window.ini
    if (config_file.is_open()) {
        std::getline(config_file, title);
        config_file >> window_bounds.width >> window_bounds.height;
        config_file >> fullscreen;
        config_file >> framerate_limit;
        config_file >> vertical_sync_enabled;
        config_file >> antialiasing_level;
    }

    config_file.close();

    // Save settings and create window
    m_window_settings.antialiasingLevel = antialiasing_level;

    if (fullscreen) {
        m_main_window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, m_window_settings);
    }
    else {
        m_main_window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, m_window_settings);
    }

    m_main_window->setFramerateLimit(framerate_limit);
    m_main_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::init_states() {
    GameState *game_state = new GameState(*m_main_window);
    game_state->load_level(new TileMap(BLOCK_WIDTH, LEVEL_ROWS, LEVEL_COLS));
    m_states.push(game_state);
    
    MainMenuState *main_menu_state = new MainMenuState(*m_main_window);
    m_states.push(main_menu_state);
}

void Game::run() {
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
        m_states.top()->check_for_quit();
        m_states.top()->update();

        if (m_states.top()->get_quit()) {
            m_states.top()->quit_state();

            delete m_states.top();
            m_states.pop();
        }
    }
    else {
        m_main_window->close();
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

    input_manager->update_mouse_position(*m_main_window);

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