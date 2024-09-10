#ifndef GAME_HPP
#define GAME_HPP

#include "piece.hpp"
#include "coord.hpp"
#include "board.hpp"
#include "settings.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

enum Status
{
	X_WIN,
	O_WIN,
	DRAW,
	IN_PROGRESS
};

// Class to handle game logic
class Game
{
	private:
		Piece currPlayer = DEFAULT_PLAYER;
		void changePlayer();
		Status checkGameStatus();
		void setGameStatus(Status status) { gameStatus = status; };
		Status getGameStatus(Piece piece) const;
	
	public:
		Game();
		void playTurn(int x, int y);
		Board board = Board(3, 3);
		Status gameStatus = IN_PROGRESS;
		std::vector<Coord> winLine;
};

#endif
