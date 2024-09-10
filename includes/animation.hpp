#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>

// Class to store the position and sprite of an animation sprite
class AnimationSprite
{    
    public:
        AnimationSprite(int x, int y, sf::Sprite sprite);
        int x;
        int y;
        sf::Sprite sprite;
        bool isVisible = true;
};

// Base class for animations
class Animation
{
    public:
        Animation(int lifespan);
        virtual ~Animation() = default;  // Destructor
        virtual void update() = 0;
        int timer = 0;
        int lifespan;
        bool isExpired = false;
        std::vector<AnimationSprite> sprites;
};

#endif