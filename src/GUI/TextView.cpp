#include "TextView.h"

TextView::TextView(float x, float y, std::string text, sf::Font *font, unsigned font_size, sf::Color color):
m_text_value(text),
m_font(font),
m_font_size(font_size),
m_text_color(color)
{
    m_text.setFont(*font);
    m_text.setString(text);
    m_text.setFillColor(color);
    m_text.setCharacterSize(font_size);

    m_text.setPosition(x - m_text.getGlobalBounds().width / 2.0f, y - m_text.getGlobalBounds().height);
}

TextView::~TextView() {

}

void TextView::render(sf::RenderWindow &render_window) {
    render_window.draw(m_text);
}