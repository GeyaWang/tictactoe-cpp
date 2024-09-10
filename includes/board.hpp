#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "piece.hpp"


class Board
{
    private:
        std::size_t nRows;
        std::size_t nCols;

    public:
        Board(std::size_t nRows = 3, std::size_t nCols = 3);
        void clear();
        std::vector<std::vector<Piece>> state;
};

#endif