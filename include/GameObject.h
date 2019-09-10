#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "global.h"

class GameObject {
    public:
        GameObject(const std::string &name);
        GameObject(const std::string &name, sf::Vector2f pos);
        virtual ~GameObject();

        virtual void update();
        void draw(sf::RenderWindow &render_window);

    protected:
        std::string m_texture_name;
        sf::Vector2f m_position;
};

#endif //GAMEOBJECT_H