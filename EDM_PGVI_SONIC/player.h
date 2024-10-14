#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void handleInput(sf::Keyboard::Key key, bool isPressed);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;  // Obtener los l�mites del jugador
    void revertMovement();  // Revertir el movimiento en caso de colisi�n
    sf::Vector2f getPosition() const; // Obtener la posici�n del jugador

private:
    sf::Sprite mSprite;
    sf::Vector2f mLastPosition;  // Guardar la �ltima posici�n
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    static const float PlayerSpeed;
};

#endif // PLAYER_H