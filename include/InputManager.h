#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>
#include <set>

class InputManager {
    public:
        InputManager();
        ~InputManager();

        bool get_key_pressed() const;
        std::set<sf::Keyboard::Key> get_last_keys_pressed();

        void set_last_key_pressed(sf::Keyboard::Key);
        void set_last_key_released(sf::Keyboard::Key);

    private:
        std::set<sf::Keyboard::Key> m_keys_pressed;
};

#endif // INPUTMANAGER_H