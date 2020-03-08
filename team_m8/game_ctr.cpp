/* File:   game_ctr.cpp
 * Author: Micah Weston
 * Info:   Implements class for the game controller
 */

#include "game_ctr.h"

//checks if current player is after end, if so resets to start
bool GameCtr::checkPlayerEnd() {
  bool rsp = (curPlayer == player_count);
  if (rsp) {
    curPlayer = 0;
  }
  return rsp;
}

//sends out the commands to reset the board and start a new game
void GameCtr::resetGame(Message) {
  curPlayer = 0;
  this->Port.Send(CompID::MOTOR_CTR, Protocol::ZERO_XY, DeviceInput::NULL_DIN);
  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_COUNT, DeviceInput::NULL_DIN);
}

//resets players in array based on how many are playing
void GameCtr::declarePlayerCount(Message rsp) {
  //check message
  int plCnt = (int) rsp.SeeDin();
  //reset players necessary
  for (int i = 0; i < plCnt; ++i) {
    players[i].Reset();
  }
  //send request for player states (game- vs self-controlled)
  this->Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_STATE);

}

//Called in setup to send reset request and start game
void GameCtr::StartGame() {
  this->Port.Send(CompID::GAME_CTR, Protocol::RESET_GAME);
}







//checks port, execute msg if one is there
void GameCtr::Tick() {
  if (!Port.Peek()) {return;}

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
