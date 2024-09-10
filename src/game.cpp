#include "game.hpp"

Game::Game() {}

void Game::change_player()
{
	// O <-> X
	currPlayer = (currPlayer == Piece::X) ? Piece::O : Piece::X;
}

Status Game::get_game_status(Piece piece) const
{
	return (piece == Piece::X) ? Status::X_WIN : Status::O_WIN;
}

Status Game::check_game_status()
{
	// Init piece variable
	Piece piece;


	// Check rows
	for (int x = 0; x < 3; x++)
	{
		piece = board.state[x][0];
		if (piece != Piece::EMPTY && piece == board.state[x][1] && board.state[x][1] == board.state[x][2])
		{
			winLine = {Coord(x, 0), Coord(x, 1), Coord(x, 2)};
			return get_game_status(piece);
		}
	}


	// Check columns
	for (int y = 0; y < 3; y++)
	{	
		piece = board.state[0][y];
		if (piece != Piece::EMPTY && piece == board.state[1][y] && board.state[1][y] == board.state[2][y])
		{
			winLine = {Coord(0, y), Coord(1, y), Coord(2, y)};
			return get_game_status(piece);
		}
	}


	// Check diagonals
	piece = board.state[0][0];
	if (piece != Piece::EMPTY && piece == board.state[1][1] && board.state[1][1] == board.state[2][2])
	{
		winLine = {Coord(0, 0), Coord(1, 1), Coord(2, 2)};
		return get_game_status(piece);
	}

	piece = board.state[0][2];
	if (piece != Piece::EMPTY && piece == board.state[1][1] && board.state[1][1] == board.state[2][0])
	{
		winLine = {Coord(0, 2), Coord(1, 1), Coord(2, 0)};
		return get_game_status(piece);
	}


	// Check if board is full
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{	
			if (board.state[x][y] == Piece::EMPTY)
			{
				// Empty space found
				return Status::IN_PROGRESS;
			}
		}
	}

	// Board is full
	return Status::DRAW;
}

void Game::play_turn(int x, int y)
{
	// If game over, reset game
	if (gameStatus != Status::IN_PROGRESS)
	{
		board.clear();
		set_game_status(Status::IN_PROGRESS);
		currPlayer = DEFAULT_PLAYER;
	}

	// Check if move is valid
	if (board.state[x][y] != Piece::EMPTY)
	{
		return;
	}

	// Play turn
	board.state[x][y] = currPlayer;
	change_player();

	// Check if game over
	set_game_status(check_game_status());
}
