#include "GameState.h"

GameState::GameState(sf::RenderWindow &render_window):
State(render_window),
m_player(new Player("res/player.bmp"))
{

}

GameState::~GameState() {
    delete m_player;
    delete m_level;
}

void GameState::update() {
    m_level->update();
    m_player->update();

    for (GameObject *g : m_game_objects) {
        g->update();
    }
}

void GameState::render() {
    m_level->render(m_render_window);
    m_player->render(m_render_window);

    for (GameObject *g : m_game_objects) {
        g->render(m_render_window);
    }
}

void GameState::load_level(Level *level) {
    m_level = level;
}

void GameState::add_game_object(GameObject *g) {
    m_game_objects.push_back(g);
}

void GameState::remove_game_object(GameObject &g) {
    // TODO
}