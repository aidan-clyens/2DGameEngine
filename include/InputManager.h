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

        void update_mouse_position(sf::RenderWindow &render_window);

        sf::Vector2f get_mouse_position_view();

    private:
        std::set<sf::Keyboard::Key> m_keys_pressed;

        sf::Vector2i m_mouse_position_screen;
        sf::Vector2i m_mouse_position_window;
        sf::Vector2f m_mouse_position_view;
};

#endif // INPUTMANAGER_H