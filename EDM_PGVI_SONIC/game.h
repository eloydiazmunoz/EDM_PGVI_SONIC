#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void checkWinCondition();  // Verifica si el jugador ha ganado
    void checkLoseCondition();  // Verifica si el jugador ha perdido

private:
    sf::RenderWindow mWindow;
    Player mPlayer;
    Enemy mEnemies[3]; // Array de enemigos

    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;

    // Barreras rojas
    sf::RectangleShape mBarrierTop;
    sf::RectangleShape mBarrierMiddle;
    sf::RectangleShape mBarrierBottom3;
    sf::RectangleShape mBarrierBottom4;    
    sf::RectangleShape mBarrierTop2;
    sf::RectangleShape mBarrierBottom;
    sf::RectangleShape mBarrierBottom2;

    sf::RectangleShape mGoal; // Meta o Fin del Juego (ahora en vertical)

    sf::Font mFont;  // Fuente para el texto de "Fi partida"
    sf::Text mEndText;  // Texto que muestra "Has Perdut!"
    sf::Text mWinText;  // Texto que muestra "Has Guanyat!"

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    bool mGameWon = false;  // Estado de si se ha ganado el juego
    bool mGameLost = false;  // Estado de si se ha perdido el juego
};

#endif // GAME_H
