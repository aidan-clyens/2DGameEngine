#include "World.h"

World::World(sf::RenderWindow &render_window):
m_render_window(render_window)
{
    // Empty
}

World::~World() {
    // Empty
}

void World::update() {
    for (GameObject g : m_game_objects) {
        g.update();
    }
}

void World::draw() {
    for (GameObject g : m_game_objects) {
        g.draw(m_render_window);
    }
}

void World::add_game_object(GameObject &g) {
    m_game_objects.push_back(g);
}

void World::remove_game_object(GameObject &g) {
    // TODO
}