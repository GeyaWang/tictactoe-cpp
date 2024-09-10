#include "draw.hpp"
#include "settings.hpp"

Draw::Draw(sf::RenderWindow& w, Assets& assets) : window(w)
{
    sf::Sprite board(*assets.getTexture("BOARD"));
    sf::Sprite x(*assets.getTexture("X"));
    sf::Sprite o(*assets.getTexture("O"));

    this->boardSprite = board;
    this->XSprite = x;
    this->OSprite = o;
}

void Draw::drawBoard() const
{
    window.draw(boardSprite);
}

void Draw::drawPieces(std::vector<std::vector<Piece>> board)
{
    // Draw pieces
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == Piece::X)
            {
                XSprite.setPosition(i * CELL_SIZE + BOARD_PADDING, j * CELL_SIZE + BOARD_PADDING);
                window.draw(XSprite);
            }
            else if (board[i][j] == Piece::O)
            {
                OSprite.setPosition(i * CELL_SIZE + BOARD_PADDING, j * CELL_SIZE + BOARD_PADDING);
                window.draw(OSprite);
            }
        }
    }
}

void Draw::drawAnimation(Animation& animation) const
{
    for (auto& sprite : animation.sprites)
    {   
        if (sprite.isVisible)
        {
            sprite.sprite.setPosition(sprite.x * CELL_SIZE + BOARD_PADDING, sprite.y * CELL_SIZE + BOARD_PADDING);
            window.draw(sprite.sprite);
        }
    }
}
