#include "Level.h"

Level::Level() {

}

Level::~Level() {

}

void Level::update() {
    m_tile_map.update();
}

void Level::render(sf::RenderWindow &window) {
    m_tile_map.render(window);
}