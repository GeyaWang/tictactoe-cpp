#include "win_animation.hpp"

WinAnimation::WinAnimation(Assets& assets, int ls, int c, Status status, std::vector<std::vector<Piece>> boardState, std::vector<Coord>& line) : Animation(ls), gameStatus(status), winLine(line), cycle(c)
{
    // Load sprites
    sf::Sprite XSprite(*assets.getTexture("X"));
    sf::Sprite OSprite(*assets.getTexture("O"));

    // Copy board state
    Piece piece;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            piece = boardState[x][y];
            
            if (piece == Piece::X)
            {
                AnimationSprite sprite = AnimationSprite(x, y, XSprite);
                sprites.push_back(sprite);
            } else if (piece == Piece::O)
            {
                AnimationSprite sprite = AnimationSprite(x, y, OSprite);
                sprites.push_back(sprite);
            }
        }
    }
}

void WinAnimation::update()
{
    // Increment timer, check if expired
    timer++;
    if (timer >= lifespan)
    {
        isExpired = true;
    }

    // Flash sprites
    if (timer % cycle == 0)
    {
        // If draw, flash all sprites
        if (gameStatus == Status::DRAW)
        {
            for (auto& sprite : sprites)
            {  
                sprite.isVisible = !sprite.isVisible;
            }
        } else  // If win, flash only winning line
        {           
            for (auto& sprite : sprites)
            {   
                for (auto& coord : winLine)
                {
                    if (sprite.x == coord.x && sprite.y == coord.y)
                    {
                        sprite.isVisible = !sprite.isVisible;
                        break;
                    }
                }
            }
        }
    }
}
