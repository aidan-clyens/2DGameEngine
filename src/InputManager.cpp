#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

sf::Keyboard::Key InputManager::get_last_key_pressed() const {
    return m_last_key_pressed;
}

void InputManager::set_last_key_pressed(sf::Keyboard::Key last_key_pressed) {
    m_last_key_pressed = last_key_pressed;
}