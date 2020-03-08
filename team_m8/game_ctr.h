/* File:   game_ctr.h
 * Author: Micah Weston
 * Info:   Holds class for the game controller
 */

#ifndef __GAME_CTR_H__
#define __GAME_CTR_H__

#include "chutes_and_ladders.h"

#include "controller.h"

#include "game_protocol.h"
#include "communicator.h"
#include "message.h"

class GameCtr : private controller {
    short int player_count;
    Player players[3];
    short int curPlayer;
    
    //checks if current player is after end, if so resets to start
    bool checkPlayerEnd();

    //sends out the commands to reset the board and start a new game
    void resetGame(Message);
    //resets players in array based on how many are playing
    void declarePlayerCount(Message);
    void movePlayer();

  public:
    GameCtr() : controller(CompID::GAME_CTR) {};
    //checks port, execute msg if one is there
    void Tick();
    //Called in setup to send reset request and start game
    void StartGame();
};

#endif
