#include "Game.h" // Incloc el fitxer d'encapçalament de la classe Game.
#include "TextureHolder.h" // Incloc el fitxer d'encapçalament de TextureHolder per gestionar textures.
#include <iostream> // Incloc la llibreria d'entrada/sortida per poder imprimir missatges a la consola.

// Constructor de la classe Game
Game::Game()
    : mWindow(sf::VideoMode::getDesktopMode(), "EDM_PGVI_SONIC", sf::Style::Fullscreen) // Inicialitzo la finestra del joc en mode pantalla completa
{
    // Utilitzo TextureHolder per carregar la textura de fons
    mBackgroundTexture = TextureHolder::GetInstance().GetTexture("E:/AluCiclesGS2/EDM/EDM 2n/PGVI/UF1/EDM_PGVI_SONIC/x64/Debug/Fons2.jpg");
    mBackgroundSprite.setTexture(mBackgroundTexture); // Estableixo la textura del sprite de fons

    // Configuro les barreres
    mBarrierTop.setSize(sf::Vector2f(100.f, 800.f)); // Estableixo la mida de la barrera superior
    mBarrierTop.setFillColor(sf::Color::Magenta); // Estableixo el color de la barrera superior a magenta
    mBarrierTop.setPosition(1000.f, 0.f); // Estableixo la posició de la barrera superior

    mBarrierTop2.setSize(sf::Vector2f(100.f, 800.f)); // Estableixo la mida de la segona barrera superior
    mBarrierTop2.setFillColor(sf::Color::White); // Estableixo el color de la segona barrera superior a blanc
    mBarrierTop2.setPosition(1600.f, 0.f); // Estableixo la posició de la segona barrera superior

    mBarrierMiddle.setSize(sf::Vector2f(100.f, 700.f)); // Estableixo la mida de la barrera mitjana
    mBarrierMiddle.setFillColor(sf::Color::Red); // Estableixo el color de la barrera mitjana a vermell
    mBarrierMiddle.setPosition(250.f, -50.f); // Estableixo la posició de la barrera mitjana

    mBarrierBottom.setSize(sf::Vector2f(100.f, 1050.f)); // Estableixo la mida de la barrera inferior
    mBarrierBottom.setFillColor(sf::Color::Cyan); // Estableixo el color de la barrera inferior a cian
    mBarrierBottom.setPosition(1300.f, mWindow.getSize().y - 750.f); // Estableixo la posició de la barrera inferior

    mBarrierBottom2.setSize(sf::Vector2f(100.f, 1050.f)); // Estableixo la mida de la segona barrera inferior
    mBarrierBottom2.setFillColor(sf::Color::Green); // Estableixo el color de la segona barrera inferior a verd
    mBarrierBottom2.setPosition(600.f, mWindow.getSize().y - 750.f); // Estableixo la posició de la segona barrera inferior

    mBarrierBottom4.setSize(sf::Vector2f(100.f, 1050.f)); // Estableixo la mida de la quarta barrera inferior
    mBarrierBottom4.setFillColor(sf::Color::Blue); // Estableixo el color de la quarta barrera inferior a blau
    mBarrierBottom4.setPosition(1900.f, mWindow.getSize().y - 750.f); // Estableixo la posició de la quarta barrera inferior

    mBarrierBottom3.setSize(sf::Vector2f(100.f, 1050.f)); // Estableixo la mida de la tercera barrera inferior
    mBarrierBottom3.setFillColor(sf::Color::White); // Estableixo el color de la tercera barrera inferior a blanc
    mBarrierBottom3.setPosition(600.f, mWindow.getSize().y - 750.f); // Estableixo la posició de la tercera barrera inferior

    // Configuro la meta
    mGoal.setSize(sf::Vector2f(50.f, mWindow.getSize().y)); // Estableixo la mida de la meta
    mGoal.setFillColor(sf::Color::Cyan); // Estableixo el color de la meta a cian
    mGoal.setPosition(mWindow.getSize().x - 100.f, 0.f); // Estableixo la posició de la meta

    // Configuro el text per a "Has Perdut!"
    if (!mFont.loadFromFile("Blox2.ttf")) { // Carrego la font i controlo si hi ha errors
        std::cerr << "Error al cargar la fuente." << std::endl; // Imprimo un missatge d'error si no es pot carregar la font
    }

    mEndText.setFont(mFont); // Estableixo la font del text
    mEndText.setCharacterSize(200); // Estableixo la mida del text
    mEndText.setFillColor(sf::Color::Red); // Estableixo el color del text a vermell
    mEndText.setString("Has Perdut"); // Estableixo el contingut del text

    // Centro el text de "Has Perdut"
    sf::FloatRect textBounds = mEndText.getLocalBounds(); // Obtenim els límits del text
    mEndText.setOrigin(textBounds.width / 2, textBounds.height / 2); // Estableixo l'origen del text al centre
    mEndText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2); // Estableixo la posició del text al centre de la finestra

    // Configuro el text per a "Has Guanyat!"
    mWinText.setFont(mFont); // Estableixo la font del text de victòria
    mWinText.setCharacterSize(200); // Estableixo la mida del text de victòria
    mWinText.setFillColor(sf::Color::Green); // Estableixo el color del text de victòria a verd
    mWinText.setString("Has Guanyat"); // Estableixo el contingut del text de victòria

    // Centro el text de "Has Guanyat"
    sf::FloatRect winTextBounds = mWinText.getLocalBounds(); // Obtenim els límits del text de victòria
    mWinText.setOrigin(winTextBounds.width / 2, winTextBounds.height / 2); // Estableixo l'origen del text de victòria al centre
    mWinText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2); // Estableixo la posició del text de victòria al centre de la finestra

    // Inicialitzo els enemics
    for (int i = 0; i < 3; ++i) { // Itero per inicialitzar els tres enemics
        mEnemies[i].setPosition(200.f * (i + 1), 100.f); // Estableixo les posicions inicials dels enemics
    }
}

