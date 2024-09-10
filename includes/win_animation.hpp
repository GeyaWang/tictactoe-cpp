#ifndef WIN_ANIMATION_HPP
#define WIN_ANIMATION_HPP

#include "animation.hpp"
#include "game.hpp"
#include "assets.hpp"
#include <vector>

// Child class to animate the game over animation
class WinAnimation : public Animation
{
    private:
        std::vector<Coord>& winLine;
        int cycle;
        Status gameStatus;
    
    public:
        WinAnimation(Assets& assets, int lifespan, int cycle, Status gameStatus, std::vector<std::vector<Piece>> boardState, std::vector<Coord>& winLine);
        void update() override;
};

#endif
