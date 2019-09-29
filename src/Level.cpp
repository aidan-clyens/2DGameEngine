#include "Level.h"

Level::Level() {
    for (int i=0; i<LEVEL_ROWS; i++) {
        for (int j=0; j <LEVEL_COLS; j++) {
            add_level_background_object(new GameObject("res/block.bmp", sf::Vector2f(j*BLOCK_WIDTH, i*BLOCK_WIDTH)));
        }
    }
}

Level::~Level() {
    for (GameObject *g : m_level_background_blocks) {
        delete g;
    }

    for (GameObject *g : m_level_blocks) {
        delete g;
    }
}

void Level::update() {
    for (GameObject *g : m_level_background_blocks) {
        g->update();
    }

    for (GameObject *g : m_level_blocks) {
        g->update();
    }
}

void Level::draw(sf::RenderWindow &window) {
    for (GameObject *g : m_level_background_blocks) {
        g->draw(window);
    }

    for (GameObject *g : m_level_blocks) {
        g->draw(window);
    }
}

void Level::add_level_background_object(GameObject *g) {
    m_level_background_blocks.push_back(g);
}

void Level::remove_level_background_object(GameObject &g) {
    // TODO
}

void Level::add_level_object(GameObject *g) {
    m_level_blocks.push_back(g);
}

void Level::remove_level_object(GameObject &g) {
    // TODO
}