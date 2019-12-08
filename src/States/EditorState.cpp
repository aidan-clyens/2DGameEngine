#include "EditorState.h"

EditorState::EditorState(sf::RenderWindow &render_window):
State(render_window)
{

}

EditorState::~EditorState() {
    delete m_tile_map;
}

void EditorState::check_for_quit() {

}

void EditorState::quit_state() {

}

void EditorState::update() {
    // Create a tile on mouse click
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mouse_pos = input_manager->get_mouse_position_view();

        unsigned x = mouse_pos.x / m_tile_map->get_grid_size();
        unsigned y = mouse_pos.y / m_tile_map->get_grid_size();

        m_tile_map->add_tile("res/block.bmp", x, y);
    }

    m_tile_map->update();
}

void EditorState::render() {
    m_tile_map->render(m_render_window);
}

void EditorState::load_level(TileMap *tile_map) {
    m_tile_map = tile_map;

    m_tile_map->load_empty_tile_map();
}