#include "Player.h"
#include "TextureHolder.h"

const float Player::PlayerSpeed = 400.f; // Ajustar velocidad del jugador

Player::Player()
    : mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
{
    mSprite.setTexture(TextureHolder::GetInstance().GetTexture("E:/AluCiclesGS2/EDM/EDM 2n/PGVI/UF1/EDM_PGVI_SONIC/x64/Debug/Personatge.png"));

    // Ajustar el tamaño del sprite
    sf::FloatRect bounds = mSprite.getGlobalBounds();
    mSprite.setPosition(100.f, 300.f);
    mSprite.setScale(150.f / bounds.width, 150.f / bounds.height);  // Escalar el sprite

    mLastPosition = mSprite.getPosition();  // Posición inicial
}

void Player::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Player::update(sf::Time deltaTime)
{
    mLastPosition = mSprite.getPosition();  // Guardar la última posición

    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp) movement.y -= PlayerSpeed;
    if (mIsMovingDown) movement.y += PlayerSpeed;
    if (mIsMovingLeft) movement.x -= PlayerSpeed;
    if (mIsMovingRight) movement.x += PlayerSpeed;

    // Mover el jugador
    mSprite.move(movement * deltaTime.asSeconds());
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

sf::FloatRect Player::getBounds() const
{
    return mSprite.getGlobalBounds();
}

void Player::revertMovement()
{
    mSprite.setPosition(mLastPosition);  // Revertir a la última posición
}

sf::Vector2f Player::getPosition() const
{
    return mSprite.getPosition(); // Devolver la posición actual del jugador
}