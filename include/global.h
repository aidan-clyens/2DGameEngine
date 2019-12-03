#ifndef GLOBAL_H
#define GLOBAL_H

// STL includes
#include <string>
#include <list>
#include <stack>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

// Local includes
#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"

// Definitions
#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define LEVEL_COLS      16
#define LEVEL_ROWS      12

#define BLOCK_WIDTH     (WINDOW_WIDTH / LEVEL_COLS)

#define PLAYER_SPEED    8

// Fonts
const std::string PLAYER_IMG = "res/player.bmp";
const std::string SANS_REGULAR_FONT = "res/fonts/open-sans/OpenSans-Regular.ttf";
const std::string SANS_SEMIBOLD_FONT = "res/fonts/open-sans/OpenSans-Semibold.ttf";
const std::string SANS_BOLD_FONT = "res/fonts/open-sans/OpenSans-Bold.ttf";

// Colours
const sf::Color TEXT_COLOR_LIGHT = sf::Color::White;
const sf::Color TEXT_COLOR_DARK = sf::Color::Black;
const sf::Color MENU_BACKGROUND_COLOR(251, 245, 243);
const sf::Color BUTTON_IDLE_COLOR(166, 0, 103);
const sf::Color BUTTON_HOVER_COLOR(150, 29, 78);
const sf::Color BUTTON_ACTIVE_COLOR(113, 6, 39);

// Config files
const std::string WINDOW_CONFIG_FILE = "config/window.ini";
const std::string TILE_MAP_FILE = "config/tilemap.json";

// Global variables
extern InputManager *input_manager;
extern FontManager *font_manager;
extern TextureManager *texture_manager;

#endif // GLOBAL_H