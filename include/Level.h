#ifndef LEVEL_H
#define LEVEL_H

#include "global.h"
#include "GameObject.h"
#include "TileMap.h"
#include <list>

class Level {
    public:
        Level();
        ~Level();

        void update();
        void render(sf::RenderWindow &window);

    private:
        TileMap m_tile_map;
};

#endif // LEVEL_H