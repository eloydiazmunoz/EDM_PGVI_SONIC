#include "Game.h"
#include "TextureHolder.h"
#include <iostream>

// Constructor
Game::Game()
    : mWindow(sf::VideoMode::getDesktopMode(), "EDM_PGVI_SONIC", sf::Style::Fullscreen)
{
    // Usar TextureHolder para cargar la textura de fondo
    mBackgroundTexture = TextureHolder::GetInstance().GetTexture("E:/AluCiclesGS2/EDM/EDM 2n/PGVI/UF1/EDM_PGVI_SONIC/x64/Debug/Fons2.jpg");
    mBackgroundSprite.setTexture(mBackgroundTexture);

    // Barreras
    mBarrierTop.setSize(sf::Vector2f(100.f, 800.f));
    mBarrierTop.setFillColor(sf::Color::Magenta);
    mBarrierTop.setPosition(1000.f, 0.f);

    mBarrierTop2.setSize(sf::Vector2f(100.f, 800.f));
    mBarrierTop2.setFillColor(sf::Color::Green);
    mBarrierTop2.setPosition(1600.f, 0.f);

    mBarrierMiddle.setSize(sf::Vector2f(100.f, 700.f));
    mBarrierMiddle.setFillColor(sf::Color::Red);
    mBarrierMiddle.setPosition(250.f, -50.f);

    mBarrierBottom.setSize(sf::Vector2f(100.f, 1050.f));
    mBarrierBottom.setFillColor(sf::Color::Cyan);
    mBarrierBottom.setPosition(1300.f, mWindow.getSize().y - 750.f);

    mBarrierBottom2.setSize(sf::Vector2f(100.f, 1050.f));
    mBarrierBottom2.setFillColor(sf::Color::White);
    mBarrierBottom2.setPosition(600.f, mWindow.getSize().y - 750.f);


    mBarrierBottom4.setSize(sf::Vector2f(100.f, 1050.f));
    mBarrierBottom4.setFillColor(sf::Color::Blue);
    mBarrierBottom4.setPosition(1900.f, mWindow.getSize().y - 750.f);

    mBarrierBottom3.setSize(sf::Vector2f(100.f, 1050.f));
    mBarrierBottom3.setFillColor(sf::Color::White);
    mBarrierBottom3.setPosition(600.f, mWindow.getSize().y - 750.f);

    // Meta
    mGoal.setSize(sf::Vector2f(50.f, mWindow.getSize().y));
    mGoal.setFillColor(sf::Color::Cyan);
    mGoal.setPosition(mWindow.getSize().x - 100.f, 0.f);

    // Configuración de texto para "Has Perdut!"
    if (!mFont.loadFromFile("Blox2.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }

    mEndText.setFont(mFont);
    mEndText.setCharacterSize(200);
    mEndText.setFillColor(sf::Color::Red);
    mEndText.setString("Has Perdut");

    // Centrar el texto de "Has Perdut"
    sf::FloatRect textBounds = mEndText.getLocalBounds();
    mEndText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    mEndText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);

    // Configuración de texto para "Has Guanyat!"
    mWinText.setFont(mFont);
    mWinText.setCharacterSize(200);
    mWinText.setFillColor(sf::Color::Green);
    mWinText.setString("Has Guanyat");

    // Centrar el texto de "Has Guanyat"
    sf::FloatRect winTextBounds = mWinText.getLocalBounds();
    mWinText.setOrigin(winTextBounds.width / 2, winTextBounds.height / 2);
    mWinText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);

    // Inicializa enemigos
    for (int i = 0; i < 3; ++i) {
        mEnemies[i].setPosition(200.f * (i + 1), 100.f); // Posiciones iniciales de los enemigos
    }
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                mWindow.close();
            }
            mPlayer.handleInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            mPlayer.handleInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    if (mGameWon || mGameLost)  // Si el juego ya ha terminado, no actualizar más
        return;

    mPlayer.update(deltaTime);

    // Actualizar enemigos y verificar colisiones
    for (int i = 0; i < 3; ++i) {
        mEnemies[i].update(deltaTime, mPlayer.getPosition()); // Hacer que los enemigos persigan al jugador
    }

    // Colisiones con barreras
    sf::FloatRect playerBounds = mPlayer.getBounds();
    if (playerBounds.intersects(mBarrierTop.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierMiddle.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom4.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierTop2.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom3.getGlobalBounds()))
    {
        mPlayer.revertMovement();  // Revertir el movimiento si colisiona
    }

    // Verificar colisiones con enemigos
    for (int i = 0; i < 3; ++i) {
        if (playerBounds.intersects(mEnemies[i].getBounds())) {
            mGameLost = true;  // Se ha perdido el juego
        }
    }

    // Evitar que el jugador salga de los límites de la pantalla
    if (playerBounds.left < 0.f || playerBounds.left + playerBounds.width > mWindow.getSize().x ||
        playerBounds.top < 0.f || playerBounds.top + playerBounds.height > mWindow.getSize().y)
    {
        mPlayer.revertMovement();  // Revertir el movimiento si sale del mapa
    }

    // Verificar si el jugador ha alcanzado la meta
    checkWinCondition();
}

void Game::checkWinCondition()
{
    if (mPlayer.getBounds().intersects(mGoal.getGlobalBounds())) {
        mGameWon = true;  // El jugador ha ganado
        std::cout << "Fi del Joc, Has guanyat!" << std::endl;  // Imprimir "Fi partida" en la consola
    }
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mBackgroundSprite);
    mPlayer.draw(mWindow);
    for (int i = 0; i < 3; ++i) {
        mEnemies[i].draw(mWindow); // Dibujar enemigos
    }
    mWindow.draw(mBarrierTop);
    mWindow.draw(mBarrierMiddle);
    mWindow.draw(mBarrierBottom3);
    mWindow.draw(mBarrierBottom);
    mWindow.draw(mBarrierBottom2);
    mWindow.draw(mBarrierBottom4); 
    mWindow.draw(mBarrierTop2);
    mWindow.draw(mGoal); // Dibujar la meta

    if (mGameLost) {
        mWindow.draw(mEndText); // Dibujar el texto de "Has Perdut!"
    }

    if (mGameWon) {
        mWindow.draw(mWinText); // Dibujar el texto de "Has Guanyat!"
    }

    mWindow.display();
}
