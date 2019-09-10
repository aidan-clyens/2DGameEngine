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