#include "TileMap.h"

TileMap::TileMap() {
    for (int x=0; x<LEVEL_ROWS; x++) {
        m_map.push_back(std::vector<GameObject*>());

        for (int y=0; y<LEVEL_COLS; y++) {
            m_map[x].push_back(new GameObject("res/block.bmp", sf::Vector2f(y*BLOCK_WIDTH, x*BLOCK_WIDTH)));
        }
    }
}

TileMap::~TileMap() {
    for (int x = 0; x < LEVEL_ROWS; x++) {
        for (int y = 0; y < LEVEL_COLS; y++) {
            delete m_map[x][y];
        }
    }
}

void TileMap::update() {
    for (int x = 0; x < LEVEL_ROWS; x++) {
        for (int y = 0; y < LEVEL_COLS; y++) {
            m_map[x][y]->update();
        }
    }
}

void TileMap::render(sf::RenderWindow &render_window) {
    for (int x = 0; x < LEVEL_ROWS; x++) {
        for (int y = 0; y < LEVEL_COLS; y++) {
            m_map[x][y]->render(render_window);
        }
    }
}