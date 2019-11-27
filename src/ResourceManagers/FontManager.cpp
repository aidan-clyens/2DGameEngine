#include "FontManager.h"

FontManager::FontManager() {

}

FontManager::~FontManager() {

}

int FontManager::load_font(const std::string &path) {
    auto it = m_fonts.find(path);

    // Only insert font if it is currently not stored
    if (it == m_fonts.end())
    {
        sf::Font font;
        if (!font.loadFromFile(path))
        {
            return EXIT_FAILURE;
        }

        m_fonts.emplace(path, font);
    }

    return EXIT_SUCCESS;
}

sf::Font *FontManager::get_font(const std::string &path) {
    auto it = m_fonts.find(path);

    // Find requested font or return a default font
    if (it != m_fonts.end())
    {
        return &it->second;
    }

    return nullptr;
}