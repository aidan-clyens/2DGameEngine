#ifndef WORLD_H
#define WORLD_H

#include "global.h"
#include "GameObject.h"
#include "Level.h"

class World {
    public:
        World(sf::RenderWindow &render_window);
        ~World();

        void update();
        void draw();

        void load_level(Level *level);

        void add_game_object(GameObject *g);
        void remove_game_object(GameObject &g);

    private:
        std::list<GameObject*> m_game_objects;
        Level *m_level;
        sf::RenderWindow &m_render_window;
};

#endif // WORLD_H