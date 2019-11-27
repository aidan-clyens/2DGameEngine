#include "Button.h"

Button::Button(float x, float y, float width, float height,
    std::string text,
    sf::Color idle_color, sf::Color hover_color, sf::Color active_color):
m_idle_color(idle_color),
m_hover_color(hover_color),
m_active_color(active_color)
{
    m_shape.setPosition(sf::Vector2f(x, y));
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(m_idle_color);

    m_text.setString(text);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(12);

    m_text.setPosition(
        m_shape.getPosition().x / 2.0f - m_text.getGlobalBounds().width / 2.0f,
        m_shape.getPosition().y / 2.0f - m_text.getGlobalBounds().height / 2.0f
    );
}

Button::~Button() {

}

void Button::update(sf::Vector2f mouse_pos) {

}

void Button::render(sf::RenderWindow &render_window) {
    render_window.draw(m_shape);
}
