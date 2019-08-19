#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
    public:
        InputManager();
        ~InputManager();

        sf::Keyboard::Key get_last_key_pressed() const;

        void set_last_key_pressed(sf::Keyboard::Key);

    private:
        sf::Keyboard::Key m_last_key_pressed;
};

#endif // INPUTMANAGER_H