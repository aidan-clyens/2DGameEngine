#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager {
    public:
        TextureManager();
        ~TextureManager();

        int load_texture(const std::string &path);
        sf::Texture get_texture(const std::string &path);

    private:
        std::unordered_map<std::string, sf::Texture> m_textures;
};

#endif // TEXTUREMANAGER_H