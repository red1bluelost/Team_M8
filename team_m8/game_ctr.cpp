/* File:   game_ctr.cpp
   Author: Micah Weston
   Info:   Implements class for the game controller
*/

#include "game_ctr.h"

bool GameCtr::checkPlayerEnd() {
  bool rsp = (curPlayer == player_count);
  if (rsp) {
    curPlayer = 0;
  }
  return rsp;
}

void GameCtr::resetGame(Message) {
  curPlayer = 0;
  this->Port.Send(CompID::MOTOR_CTR, Protocol::ZERO_XY, DeviceInput::NULL_DIN);
  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_COUNT, DeviceInput::NULL_DIN);
}

void GameCtr::declarePlayerCount(Message rsp) {
  int plCnt = (int) rsp.SeeDin();
  for (int i = 0; i < plCnt; ++i) {
    players[i].Reset();
  }
  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_STATE);

}

void GameCtr::StartGame() {
  this->Port.Send(CompID::GAME_CTR, Protocol::RESET_GAME);
}








void GameCtr::Tick() {
  if (!Port.Peek()) {
    return;
  }

  Message req = Port.Retrieve();
  switch (req.SeeReq()) {
    case Protocol::PROCESS_PLAYER_COUNT: //need to set up protocols
      this->declarePlayerCount(req);
      return;
    case Protocol::RESET_GAME:
      this->resetGame(req);
      return;

  }


}
