#include "Button.h"

Button::Button(float x, float y, float width, float height,
    std::string text,
    sf::Color idle_color, sf::Color hover_color, sf::Color active_color):
m_text(x + (width / 2.f), y + (height / 2.f), text, font_manager->get_font(SANS_BOLD_FONT), 22, TEXT_COLOR_LIGHT),
m_idle_color(idle_color),
m_hover_color(hover_color),
m_active_color(active_color)
{
    m_shape.setPosition(sf::Vector2f(x, y));
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(m_idle_color);

    m_button_state = BUTTON_IDLE;
}

Button::~Button() {

}

bool Button::is_pressed() const {
    return m_button_state == BUTTON_ACTIVE;
}

void Button::update() {
    m_button_state = BUTTON_IDLE;

    // Hover
    if (m_shape.getGlobalBounds().contains(input_manager->get_mouse_position_view())) {
        m_button_state = BUTTON_HOVER;

        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            m_button_state = BUTTON_ACTIVE;
        }
    }

    switch (m_button_state) {
        case BUTTON_IDLE:
            m_shape.setFillColor(m_idle_color);
            break;
        case BUTTON_HOVER:
            m_shape.setFillColor(m_hover_color);
            break;

        case BUTTON_ACTIVE:
            m_shape.setFillColor(m_active_color);
            break;

        default:
            m_shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::render(sf::RenderWindow &render_window) {
    render_window.draw(m_shape);

    m_text.render(render_window);
}
