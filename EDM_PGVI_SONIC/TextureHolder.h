#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <stdexcept>

class TextureHolder
{
public:
    static TextureHolder& GetInstance()
    {
        static TextureHolder instance;
        return instance;
    }

    sf::Texture& GetTexture(const std::string& filename);

private:
    TextureHolder() {}
    TextureHolder(const TextureHolder&) = delete;
    TextureHolder& operator=(const TextureHolder&) = delete;

    std::map<std::string, sf::Texture> m_Textures;
};

#endif // TEXTUREHOLDER_H