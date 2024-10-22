#include <iostream> // Incloc la llibreria d'entrada/sortida per poder imprimir a la consola
#include <SFML/Window.hpp> // Incloc la llibreria de finestres de SFML per gestionar la finestra del joc
#include "game.h" // Incloc el fitxer d'encapçalament de la classe Game

int main() // Funció principal, punt d'entrada del programa
{
    Game joc; // Crec una instància de la classe Game
    joc.run(); // Crido el mètode run() per iniciar el joc

    return 0; // Retorno 0 per indicar que el programa ha acabat correctament
}
