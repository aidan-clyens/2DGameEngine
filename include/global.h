#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>

#include "TextureManager.h"
#include "InputManager.h"

// Definitions
#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

const std::string PLAYER_IMG = "res/player.bmp";

// Global variables
extern InputManager *input_manager;
extern TextureManager *texture_manager;

#endif // GLOBAL_H