#include "GameState.h"

GameState::GameState(sf::RenderWindow &render_window):
State(render_window),
m_player(new Player("res/player.bmp"))
{

}

GameState::~GameState() {
    delete m_player;
    delete m_tile_map;
}

void GameState::check_for_quit() {
    
}

void GameState::quit_state() {
    
}

void GameState::update() {
    m_tile_map->update();
    m_player->update();

    for (GameObject *g : m_game_objects) {
        g->update();
    }
}

void GameState::render() {
    m_tile_map->render(m_render_window);
    m_player->render(m_render_window);

    for (GameObject *g : m_game_objects) {
        g->render(m_render_window);
    }
}

void GameState::load_level(TileMap *tile_map) {
    m_tile_map = tile_map;

    m_tile_map->load_tilemap();
}

void GameState::add_game_object(GameObject *g) {
    m_game_objects.push_back(g);
}

void GameState::remove_game_object(GameObject &g) {
    // TODO
}