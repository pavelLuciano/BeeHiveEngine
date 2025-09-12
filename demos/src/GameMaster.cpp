#include <GameMaster.h>
#include <BeeHiveEngine.h>

GameMaster::GameMaster()
{

}
GameMaster::~GameMaster()
{

}
void GameMaster::startGame()
{
    currentPlayer = &whitePlayer;
    whitePlayer.hasPlayedThisCurrentTurn = false;
    blackPlayer.hasPlayedThisCurrentTurn = false;
    setupGame();
}
void GameMaster::endGame()
{

}
void GameMaster::setupGame()
{
    Color negro  = {0.11f, 0.05f, 0.008f};
    Color blanco = {1.0f, 1.0f, 0.75f};
    short int i;
    short int acc;
    Shader* pieceShader = new Shader(DEFAULT_VERTEX_SHADER, PIECE_SHADER);
    for (i = acc = 0; i < N_ABEJAS; i++, acc++)
    {
        whitePlayer.bag[acc] = BeeHive::createEntity<Abeja>(blanco);
        blackPlayer.bag[acc] = BeeHive::createEntity<Abeja>(negro);
        whitePlayer.bag[acc]->transform->TranslateTo(glm::vec3(-4, i*0.5f, 5));
        blackPlayer.bag[acc]->transform->TranslateTo(glm::vec3(-4, i*0.5f, -5));
    }
    for (i = 0; i < N_HORMIGAS; i++, acc++)
    {
        whitePlayer.bag[acc] = BeeHive::createEntity<Hormiga>(blanco);
        blackPlayer.bag[acc] = BeeHive::createEntity<Hormiga>(negro);
        whitePlayer.bag[acc]->transform->TranslateTo(glm::vec3(-2, i*0.5f, 5));
        blackPlayer.bag[acc]->transform->TranslateTo(glm::vec3(-2, i*0.5f, -5));
    }
    for (i = 0; i < N_SALTAMONTES; i++, acc++)
    {
        whitePlayer.bag[acc] = BeeHive::createEntity<Saltamontes>(blanco);
        blackPlayer.bag[acc] = BeeHive::createEntity<Saltamontes>(negro);
        whitePlayer.bag[acc]->transform->TranslateTo(glm::vec3(0, i*0.5f, 5));
        blackPlayer.bag[acc]->transform->TranslateTo(glm::vec3(0, i*0.5f, -5));
    }
    for (i = 0; i < N_ARANAS; i++, acc++)
    {
        whitePlayer.bag[acc] = BeeHive::createEntity<Arana>(blanco);
        blackPlayer.bag[acc] = BeeHive::createEntity<Arana>(negro);
        whitePlayer.bag[acc]->transform->TranslateTo(glm::vec3(2, i*0.5f, 5));
        blackPlayer.bag[acc]->transform->TranslateTo(glm::vec3(2, i*0.5f, -5));
    }
    for (i = 0; i < N_ESCARABAJOS; i++, acc++)
    {
        whitePlayer.bag[acc] = BeeHive::createEntity<Escarabajo>(blanco);
        blackPlayer.bag[acc] = BeeHive::createEntity<Escarabajo>(negro);
        whitePlayer.bag[acc]->transform->TranslateTo(glm::vec3(4, i*0.5f, 5));
        blackPlayer.bag[acc]->transform->TranslateTo(glm::vec3(4, i*0.5f, -5));
    }
    for (i = 0; i < N_PIEZAS; i++)
    {
        BeeHive::Graphic::bindShader(whitePlayer.bag[i], pieceShader);
        BeeHive::Graphic::bindShader(blackPlayer.bag[i], pieceShader);
    }
    
}
void GameMaster::changeTurn()
{
    if (currentPlayer == &whitePlayer) 
        currentPlayer = &blackPlayer;
    else currentPlayer = &whitePlayer;
    currentPlayer->hasPlayedThisCurrentTurn = false;
}
void GameMaster::update()
{
    if (currentPlayer->hasPlayedThisCurrentTurn) 
    {
        //changeTurn();
    }
}