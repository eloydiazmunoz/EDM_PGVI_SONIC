// Definicio un bloqueig d'inclusi� per evitar que aquest fitxer s'inclogui m�s d'una vegada.
#ifndef PLAYER_H
#define PLAYER_H

// Incloc la llibreria gr�fica de SFML per gestionar gr�fics i sprites.
#include <SFML/Graphics.hpp>

// Definicio la classe Player, que representar� un jugador en el joc.
class Player
{
public:
    // Declaro el constructor de la classe Player.
    Player();

    // Declaro un m�tode per gestionar l'entrada del teclat, que accepta la tecla i un boole� que indica si est� premuda.
    void handleInput(sf::Keyboard::Key key, bool isPressed);

    // Declaro un m�tode per actualitzar l'estat del jugador en funci� del temps transcorregut.
    void update(sf::Time deltaTime);

    // Declaro un m�tode per dibuixar el jugador a la finestra proporcionada.
    void draw(sf::RenderWindow& window);

    // Declaro un m�tode per obtenir els l�mits del jugador com un rectangle flotant.
    sf::FloatRect getBounds() const;  // Obtener los l�mites del jugador

    // Declaro un m�tode per revertir el moviment en cas de col�lisi�.
    void revertMovement();

    // Declaro un m�tode per obtenir la posici� actual del jugador.
    sf::Vector2f getPosition() const; // Obtener la posici�n del jugador

private:
    // Declaro un sprite per representar gr�ficament el jugador.
    sf::Sprite mSprite;

    // Declaro un vector per guardar la darrera posici� del jugador.
    sf::Vector2f mLastPosition;  // Guardar la �ltima posici�n

    // Declaro variables booleanes per controlar els moviments en les diferents direccions.
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    // Declaro una constant est�tica que representar� la velocitat del jugador.
    static const float PlayerSpeed;
};

// Acabo el bloqueig d'inclusi� per garantir que aquest fitxer s'inclogui nom�s una vegada.
#endif // PLAYER_H
