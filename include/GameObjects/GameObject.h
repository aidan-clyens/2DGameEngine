#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "global.h"

class GameObject {
    public:
        GameObject(const std::string &name);
        GameObject(const std::string &name, sf::Vector2f pos);
        virtual ~GameObject();

        bool check_intersect(sf::FloatRect rect);

        sf::Vector2f get_position() const;
        sf::FloatRect get_hitbox() const;
        std::string get_texture_name() const;
        
        virtual void update();
        void render(sf::RenderWindow &render_window);

    protected:
        std::string m_texture_name;
        sf::Vector2f m_position;
        sf::Vector2f m_size;

        sf::RectangleShape m_hitbox;
};

#endif //GAMEOBJECT_H