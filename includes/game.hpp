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
		void change_player();
		Status check_game_status();
		void set_game_status(Status status) { gameStatus = status; };
		Status get_game_status(Piece piece) const;
	
	public:
		Game();
		void play_turn(int x, int y);
		Board board = Board(3, 3);
		Status gameStatus = IN_PROGRESS;
		std::vector<Coord> winLine;
};

#endif
