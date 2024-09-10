#include "board.hpp"

Board::Board(std::size_t r, std::size_t c) : nRows(r), nCols(c)
{
    clear();
}

void Board::clear()
{
    state = std::vector<std::vector<Piece>>(nRows, std::vector<Piece>(nCols, Piece::EMPTY));
}
