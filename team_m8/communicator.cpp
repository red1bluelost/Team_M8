/* File:   communicator.cpp
 * Author: Micah Weston
 * Info:   Implements communicator class
 */

#include "communicator.h"

//sends the message to the specified component
void Communicator::Send(CompID r, Protocol msg, DeviceInput din) {
  switch (r) {
    case CompID::GAME_CTR:
      gameBuffer.SetMsg(CID, r, msg, din);
      break;
    case CompID::MOTOR_CTR:
      motorBuffer.SetMsg(CID, r, msg, din);
      break;
    case CompID::INPUT_CTR:
      inputBuffer.SetMsg(CID, r, msg, din);
      break;
  }
}

//retrieves the message from assigned port and clears the buffer
Message Communicator::Retrieve() {
  Message m;
  switch (CID) {
    case CompID::GAME_CTR:
      m = gameBuffer;
      gameBuffer.Clear();
      return m;
    case CompID::MOTOR_CTR:
      m = motorBuffer;
      motorBuffer.Clear();
      return m;
    case CompID::INPUT_CTR:
      m = inputBuffer;
      inputBuffer.Clear();
      return m;
  }
}

//checks if the port has a message in it
bool Communicator::Peek() {
  switch (CID) {
    case CompID::GAME_CTR:
      return !gameBuffer.IsEmpty();
    case CompID::MOTOR_CTR:
      return !motorBuffer.IsEmpty();
    case CompID::INPUT_CTR:
      return !inputBuffer.IsEmpty();
  }
}
