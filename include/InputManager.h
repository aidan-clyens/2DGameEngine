#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
    public:
        InputManager();
        ~InputManager();

        bool get_key_pressed() const;
        sf::Keyboard::Key get_last_key_pressed() const;

        void set_key_pressed(bool is_key_pressed);
        void set_last_key_pressed(sf::Keyboard::Key);

    private:
        bool m_is_key_pressed;
        sf::Keyboard::Key m_last_key_pressed;
};

#endif // INPUTMANAGER_H