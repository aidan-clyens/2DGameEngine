#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "global.h"

typedef struct {
    float top;
    float bottom;
    float right;
    float left;
} bounding_box_t;

class GameObject {
    public:
        GameObject(const std::string &name);
        GameObject(const std::string &name, sf::Vector2f pos);
        virtual ~GameObject();

        virtual void update();
        void render(sf::RenderWindow &render_window);

    protected:
        std::string m_texture_name;
        sf::Vector2f m_position;
        sf::Vector2u m_size;
        bounding_box_t m_bounding_box;
};

#endif //GAMEOBJECT_H