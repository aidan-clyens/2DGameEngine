#include "World.h"

World::World(sf::RenderWindow &render_window):
m_render_window(render_window)
{
    // Empty
}

World::~World() {
    delete m_level;
    
    for (GameObject *g : m_game_objects) {
        delete g;
    }
}

void World::update() {
    m_level->update();

    for (GameObject *g : m_game_objects) {
        g->update();
    }
}

void World::draw() {
    m_level->draw(m_render_window);

    for (GameObject *g : m_game_objects) {
        g->draw(m_render_window);
    }
}

void World::load_level(Level *level) {
    m_level = level;
}

void World::add_game_object(GameObject *g) {
    m_game_objects.push_back(g);
}

void World::remove_game_object(GameObject &g) {
    // TODO
}