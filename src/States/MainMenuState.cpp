#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow &render_window):
State(render_window)
{
    font_manager->load_font(SANS_BOLD_FONT);

    m_background.setSize((sf::Vector2f)render_window.getSize());
    m_background.setFillColor(MENU_BACKGROUND_COLOR);
    
    float x = m_background.getGlobalBounds().width / 2.0f;
    float y = m_background.getGlobalBounds().height / 2.0f - BLOCK_WIDTH * 3;
    m_title_text_view = new TextView(x, y, "SFML Test Game", font_manager->get_font(SANS_BOLD_FONT), 30, TEXT_COLOR_DARK);

    float width = BLOCK_WIDTH * 6;
    float height = BLOCK_WIDTH;
    x = m_background.getGlobalBounds().width / 2.0f - width / 2.0f;
    y = m_background.getGlobalBounds().height / 2.0f - height / 2.0f;
    m_start_button = new Button(x, y, width, height, "Start", BUTTON_IDLE_COLOR, BUTTON_HOVER_COLOR, BUTTON_ACTIVE_COLOR);
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
    delete m_title_text_view;
    delete m_start_button;
}

void MainMenuState::update() {
    m_start_button->update();
}

void MainMenuState::render() {
    m_render_window.draw(m_background);
    
    m_title_text_view->render(m_render_window);
    m_start_button->render(m_render_window);
}
