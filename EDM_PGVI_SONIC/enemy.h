// Definicio un bloqueig d'inclusi� per evitar que aquest fitxer s'inclogui m�s d'una vegada.
#ifndef ENEMY_H
#define ENEMY_H

// Incloc la llibreria gr�fica de SFML per utilitzar les seves funcions per a la gesti� gr�fica.
#include <SFML/Graphics.hpp>

// Definicio la classe Enemy, que representar� un enemic en el joc.
class Enemy {
public:
    // Declaro un constructor per inicialitzar els objectes d'aquesta classe.
    Enemy();

    // Declaro una funci� anomenada update que acceptar� el temps transcorregut (deltaTime) i la posici� del jugador.
    void update(sf::Time deltaTime, sf::Vector2f playerPosition);

    // Declaro una funci� anomenada draw que dibuixar� l'enemic a la finestra proporcionada.
    void draw(sf::RenderWindow& window);

    // Declaro una funci� anomenada setPosition que estableix la posici� de l'enemic a les coordenades (x, y).
    void setPosition(float x, float y);

    // Declaro una funci� anomenada getBounds que retornar� un rectangle flotant per obtenir el quadre de col�lisi� de l'enemic.
    sf::FloatRect getBounds() const;

private:
    // Declaro una variable mShape de tipus sf::CircleShape que representar� gr�ficament l'enemic com un cercle.
    sf::CircleShape mShape;

    // Declaro una variable mSpeed que em servir� per emmagatzemar la velocitat de l'enemic.
    float mSpeed;
};

// Acabo el bloqueig d'inclusi� per garantir que aquest fitxer s'inclogui nom�s una vegada.
#endif // ENEMY_H
