#include "assets.hpp"
#include <iostream>

Assets::Assets() {}

void Assets::load_texture(const std::string& name, const std::string& filepath)
{
    sf::Texture texture;

    if (!texture.loadFromFile(filepath))
    {
        std::cerr << "Error: Failed to load texture\n";
        return;
    }

    textures[name] = texture;
}

sf::Texture* Assets::get_texture(const std::string& name)
{
    auto it = textures.find(name);
    if (it != textures.end())
    {
        return &it->second;
    }

    std::cerr << "Error: Sprite not found\n";
    return nullptr;
}
