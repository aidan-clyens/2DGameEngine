#include "TextureManager.h"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

int TextureManager::load_texture(const std::string &path) {
    auto it = m_textures.find(path);

    // Only insert texture if it is currently not stored
    if (it == m_textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            return EXIT_FAILURE;
        }

        m_textures.emplace(path, texture);
    }

    return EXIT_SUCCESS;
}

sf::Texture TextureManager::get_texture(const std::string &path) {
    auto it = m_textures.find(path);

    // Find requested texture or return a default texture
    if (it != m_textures.end()) {
        return it->second;
    }

    return sf::Texture();
}