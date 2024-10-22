#include "Player.h"
// Incloc el fitxer d'encapçalament "Player.h" per tenir accés a la classe Player i les seves funcions.

#include "TextureHolder.h"
// Incloc el fitxer d'encapçalament "TextureHolder.h" per poder utilitzar el gestor de textures.

const float Player::PlayerSpeed = 400.f; // Ajusto la velocitat del jugador

// Definio el constructor de la classe Player.
Player::Player()
    : mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
    // Inicialitzo les variables de moviment a fals al constructor.
{
    // Estableixo la textura del sprite del jugador carregant-la amb el gestor de textures.
    mSprite.setTexture(TextureHolder::GetInstance().GetTexture("E:/AluCiclesGS2/EDM/EDM 2n/PGVI/UF1/EDM_PGVI_SONIC/x64/Debug/Personatge.png"));

    // Ajusto la mida del sprite.
    sf::FloatRect bounds = mSprite.getGlobalBounds(); // Obtenint els límits globals del sprite.
    mSprite.setPosition(100.f, 300.f); // Estableixo la posició inicial del sprite.
    mSprite.setScale(150.f / bounds.width, 150.f / bounds.height);  // Escalo el sprite per ajustar-lo.

    mLastPosition = mSprite.getPosition();  // Guardar la posició inicial.
}

// Definio el mètode handleInput per gestionar l'entrada del teclat.
void Player::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    // Comprovo quina tecla s'ha premut i actualitzo les variables de moviment.
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

// Definio el mètode update per actualitzar l'estat del jugador.
void Player::update(sf::Time deltaTime)
{
    mLastPosition = mSprite.getPosition();  // Guardar la última posició

    sf::Vector2f movement(0.f, 0.f); // Declaro un vector de moviment inicialitzat a zero.
    // Actualitzo el vector de moviment en funció de les tecles premudes.
    if (mIsMovingUp) movement.y -= PlayerSpeed;
    if (mIsMovingDown) movement.y += PlayerSpeed;
    if (mIsMovingLeft) movement.x -= PlayerSpeed;
    if (mIsMovingRight) movement.x += PlayerSpeed;

    // Movo el jugador en funció del moviment calculat i el temps transcorregut.
    mSprite.move(movement * deltaTime.asSeconds());
}

// Definio el mètode draw per dibuixar el jugador a la finestra.
void Player::draw(sf::RenderWindow& window)
{
    window.draw(mSprite); // Dibuixo el sprite del jugador a la finestra.
}

// Definio el mètode getBounds per obtenir els límits del jugador.
sf::FloatRect Player::getBounds() const
{
    return mSprite.getGlobalBounds(); // Retorno els límits globals del sprite.
}

// Definio el mètode revertMovement per revertir el moviment en cas de col·lisió.
void Player::revertMovement()
{
    mSprite.setPosition(mLastPosition);  // Revertir a la última posició enregistrada.
}

// Definio el mètode getPosition per obtenir la posició actual del jugador.
sf::Vector2f Player::getPosition() const
{
    return mSprite.getPosition(); // Retorno la posició actual del jugador.
}
