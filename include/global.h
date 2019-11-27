#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <list>
#include <stack>

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

const std::string PLAYER_IMG = "res/player.bmp";

// Global variables
extern InputManager *input_manager;
extern FontManager *font_manager;
extern TextureManager *texture_manager;

#endif // GLOBAL_H