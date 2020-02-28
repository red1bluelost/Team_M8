/* File:   game_ctr.h
   Author: Micah Weston
   Info:   Holds class for the game controller
*/

#ifndef __GAME_CTR_H__
#define __GAME_CTR_H__

#include "chutes_and_ladders.h"

#include "controller.h"

#include "game_protocol.h"
#include "communicator.h"
#include "message.h"

class GameCtr : private controller {
    bool checkPlayerEnd();

    void resetGame(Message);
    void declarePlayerCount(Message);

  public:
    GameCtr() : controller(CompID::GAME_CTR) {};
    void Tick();
};

#endif
