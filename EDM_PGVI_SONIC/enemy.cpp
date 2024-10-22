#include "Enemy.h"
// Incloc el fitxer d'encapçalament "Enemy.h" per accedir a la definició de la classe Enemy.

// Constructor
Enemy::Enemy()
    : mSpeed(50.f) // Estableixo una velocitat per als enemics
{
    mShape.setRadius(30.f); // Defino la mida de l'enemic establint el radi
    mShape.setFillColor(sf::Color::Blue); // Estableixo el color blau per a l'enemic
}

// Actualitza la posició de l'enemic per tal que persegueixi al jugador
void Enemy::update(sf::Time deltaTime, sf::Vector2f playerPosition) {
    sf::Vector2f direction = playerPosition - mShape.getPosition(); // Calculo la direcció cap al jugador
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y); // Obtenint la longitud de la direcció
    if (length > 0) {
        direction /= length; // Normalitzo la direcció per obtenir un vector unitari
        mShape.move(direction * mSpeed * deltaTime.asSeconds()); // Movo l'enemic cap al jugador
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(mShape); // Dibuixo l'enemic a la finestra
}

// Estableix la posició de l'enemic
void Enemy::setPosition(float x, float y) {
    mShape.setPosition(x, y); // Estableixo la posició de l'enemic a les coordenades (x, y)
}

// Obtiene el cuadro de colisión del enemigo
sf::FloatRect Enemy::getBounds() const {
    return mShape.getGlobalBounds(); // Retorno el quadre global que representa la col·lisió de l'enemic
}
