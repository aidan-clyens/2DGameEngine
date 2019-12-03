#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "GameObject.h"
#include "global.h"

#include "json.hpp"
class TileMap {
    public:
        TileMap(const unsigned grid_size, const unsigned max_rows, const unsigned max_cols);
        virtual ~TileMap();

        void add_tile(const std::string texture_name, const unsigned x, const unsigned y);
        void remove_tile(const unsigned x, const unsigned y);

        GameObject *get_tile(const unsigned x, const unsigned y);

        void load_tilemap();

        void save_to_file(const std::string file_name);
        
        void update();
        void render(sf::RenderWindow &render_window);

    private:
        std::vector<std::vector<GameObject*>> m_map;

        unsigned m_grid_size;
        unsigned m_max_rows;
        unsigned m_max_cols;
};

#endif // TILE_MAP_H