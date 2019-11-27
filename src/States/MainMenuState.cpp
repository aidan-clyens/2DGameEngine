#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow &render_window):
State(render_window)
{
    m_background.setSize((sf::Vector2f)render_window.getSize());
    m_background.setFillColor(sf::Color::Cyan);

    float width = BLOCK_WIDTH * 6;
    float height = BLOCK_WIDTH;
    float x = m_background.getGlobalBounds().width / 2.0f - width / 2.0f;
    float y = m_background.getGlobalBounds().height / 2.0f - height / 2.0f;

    m_start_button = new Button(x, y, width, height, "Start", sf::Color::Blue, sf::Color::Magenta, sf::Color::Red);
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
    delete m_start_button;
}

void MainMenuState::update() {
    m_start_button->update();
}

void MainMenuState::render() {
    m_render_window.draw(m_background);
    
    m_start_button->render(m_render_window);
}
