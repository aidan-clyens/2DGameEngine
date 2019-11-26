#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "GameObject.h"
#include "global.h"

class TileMap {
    public:
        TileMap();
        virtual ~TileMap();

        void update();
        void render(sf::RenderWindow &render_window);

    private:
        std::vector<std::vector<GameObject*>> m_map;
};

#endif // TILE_MAP_H