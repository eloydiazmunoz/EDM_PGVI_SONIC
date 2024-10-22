// Definicio un bloqueig d'inclusi� per evitar que aquest fitxer s'inclogui m�s d'una vegada.
#ifndef GAME_H
#define GAME_H

// Incloc la llibreria gr�fica de SFML per gestionar gr�fics i finestres.
#include <SFML/Graphics.hpp>
// Incloc el fitxer d'encap�alament "Player.h" per tenir acc�s a la classe Player.
#include "Player.h"
// Incloc el fitxer d'encap�alament "Enemy.h" per tenir acc�s a la classe Enemy.
#include "Enemy.h"

// Definio la classe Game, que gestionar� la l�gica del joc.
class Game
{
public:
    // Declaro el constructor de la classe Game.
    Game();

    // Declaro el m�tode run que inicia el joc.
    void run();

private:
    // Declaro m�todes privats per processar esdeveniments, actualitzar l'estat i renderitzar gr�fics.
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    // Declaro m�todes per comprovar les condicions de guany i p�rdua.
    void checkWinCondition();  // Verifica si el jugador ha guanyat
    void checkLoseCondition();  // Verifica si el jugador ha perdut

private:
    // Declaro la finestra on es dibuixaran els gr�fics del joc.
    sf::RenderWindow mWindow;

    // Declaro un objecte Player que representar� el jugador.
    Player mPlayer;

    // Declaro un array d'enemics amb una mida de 3.
    Enemy mEnemies[3]; // Array de enemigos

    // Declaro textures i sprites per al fons del joc.
    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;

    // Declaro barreres vermelles com a rectangles.
    sf::RectangleShape mBarrierTop;
    sf::RectangleShape mBarrierMiddle;
    sf::RectangleShape mBarrierBottom3;
    sf::RectangleShape mBarrierBottom4;
    sf::RectangleShape mBarrierTop2;
    sf::RectangleShape mBarrierBottom;
    sf::RectangleShape mBarrierBottom2;

    // Declaro la meta o el final del joc (ara en vertical).
    sf::RectangleShape mGoal; // Meta o Fin del Juego (ahora en vertical)

    // Declaro una font per al text de "Fi partida".
    sf::Font mFont;  // Fuente para el texto de "Fi partida"

    // Declaro textos per mostrar si el jugador ha guanyat o perdut.
    sf::Text mEndText;  // Texto que muestra "Has Perdut!"
    sf::Text mWinText;  // Texto que muestra "Has Guanyat!"

    // Declaro una constant per definir el temps per fotograma (60 FPS).
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    // Declaro booleans per controlar si el joc s'ha guanyat o perdut.
    bool mGameWon = false;  // Estado de si se ha ganado el juego
    bool mGameLost = false;  // Estado de si se ha perdido el juego
};

// Acabo el bloqueig d'inclusi� per garantir que aquest fitxer s'inclogui nom�s una vegada.
#endif // GAME_H
