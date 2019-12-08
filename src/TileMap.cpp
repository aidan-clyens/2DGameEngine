#include "TileMap.h"

TileMap::TileMap(const unsigned grid_size, const unsigned max_rows, const unsigned max_cols):
m_grid_size(grid_size),
m_max_rows(max_rows),
m_max_cols(max_cols)
{

}

TileMap::~TileMap() {
    save_to_file(TILE_MAP_FILE);

    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                delete m_map[y][x];
            }
        }
    }
}

void TileMap::add_tile(const std::string texture_name, const unsigned x, const unsigned y) {
    if (x < m_max_cols && x >= 0 && y < m_max_rows && y >= 0) {
        if (m_map[y][x] == nullptr) {
            m_map[y][x] = new GameObject(texture_name, sf::Vector2f(x*m_grid_size, y*m_grid_size));
        }
    }
}

void TileMap::remove_tile(const unsigned x, const unsigned y) {
    if (x < m_max_cols && x >= 0 && y < m_max_rows && y >= 0) {
        if (m_map[y][x] != nullptr) {
            delete m_map[y][x];
            m_map[y][x] = nullptr;
        }
    }
}

GameObject *TileMap::get_tile(const unsigned x, const unsigned y) {
    if (x < m_max_cols && x >= 0 && y < m_max_rows && y >= 0) {
        if (m_map[y][x] != nullptr) {
            return m_map[y][x];
        }
    }

    return nullptr;
}

void TileMap::load_tilemap() {
    load_empty_tile_map();

    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            add_tile("res/block.bmp", x, y);
        }
    }
}

void TileMap::load_empty_tile_map() {
    m_map.clear();

    for (unsigned y = 0; y < m_max_rows; y++) {
        m_map.push_back(std::vector<GameObject *>());

        for (unsigned x = 0; x < m_max_cols; x++) {
            m_map[y].push_back(nullptr);
        }
    }
}

void TileMap::save_to_file(const std::string file_name) {
    nlohmann::json json_file;

    json_file["grid_size"] = m_grid_size;
    json_file["num_rows"] = m_max_rows;
    json_file["num_cols"] = m_max_cols;
    json_file["tiles"] = nlohmann::json::array();

    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            GameObject *tile = get_tile(x, y);

            if (tile != nullptr) {
                nlohmann::json json_tile;
                json_tile["x"] = tile->get_position().x;
                json_tile["y"] = tile->get_position().y;
                json_tile["texture_path"] = tile->get_texture_name();
            
                json_file["tiles"].push_back(json_tile);
            }
        }
    }

    // Write JSON data to file
    std::ofstream file(file_name);
    file << std::setw(4) << json_file << std::endl;
    file.close();
}

void TileMap::load_from_file(const std::string file_name) {
    nlohmann::json json_file;
    std::ifstream file(file_name);

    file >> json_file;

    file.close();

    m_grid_size = json_file["grid_size"];
    m_max_rows = json_file["num_rows"];
    m_max_cols = json_file["num_cols"];

    load_empty_tile_map();

    for (nlohmann::json tile : json_file["tiles"]) {
        add_tile(tile["texture_path"], static_cast<unsigned>(tile["x"]) / m_grid_size, static_cast<unsigned>(tile["y"]) / m_grid_size);
    }
}

void TileMap::update() {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                m_map[y][x]->update();
            }
        }
    }
}

void TileMap::render(sf::RenderWindow &render_window) {
    for (unsigned y = 0; y < m_max_rows; y++) {
        for (unsigned x = 0; x < m_max_cols; x++) {
            if (m_map[y][x] != nullptr) {
                m_map[y][x]->render(render_window);
            }
        }
    }
}