// Mètode per executar el joc
void Game::run()
{
    sf::Clock clock; // Inicialitzo un rellotge per gestionar el temps
    sf::Time timeSinceLastUpdate = sf::Time::Zero; // Inicialitzo el temps des de l'última actualització

    while (mWindow.isOpen()) // Executar mentre la finestra estigui oberta
    {
        sf::Time deltaTime = clock.restart(); // Reiniciem el rellotge i obtenim el temps transcorregut
        timeSinceLastUpdate += deltaTime; // Afegim el temps transcorregut

        while (timeSinceLastUpdate > TimePerFrame) // Si ha passat més temps del permès entre fotogrames
        {
            timeSinceLastUpdate -= TimePerFrame; // Reduïm el temps transcorregut
            processEvents(); // Processar esdeveniments
            update(TimePerFrame); // Actualitzar l'estat del joc
        }

        render(); // Renderitzar els gràfics
    }
}

// Mètode per processar esdeveniments de la finestra
void Game::processEvents()
{
    sf::Event event; // Declaro un esdeveniment per gestionar esdeveniments de la finestra
    while (mWindow.pollEvent(event)) // Comprovo si hi ha esdeveniments
    {
        switch (event.type) // Comprovo el tipus d'esdeveniment
        {
        case sf::Event::KeyPressed: // Si es prem una tecla
            if (event.key.code == sf::Keyboard::Escape) // Si la tecla és Escape
            {
                mWindow.close(); // Tanco la finestra
            }
            mPlayer.handleInput(event.key.code, true); // Gestiono l'entrada del jugador
            break;
        case sf::Event::KeyReleased: // Si es deixa de prem una tecla
            mPlayer.handleInput(event.key.code, false); // Gestiono l'entrada del jugador
            break;
        case sf::Event::Closed: // Si es tanca la finestra
            mWindow.close(); // Tanco la finestra
            break;
        }
    }
}

// Mètode per actualitzar l'estat del joc
void Game::update(sf::Time deltaTime)
{
    if (mGameWon || mGameLost)  // Si el joc ja ha acabat, no actualitzo més
        return;

    mPlayer.update(deltaTime); // Actualitzo l'estat del jugador

    // Actualitzar enemics i verificar col·lisions
    for (int i = 0; i < 3; ++i) {
        mEnemies[i].update(deltaTime, mPlayer.getPosition()); // Actualitzo els enemics perquè persegueixin al jugador
    }

    // Comprovar col·lisions amb barreres
    sf::FloatRect playerBounds = mPlayer.getBounds(); // Obtenim els límits del jugador
    if (playerBounds.intersects(mBarrierTop.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierMiddle.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom2.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom4.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierTop2.getGlobalBounds()) ||
        playerBounds.intersects(mBarrierBottom3.getGlobalBounds())) // Si el jugador col·lisiona amb alguna barrera
    {
        mPlayer.revertMovement();  // Reverteixo el moviment si col·lisiona
    }

    // Verificar col·lisions amb enemics
    for (int i = 0; i < 3; ++i) {
        if (playerBounds.intersects(mEnemies[i].getBounds())) { // Si el jugador col·lisiona amb un enemic
            mGameLost = true;  // El jugador ha perdut
        }
    }

    // Evitar que el jugador surti dels límits de la pantalla
    if (playerBounds.left < 0.f || playerBounds.left + playerBounds.width > mWindow.getSize().x ||
        playerBounds.top < 0.f || playerBounds.top + playerBounds.height > mWindow.getSize().y) // Si el jugador està fora dels límits
    {
        mPlayer.revertMovement();  // Reverteixo el moviment si surt del mapa
    }

    // Comprovar si el jugador ha arribat a la meta
    checkWinCondition();
}

// Mètode per verificar les condicions de guany
void Game::checkWinCondition()
{
    if (mPlayer.getBounds().intersects(mGoal.getGlobalBounds())) { // Si el jugador col·lisiona amb la meta
        mGameWon = true;  // El jugador ha guanyat
        std::cout << "Fi del Joc, Has guanyat!" << std::endl;  // Imprimir "Fi partida" a la consola
    }
}

// Mètode per renderitzar els gràfics
void Game::render()
{
    mWindow.clear(); // Esborro la finestra
    mWindow.draw(mBackgroundSprite); // Dibuixo el fons
    mPlayer.draw(mWindow); // Dibuixo el jugador
    for (int i = 0; i < 3; ++i) {
        mEnemies[i].draw(mWindow); // Dibuixo els enemics
    }
    mWindow.draw(mBarrierTop); // Dibuixo la barrera superior
    mWindow.draw(mBarrierMiddle); // Dibuixo la barrera mitjana
    mWindow.draw(mBarrierBottom3); // Dibuixo la tercera barrera inferior
    mWindow.draw(mBarrierBottom); // Dibuixo la barrera inferior
    mWindow.draw(mBarrierBottom2); // Dibuixo la segona barrera inferior
    mWindow.draw(mBarrierBottom4); // Dibuixo la quarta barrera inferior 
    mWindow.draw(mBarrierTop2); // Dibuixo la segona barrera superior
    mWindow.draw(mGoal); // Dibuixo la meta

    if (mGameLost) {
        mWindow.draw(mEndText); // Dibuixo el text de "Has Perdut!" si el jugador ha perdut
    }

    if (mGameWon) {
        mWindow.draw(mWinText); // Dibuixo el text de "Has Guanyat!" si el jugador ha guanyat
    }

    mWindow.display(); // Mostro el contingut de la finestra
}
