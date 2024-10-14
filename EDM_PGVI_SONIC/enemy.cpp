#include "Enemy.h"

// Constructor
Enemy::Enemy()
    : mSpeed(50.f) // Establece una velocidad para los enemigos
{
    mShape.setRadius(30.f); // Define el tamaño del enemigo
    mShape.setFillColor(sf::Color::Blue); // Color azul
}

// Actualiza la posición del enemigo para que persiga al jugador
void Enemy::update(sf::Time deltaTime, sf::Vector2f playerPosition) {
    sf::Vector2f direction = playerPosition - mShape.getPosition(); // Calcula la dirección hacia el jugador
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0) {
        direction /= length; // Normaliza la dirección
        mShape.move(direction * mSpeed * deltaTime.asSeconds()); // Mueve al enemigo hacia el jugador
    }
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(mShape);
}

// Establece la posición del enemigo
void Enemy::setPosition(float x, float y) {
    mShape.setPosition(x, y);
}

// Obtiene el cuadro de colisión del enemigo
sf::FloatRect Enemy::getBounds() const {
    return mShape.getGlobalBounds();
}