// Definicio un bloqueig d'inclusió per evitar que aquest fitxer s'inclogui més d'una vegada.
#ifndef PLAYER_H
#define PLAYER_H

// Incloc la llibreria gràfica de SFML per gestionar gràfics i sprites.
#include <SFML/Graphics.hpp>

// Definicio la classe Player, que representarà un jugador en el joc.
class Player
{
public:
    // Declaro el constructor de la classe Player.
    Player();

    // Declaro un mètode per gestionar l'entrada del teclat, que accepta la tecla i un booleà que indica si està premuda.
    void handleInput(sf::Keyboard::Key key, bool isPressed);

    // Declaro un mètode per actualitzar l'estat del jugador en funció del temps transcorregut.
    void update(sf::Time deltaTime);

    // Declaro un mètode per dibuixar el jugador a la finestra proporcionada.
    void draw(sf::RenderWindow& window);

    // Declaro un mètode per obtenir els límits del jugador com un rectangle flotant.
    sf::FloatRect getBounds() const;  // Obtener los límites del jugador

    // Declaro un mètode per revertir el moviment en cas de col·lisió.
    void revertMovement();

    // Declaro un mètode per obtenir la posició actual del jugador.
    sf::Vector2f getPosition() const; // Obtener la posición del jugador

private:
    // Declaro un sprite per representar gràficament el jugador.
    sf::Sprite mSprite;

    // Declaro un vector per guardar la darrera posició del jugador.
    sf::Vector2f mLastPosition;  // Guardar la última posición

    // Declaro variables booleanes per controlar els moviments en les diferents direccions.
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    // Declaro una constant estàtica que representarà la velocitat del jugador.
    static const float PlayerSpeed;
};

// Acabo el bloqueig d'inclusió per garantir que aquest fitxer s'inclogui només una vegada.
#endif // PLAYER_H
