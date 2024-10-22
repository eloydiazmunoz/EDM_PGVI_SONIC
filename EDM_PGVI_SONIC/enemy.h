// Definicio un bloqueig d'inclusió per evitar que aquest fitxer s'inclogui més d'una vegada.
#ifndef ENEMY_H
#define ENEMY_H

// Incloc la llibreria gràfica de SFML per utilitzar les seves funcions per a la gestió gràfica.
#include <SFML/Graphics.hpp>

// Definicio la classe Enemy, que representarà un enemic en el joc.
class Enemy {
public:
    // Declaro un constructor per inicialitzar els objectes d'aquesta classe.
    Enemy();

    // Declaro una funció anomenada update que acceptarà el temps transcorregut (deltaTime) i la posició del jugador.
    void update(sf::Time deltaTime, sf::Vector2f playerPosition);

    // Declaro una funció anomenada draw que dibuixarà l'enemic a la finestra proporcionada.
    void draw(sf::RenderWindow& window);

    // Declaro una funció anomenada setPosition que estableix la posició de l'enemic a les coordenades (x, y).
    void setPosition(float x, float y);

    // Declaro una funció anomenada getBounds que retornarà un rectangle flotant per obtenir el quadre de col·lisió de l'enemic.
    sf::FloatRect getBounds() const;

private:
    // Declaro una variable mShape de tipus sf::CircleShape que representarà gràficament l'enemic com un cercle.
    sf::CircleShape mShape;

    // Declaro una variable mSpeed que em servirà per emmagatzemar la velocitat de l'enemic.
    float mSpeed;
};

// Acabo el bloqueig d'inclusió per garantir que aquest fitxer s'inclogui només una vegada.
#endif // ENEMY_H
