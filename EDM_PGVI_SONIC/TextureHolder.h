// Definicio un bloqueig d'inclusió per evitar que aquest fitxer s'inclogui més d'una vegada.
#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

// Incloc la llibreria gràfica de SFML per gestionar textures i gràfics.
#include <SFML/Graphics.hpp>
// Incloc la llibreria map per utilitzar estructures de dades que associïn claus amb valors.
#include <map>
// Incloc la llibreria string per poder treballar amb cadenes de caràcters.
#include <string>
// Incloc la llibreria stdexcept per gestionar excepcions i errors.
#include <stdexcept>

// Definicio la classe TextureHolder, que s'encarregarà de gestionar textures.
class TextureHolder
{
public:
    // Declaro un mètode estàtic que retorna una instància de TextureHolder.
    static TextureHolder& GetInstance()
    {
        // Crec una instància estàtica per assegurar-me que només n'hi hagi una.
        static TextureHolder instance;
        return instance; // Retorno la instància única.
    }

    // Declaro un mètode que retorna una referència a una textura, donant-li el nom del fitxer corresponent.
    sf::Texture& GetTexture(const std::string& filename);

private:
    // Declaro un constructor privat per evitar que es creïn instàncies externes.
    TextureHolder() {}

    // Declaro el constructor de còpia com a eliminat per evitar còpies de l'instància.
    TextureHolder(const TextureHolder&) = delete;

    // Declaro l'operador d'assignació com a eliminat per evitar l'assignació de l'instància.
    TextureHolder& operator=(const TextureHolder&) = delete;

    // Declaro un mapa per emmagatzemar les textures associades amb els seus noms de fitxer.
    std::map<std::string, sf::Texture> m_Textures;
};

// Acabo el bloqueig d'inclusió per garantir que aquest fitxer s'inclogui només una vegada.
#endif // TEXTUREHOLDER_H
