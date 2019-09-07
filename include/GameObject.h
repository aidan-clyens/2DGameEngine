#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "global.h"

class GameObject {
    public:
        GameObject(const std::string &name);
        ~GameObject();

        void update();
        void draw(sf::RenderWindow &render_window);

    private:
        std::string m_texture_name;
        sf::Vector2f m_position;
};

#endif //GAMEOBJECT_H