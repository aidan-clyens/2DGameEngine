#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "global.h"

class TextView {
    public:
        TextView(float x, float y, std::string text, sf::Font *font, unsigned font_size);
        virtual ~TextView();
    
        void update();
        void render(sf::RenderWindow &render_window);

    private:
        std::string m_text_value;
        sf::Font *m_font;
        unsigned m_font_size;
        sf::Text m_text;
};

#endif // TEXT_VIEW_H