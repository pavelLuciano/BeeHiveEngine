#ifndef _GAME_MASTER_H_
#define _GAME_MASTER_H_

#include <Pieces.h>
#include <memory>

typedef bool PlayerColor;
#define WHITE_PLAYER true
#define BLACK_PLAYER false

#define N_ABEJAS 1
#define N_HORMIGAS 3
#define N_SALTAMONTES 3
#define N_ARANAS 2
#define N_ESCARABAJOS 2
//DLC
#define N_CHINITAS 0
#define N_ZANCUDOS 0
#define N_CHANCHITOS 0

#define N_PIEZAS (N_ABEJAS + N_HORMIGAS + N_SALTAMONTES + N_ARANAS + N_ESCARABAJOS + N_CHINITAS + N_ZANCUDOS + N_CHANCHITOS)

struct Player
{
    PlayerColor color;
    std::shared_ptr<Piece> bag[N_PIEZAS];
    bool hasPlayedThisCurrentTurn;
};

class GameMaster: Entity
{
public:
    Player* currentPlayer;
    Player whitePlayer;
    Player blackPlayer;
    int currentTurn;
    std::vector<Piece> Board;

    GameMaster();
    ~GameMaster();
    void startGame();
    void endGame();

    //override//
    void update() override;

private:
    void setupGame();
    void changeTurn();
};
#endif