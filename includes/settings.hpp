#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>
#include <map>
#include "piece.hpp"

const std::string WINDOW_NAME = "TicTacToe";
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 540;
const int CELL_SIZE = 150;
const int BOARD_PADDING = 45;

const int FPS = 30;

const Piece DEFAULT_PLAYER = Piece::X;

const std::map<std::string, std::string> TEXTURES = {
    {"X", "../assets/X.png"},
    {"O", "../assets/O.png"},
    {"BOARD", "../assets/board.png"}
};

#endif