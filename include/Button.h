#ifndef BUTTON_H
#define BUTTON_H

#include "global.h"

class Button {
    public:
        Button(float x, float y, float width, float height, std::string text, sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
        virtual ~Button();

        void update(sf::Vector2f mouse_pos);
        void render(sf::RenderWindow &render_window);

    private:
        sf::RectangleShape m_shape;
        sf::Font *m_font;
        sf::Text m_text;

        sf::Color m_idle_color;
        sf::Color m_hover_color;
        sf::Color m_active_color;
};

#endif //BUTTON_H