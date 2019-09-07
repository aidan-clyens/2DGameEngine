#include "World.h"

World::World(sf::RenderWindow &render_window):
m_render_window(render_window)
{
    // Empty
}

World::~World() {
    for (GameObject *g : m_game_objects) {
        delete g;
    }
}

void World::update() {
    for (GameObject *g : m_level_objects) {
        g->update();
    }

    for (GameObject *g : m_game_objects) {
        g->update();
    }
}

void World::draw() {
    for (GameObject *g : m_level_objects) {
        g->draw(m_render_window);
    }

    for (GameObject *g : m_game_objects) {
        g->draw(m_render_window);
    }
}

void World::load_level() {
    // TODO
}

void World::add_game_object(GameObject *g) {
    m_game_objects.push_back(g);
}

void World::remove_game_object(GameObject &g) {
    // TODO
}