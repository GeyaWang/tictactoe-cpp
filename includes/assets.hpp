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
        void loadTexture(const std::string& name, const std::string& filepath);
        sf::Texture* getTexture(const std::string& name);
};

#endif
