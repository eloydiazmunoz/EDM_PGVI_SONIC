#include "TextureHolder.h"

sf::Texture& TextureHolder::GetTexture(const std::string& filename)
{
    auto& m = m_Textures;
    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        auto& texture = m[filename];
        if (!texture.loadFromFile(filename))
        {
            throw std::runtime_error("Failed to load texture: " + filename);
        }
        return texture;
    }
}