// Incloc el fitxer d'encapçalament "TextureHolder.h" per tenir accés a la classe TextureHolder i les seves declaracions.
#include "TextureHolder.h"

// Definio el mètode GetTexture que pertany a la classe TextureHolder i retorna una referència a una textura.
sf::Texture& TextureHolder::GetTexture(const std::string& filename)
{
    // Declaro una referència a m_Textures per facilitar l'accés al mapa de textures.
    auto& m = m_Textures;

    // Busco si el nom del fitxer (filename) ja existeix al mapa de textures.
    auto keyValuePair = m.find(filename);

    // Comprovo si el nom del fitxer s'ha trobat al mapa.
    if (keyValuePair != m.end())
    {
        // Si el fitxer existeix, retorno la textura associada a aquest nom.
        return keyValuePair->second;
    }
    else
        // Si el fitxer no es troba al mapa...
    {
        // Declaro una nova referència a la textura que s'emmagatzemarà al mapa per a aquest nom de fitxer.
        auto& texture = m[filename];

        // Intento carregar la textura des del fitxer. Si falla...
        if (!texture.loadFromFile(filename))
        {
            // Llanço una excepció indicant que ha fallat la càrrega de la textura.
            throw std::runtime_error("Failed to load texture: " + filename);
        }
        // Retorno la textura que s'ha carregat correctament.
        return texture;
    }
}
