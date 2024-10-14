#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    void update(sf::Time deltaTime, sf::Vector2f playerPosition); // Ahora acepta la posici�n del jugador
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y); // Establece la posici�n del enemigo
    sf::FloatRect getBounds() const; // Para obtener el cuadro de colisi�n

private:
    sf::CircleShape mShape; // Usar un c�rculo para el enemigo
    float mSpeed; // Velocidad del enemigo
};

#endif // ENEMY_H