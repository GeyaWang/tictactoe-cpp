#ifndef DRAW_HPP
#define DRAW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "animation.hpp"
#include "piece.hpp"
#include "assets.hpp"

// Class to handle drawing to the window
class Draw
{
    private:
        sf::RenderWindow& window;
        sf::Sprite boardSprite;
        sf::Sprite XSprite;
        sf::Sprite OSprite;
        Animation* currentAnimation;

    public:
        Draw(sf::RenderWindow& window, Assets& assets);
        void drawBoard() const;
        void drawPieces(std::vector<std::vector<Piece>> board);
        void drawAnimation(Animation& animation) const;
};

#endif