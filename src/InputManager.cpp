#include "InputManager.h"

InputManager::InputManager():
m_is_key_pressed(false)
{
    // Empty
}

InputManager::~InputManager() {

}

bool InputManager::get_key_pressed() const {
    return m_is_key_pressed;
}

sf::Keyboard::Key InputManager::get_last_key_pressed() const {
    return m_last_key_pressed;
}

void InputManager::set_key_pressed(bool is_key_pressed) {
    m_is_key_pressed = is_key_pressed;
}

void InputManager::set_last_key_pressed(sf::Keyboard::Key last_key_pressed) {
    m_last_key_pressed = last_key_pressed;
}