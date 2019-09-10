#ifndef LEVEL_H
#define LEVEL_H

#include "global.h"
#include "GameObject.h"
#include <list>

class Level {
    public:
        Level();
        ~Level();

        void update();
        void draw(sf::RenderWindow &window);

        void add_level_object(GameObject *g);
        void remove_level_object(GameObject &g);

    private:
        std::list<GameObject*> m_level_blocks;
};

#endif // LEVEL_H