#include "Enemy.h"
// Incloc el fitxer d'encap�alament "Enemy.h" per accedir a la definici� de la classe Enemy.

// Constructor
Enemy::Enemy()
    : mSpeed(50.f) // Estableixo una velocitat per als enemics
{
    mShape.setRadius(30.f); // Defino la mida de l'enemic establint el radi
    mShape.setFillColor(sf::Color::Blue); // Estableixo el color blau per a l'enemic
}

// Actualitza la posici� de l'enemic per tal que persegueixi al jugador
void Enemy::update(sf::Time deltaTime, sf::Vector2f playerPosition) {
    sf::Vector2f direction = playerPosition - mShape.getPosition(); // Calculo la direcci� cap al jugador
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y); // Obtenint la longitud de la direcci�
    if (length > 0) {
        direction /= length; // Normalitzo la direcci� per obtenir un vector unitari
        mShape.move(direction * mSpeed * deltaTime.asSeconds()); // Movo l'enemic cap al jugador
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(mShape); // Dibuixo l'enemic a la finestra
}

// Estableix la posici� de l'enemic
void Enemy::setPosition(float x, float y) {
    mShape.setPosition(x, y); // Estableixo la posici� de l'enemic a les coordenades (x, y)
}

// Obtiene el cuadro de colisi�n del enemigo
sf::FloatRect Enemy::getBounds() const {
    return mShape.getGlobalBounds(); // Retorno el quadre global que representa la col�lisi� de l'enemic
}
