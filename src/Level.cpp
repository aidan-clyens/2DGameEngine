#include "Level.h"

Level::Level() {
    // Empty
}

Level::~Level() {
    // Empty
}

void Level::update() {
    for (GameObject *g : m_level_blocks) {
        g->update();
    }
}

void Level::draw(sf::RenderWindow &window) {
    for (GameObject *g : m_level_blocks) {
        g->draw(window);
    }
}

void Level::add_level_object(GameObject *g) {
    m_level_blocks.push_back(g);
}

void Level::remove_level_object(GameObject &g)
{
    // TODO
}