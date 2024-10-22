#include "Player.h"
// Incloc el fitxer d'encap�alament "Player.h" per tenir acc�s a la classe Player i les seves funcions.

#include "TextureHolder.h"
// Incloc el fitxer d'encap�alament "TextureHolder.h" per poder utilitzar el gestor de textures.

const float Player::PlayerSpeed = 400.f; // Ajusto la velocitat del jugador

// Definio el constructor de la classe Player.
Player::Player()
    : mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
    // Inicialitzo les variables de moviment a fals al constructor.
{
    // Estableixo la textura del sprite del jugador carregant-la amb el gestor de textures.
    mSprite.setTexture(TextureHolder::GetInstance().GetTexture("E:/AluCiclesGS2/EDM/EDM 2n/PGVI/UF1/EDM_PGVI_SONIC/x64/Debug/Personatge.png"));

    // Ajusto la mida del sprite.
    sf::FloatRect bounds = mSprite.getGlobalBounds(); // Obtenint els l�mits globals del sprite.
    mSprite.setPosition(100.f, 300.f); // Estableixo la posici� inicial del sprite.
    mSprite.setScale(150.f / bounds.width, 150.f / bounds.height);  // Escalo el sprite per ajustar-lo.

    mLastPosition = mSprite.getPosition();  // Guardar la posici� inicial.
}

// Definio el m�tode handleInput per gestionar l'entrada del teclat.
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

// Definio el m�tode update per actualitzar l'estat del jugador.
void Player::update(sf::Time deltaTime)
{
    mLastPosition = mSprite.getPosition();  // Guardar la �ltima posici�

    sf::Vector2f movement(0.f, 0.f); // Declaro un vector de moviment inicialitzat a zero.
    // Actualitzo el vector de moviment en funci� de les tecles premudes.
    if (mIsMovingUp) movement.y -= PlayerSpeed;
    if (mIsMovingDown) movement.y += PlayerSpeed;
    if (mIsMovingLeft) movement.x -= PlayerSpeed;
    if (mIsMovingRight) movement.x += PlayerSpeed;

    // Movo el jugador en funci� del moviment calculat i el temps transcorregut.
    mSprite.move(movement * deltaTime.asSeconds());
}

// Definio el m�tode draw per dibuixar el jugador a la finestra.
void Player::draw(sf::RenderWindow& window)
{
    window.draw(mSprite); // Dibuixo el sprite del jugador a la finestra.
}

// Definio el m�tode getBounds per obtenir els l�mits del jugador.
sf::FloatRect Player::getBounds() const
{
    return mSprite.getGlobalBounds(); // Retorno els l�mits globals del sprite.
}

// Definio el m�tode revertMovement per revertir el moviment en cas de col�lisi�.
void Player::revertMovement()
{
    mSprite.setPosition(mLastPosition);  // Revertir a la �ltima posici� enregistrada.
}

// Definio el m�tode getPosition per obtenir la posici� actual del jugador.
sf::Vector2f Player::getPosition() const
{
    return mSprite.getPosition(); // Retorno la posici� actual del jugador.
}
