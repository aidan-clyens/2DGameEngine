#include "InputManager.h"

InputManager::InputManager() {
    // Empty
}

InputManager::~InputManager() {

}

bool InputManager::get_key_pressed() const {
    return m_keys_pressed.size() != 0;
}

std::set<sf::Keyboard::Key> InputManager::get_last_keys_pressed() {
    return m_keys_pressed;
}

void InputManager::set_last_key_pressed(sf::Keyboard::Key last_key_pressed) {
    m_keys_pressed.insert(last_key_pressed);
}

void InputManager::set_last_key_released(sf::Keyboard::Key last_key_released) {
    m_keys_pressed.erase(last_key_released);
}

void InputManager::update_mouse_position(sf::RenderWindow &render_window) {
    m_mouse_position_screen = sf::Mouse::getPosition();
    m_mouse_position_window = sf::Mouse::getPosition(render_window);
    m_mouse_position_view = render_window.mapPixelToCoords(sf::Mouse::getPosition(render_window));
}

sf::Vector2f InputManager::get_mouse_position_view() {
    return m_mouse_position_view;
}