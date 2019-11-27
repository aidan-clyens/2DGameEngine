#ifndef BUTTON_H
#define BUTTON_H

#include "TextView.h"
#include "global.h"

typedef enum button_state {
    BUTTON_IDLE,
    BUTTON_HOVER,
    BUTTON_ACTIVE
} button_state_t;

class Button {
    public:
        Button(float x, float y, float width, float height, std::string text, sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
        virtual ~Button();

        bool is_pressed() const;

        void update();
        void render(sf::RenderWindow &render_window);

    private:
        sf::RectangleShape m_shape;

        TextView m_text;

        sf::Color m_idle_color;
        sf::Color m_hover_color;
        sf::Color m_active_color;

        button_state_t m_button_state;
};

#endif //BUTTON_H