#ifndef EDITOR_STATE_H
#define EDITOR_STATE_H

#include "State.h"
#include "TileMap.h"

class EditorState : public State {
    public:
        EditorState(sf::RenderWindow &render_window);
        virtual ~EditorState();

        void check_for_quit();

        void quit_state();

        void update();
        void render();

        void load_level(TileMap *tile_map);

    private:
        TileMap *m_tile_map;
};

#endif // EDITOR_STATE_H