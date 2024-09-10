#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Assets
{
    private:
        std::map<std::string, sf::Texture> textures;

    public:
        Assets();
        void load_texture(const std::string& name, const std::string& filepath);
        sf::Texture* get_texture(const std::string& name);
};

#endif
