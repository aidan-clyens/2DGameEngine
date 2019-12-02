#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "TileMap.h"
#include "GameObject.h"
#include "Player.h"

class GameState : public State {
    public:
        GameState(sf::RenderWindow &render_window);
        virtual ~GameState();

        void check_for_quit();

        void quit_state();

        void update();
        void render();

        void load_level(TileMap *tile_map);

        void add_game_object(GameObject *g);
        void remove_game_object(GameObject &g);
    
    private:
        std::list<GameObject*> m_game_objects;
        Player *m_player;
        TileMap *m_tile_map;
};

#endif // GAME_STATE_H