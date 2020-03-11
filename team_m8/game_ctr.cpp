/* File:   game_ctr.cpp
 * Author: Micah Weston
 * Info:   Implements class for the game controller
 */

#include "game_ctr.h"

extern MovePtc MoveBuffer[256];

void clearMoveBuf() {
  for(auto & m : MoveBuffer) {
    m = MovePtc::END;
  }
}

//checks if current player is after end, if so resets to start
void GameCtr::nextPlayer() {
  ++curPlayer;
  bool atEnd = (curPlayer == player_count);
  if (atEnd) {
    curPlayer = 0;
  }
}

//sends out the commands to reset the board and start a new game
void GameCtr::resetGame(Message) {
  curPlayer = 0;
  Port.Send(CompID::MOTOR_CTR, Protocol::ZERO_XY, DeviceInput::NULL_DIN);
  Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_COUNT, DeviceInput::NULL_DIN);
}

//resets players in array based on how many are playing
void GameCtr::declarePlayerCount(Message rsp) {
  //check message
  int plCnt = (int) rsp.SeeDin();
  //reset players necessary
  for (int i = 0; i < plCnt; ++i) {
    players[i].Reset();
    players[i].MoveYPosn(i);
  }
  //send request for player states (game- vs self-controlled)
  Port.Send(CompID::INPUT_CTR, Protocol::GET_PLAYER_STATE);

}

//processes the role and moves the player
void GameCtr::movePlayer(Message rsp) {
  clearMoveBuf();
  int roll = rsp.SeeDin();

  //compute move commands
  int mbi = 0; //move buffer iterator

  posn locBegin = players[curPlayer].GetPosn();
  int tileBegin = players[curPlayer].GetTile();

  //incase of start of game (first roll)
  if (tileBegin == 0) {
    MoveBuffer[mbi++] = MovePtc::R090;
    MoveBuffer[mbi++] = MovePtc::R090;
    MoveBuffer[mbi++] = MovePtc::R000;
    MoveBuffer[mbi++] = MovePtc::R000;
    --roll;
  }

  int tileEnd = tileBegin + roll;
  gameTile EndGameTile = CAL_Tiles[tileEnd];
  posn locEnd = EndGameTile.Position;

  int yDiff = locEnd.y - locBegin.y;
  int xDiff = locEnd.x - locBegin.x;
  bool direction = (tileBegin / 10) % 2; //false = right, true = left




}

//Called in setup to send reset request and start game
void GameCtr::StartGame() {
  Port.Send(CompID::GAME_CTR, Protocol::RESET_GAME);
}







//checks port, execute msg if one is there
void GameCtr::Tick() {
  if (!Port.Peek()) {return;}

  Message req = Port.Retrieve();
  switch (req.SeeReq()) {
    case Protocol::PROCESS_ROLL:
      movePlayer(req);
      return;
    case Protocol::PROCESS_PLAYER_COUNT: //need to set up protocols
      declarePlayerCount(req);
      return;
    case Protocol::RESET_GAME:
      resetGame(req);
      return;

  }


}
