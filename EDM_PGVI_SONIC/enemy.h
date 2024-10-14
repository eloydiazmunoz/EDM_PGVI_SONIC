#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    void update(sf::Time deltaTime, sf::Vector2f playerPosition); // Ahora acepta la posición del jugador
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y); // Establece la posición del enemigo
    sf::FloatRect getBounds() const; // Para obtener el cuadro de colisión

private:
    sf::CircleShape mShape; // Usar un círculo para el enemigo
    float mSpeed; // Velocidad del enemigo
};

#endif // ENEMY_H