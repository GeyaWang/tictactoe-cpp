#include "draw.hpp"
#include "settings.hpp"

Draw::Draw(sf::RenderWindow& w, Assets& assets) : window(w)
{
    sf::Sprite board(*assets.get_texture("BOARD"));
    sf::Sprite x(*assets.get_texture("X"));
    sf::Sprite o(*assets.get_texture("O"));

    this->boardSprite = board;
    this->XSprite = x;
    this->OSprite = o;
}

void Draw::draw_board() const
{
    window.draw(boardSprite);
}

void Draw::draw_pieces(std::vector<std::vector<Piece>> board)
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

void Draw::draw_animation(Animation& animation) const
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
