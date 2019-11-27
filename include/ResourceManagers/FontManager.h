#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class FontManager
{
public:
    FontManager();
    virtual ~FontManager();

    int load_font(const std::string &path);
    sf::Font *get_font(const std::string &path);

private:
    std::unordered_map<std::string, sf::Font> m_fonts;
};

#endif // FONTMANAGER_H