// Definicio un bloqueig d'inclusi� per evitar que aquest fitxer s'inclogui m�s d'una vegada.
#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

// Incloc la llibreria gr�fica de SFML per gestionar textures i gr�fics.
#include <SFML/Graphics.hpp>
// Incloc la llibreria map per utilitzar estructures de dades que associ�n claus amb valors.
#include <map>
// Incloc la llibreria string per poder treballar amb cadenes de car�cters.
#include <string>
// Incloc la llibreria stdexcept per gestionar excepcions i errors.
#include <stdexcept>

// Definicio la classe TextureHolder, que s'encarregar� de gestionar textures.
class TextureHolder
{
public:
    // Declaro un m�tode est�tic que retorna una inst�ncia de TextureHolder.
    static TextureHolder& GetInstance()
    {
        // Crec una inst�ncia est�tica per assegurar-me que nom�s n'hi hagi una.
        static TextureHolder instance;
        return instance; // Retorno la inst�ncia �nica.
    }

    // Declaro un m�tode que retorna una refer�ncia a una textura, donant-li el nom del fitxer corresponent.
    sf::Texture& GetTexture(const std::string& filename);

private:
    // Declaro un constructor privat per evitar que es cre�n inst�ncies externes.
    TextureHolder() {}

    // Declaro el constructor de c�pia com a eliminat per evitar c�pies de l'inst�ncia.
    TextureHolder(const TextureHolder&) = delete;

    // Declaro l'operador d'assignaci� com a eliminat per evitar l'assignaci� de l'inst�ncia.
    TextureHolder& operator=(const TextureHolder&) = delete;

    // Declaro un mapa per emmagatzemar les textures associades amb els seus noms de fitxer.
    std::map<std::string, sf::Texture> m_Textures;
};

// Acabo el bloqueig d'inclusi� per garantir que aquest fitxer s'inclogui nom�s una vegada.
#endif // TEXTUREHOLDER_H
