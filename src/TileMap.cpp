#include "TileMap.h"

TileMap::TileMap(const unsigned grid_size, const unsigned max_rows, const unsigned max_cols):
m_grid_size(grid_size),
m_max_rows(max_rows),
m_max_cols(max_cols)
{
    for (unsigned y=0; y<m_max_rows; y++) {
        m_map.push_back(std::vector<GameObject*>());

        for (unsigned x=0; x<m_max_cols; x++) {
            m_map[y].push_back(nullptr);
        }
    }
}

TileMap::~TileMap() {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                delete m_map[y][x];
            }
        }
    }
}

void TileMap::add_tile(const unsigned x, const unsigned y) {
    if (x < m_max_cols && x >= 0 && y < m_max_rows && y >= 0) {
        if (m_map[y][x] == nullptr) {
            m_map[y][x] = new GameObject("res/block.bmp", sf::Vector2f(x*m_grid_size, y*m_grid_size));
        }
    }
}

void TileMap::remove_tile(const unsigned x, const unsigned y) {
    if (x < m_max_cols && x >= 0 && y < m_max_rows && y >= 0) {
        if (m_map[y][x] != nullptr) {
            delete m_map[y][x];
            m_map[y][x] = nullptr;
        }
    }
}

void TileMap::load_tilemap() {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++){
            add_tile(x, y);
        }
    }
}

void TileMap::update() {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                m_map[y][x]->update();
            }
        }
    }
}

void TileMap::render(sf::RenderWindow &render_window) {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                m_map[y][x]->render(render_window);
            }
        }
    }
}