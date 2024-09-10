#include <SFML/Graphics.hpp>
#include <iostream>
#include <tuple>
#include "game.hpp"
#include "settings.hpp"
#include "draw.hpp"
#include "assets.hpp"
#include "win_animation.hpp"


int getRelPos(int n)
{
	// 0: 0-195, 1: 196-345, 2: 346-540
	return (n <= 195) ? 0 : (n <= 345) ? 1 : 2;
}

std::tuple<int, int> getMouseCoords(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	return std::make_tuple(getRelPos(mousePos.x), getRelPos(mousePos.y));
}

void gameOverAnimation(sf::RenderWindow& window, Game& game, Draw& draw, Assets& assets)
{
	WinAnimation animation = WinAnimation(assets, 54, 6, game.gameStatus, game.board.state, game.winLine);

	while (window.isOpen())
	{
		// Detect close window event
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Draw
		window.clear(sf::Color::Black);
		draw.drawBoard();
		draw.drawAnimation(animation);
		window.display();

		// Update animation
		animation.update();

		if (animation.isExpired) {
			// Animation finished
			break;
		}
	}
}

void loadSprites(Assets& assets)
{
	for (const auto& [name, path] : TEXTURES)
	{
		assets.loadTexture(name, path);
	}

	std::cout << "Sprites loaded\n";
}

int main()
{	
	// Init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_NAME);
	window.setFramerateLimit(FPS);

	Assets assets;

	// Load sprites
	loadSprites(assets);

	// Game and draw objects
	Game game;
	Draw draw(window, assets);

	// Start by drawing board
	draw.drawBoard();
	window.display();

	// Relative mouse coordinates
	int x; int y;

	
	// Game loop
	while (window.isOpen())
	{
		// Event handelling
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// LMB click
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					// Get mouse position
					std::tie(x, y) = getMouseCoords(window);

					// Play turn
					game.playTurn(x, y);

					// Draw board and pieces
					window.clear();
					draw.drawBoard();
					draw.drawPieces(game.board.state);
					window.display();

					// If game over, play animation
					if (game.gameStatus != Status::IN_PROGRESS)
					{
						gameOverAnimation(window, game, draw, assets);

						// End by drawing empty board
						draw.drawBoard();
						window.display();
					}
				}	
			}
		}
	}
	
	return 0;
}
