#include <SFML/Graphics.hpp>
#include <iostream>
#include <tuple>
#include "game.hpp"
#include "settings.hpp"
#include "draw.hpp"
#include "assets.hpp"
#include "win_animation.hpp"


int get_rel_pos(int n)
{
	// 0: 0-195, 1: 196-345, 2: 346-540
	return (n <= 195) ? 0 : (n <= 345) ? 1 : 2;
}

std::tuple<int, int> get_mouse_coords(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	return std::make_tuple(get_rel_pos(mousePos.x), get_rel_pos(mousePos.y));
}

void play_game_over_animation(sf::RenderWindow& window, Game& game, Draw& draw, Assets& assets)
{
	WinAnimation animation = WinAnimation(assets, 42, 6, game.gameStatus, game.board.state, game.winLine);

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
		draw.draw_board();
		draw.draw_animation(animation);
		window.display();

		// Update animation
		animation.update();

		if (animation.isExpired) {
			// Animation finished
			break;
		}
	}
}

void load_sprites(Assets& assets)
{
	for (const auto& [name, path] : TEXTURES)
	{
		assets.load_texture(name, path);
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
	load_sprites(assets);

	// Game and draw objects
	Game game;
	Draw draw(window, assets);

	// Start by drawing board
	draw.draw_board();
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
					std::tie(x, y) = get_mouse_coords(window);

					// Play turn
					game.play_turn(x, y);

					// Draw board and pieces
					window.clear();
					draw.draw_board();
					draw.draw_pieces(game.board.state);
					window.display();

					// If game over, play animation
					if (game.gameStatus != Status::IN_PROGRESS)
					{
						play_game_over_animation(window, game, draw, assets);

						// End by drawing empty board
						draw.draw_board();
						window.display();
					}
				}	
			}
		}
	}
	
	return 0;
}
