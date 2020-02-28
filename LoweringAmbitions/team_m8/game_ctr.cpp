/* File:   game_ctr.cpp
   Author: Micah Weston
   Info:   Implements class for the game controller
*/

#include "game_ctr.h"

bool GameCtr::checkPlayerEnd() {
//  bool rsp = curPlayer == players.end();
//  if (rsp) {
//    curPlayer = players.begin();
//  }
//  return rsp;
}

void GameCtr::resetGame(Message) {
//  players.clear();
  this->Port.Send(CompID::MOTOR_CTR, Protocol::ZERO_XY, DeviceInput::NULL_DIN);
  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_COUNT, DeviceInput::NULL_DIN);
}

void declarePlayerCount(Message rsp) {
//  int plCnt = rsp.SeeDin;
//  for (int i = 0; i < plCnt; ++i) {
//    auto sp = std::make_shared<Player>;
//    players.push_back(sp);
//  }
//  curPlayer = players.begin();
//  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_STATE);

}










void GameCtr::Tick() {
  if (!Port.Peek()) {
    return;
  }

  Message req = Port.Retrieve();
  switch (req.SeeReq()) {
    case Protocol::PROCESS_PLAYER_COUNT: //need to set up protocols
      //this->declarePlayerCount(req);
      return;
    case Protocol::RESET_GAME:
      this->resetGame(req);
      return;

  }


}
