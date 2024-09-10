#include "animation.hpp"

AnimationSprite::AnimationSprite(int X, int Y, sf::Sprite S) : x(X), y(Y), sprite(S) {}

Animation::Animation(int l) : lifespan(l) {}
