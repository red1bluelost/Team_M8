/* File:   message.cpp
 * Author: Micah Weston
 * Info:   Implements message class
 */

#include "message.h"

//clears the message reseting everything to null
void Message::Clear() {
  sender   = CompID::NULL_ID;
  receiver = CompID::NULL_ID;
  msg      = Protocol::NULL_PTC;
  din      = DeviceInput::NULL_DIN;
}

//checks if message is null
bool Message::IsEmpty() {
  return sender == CompID::NULL_ID;
}

//sets message based on arguments
void Message::SetMsg(CompID s, CompID r, Protocol m, DeviceInput d) {
  sender   = s;
  receiver = r;
  msg      = m;
  din      = d;
}

//Returns an empty message
Message EmptyMsg() {
  Message msg;
  return msg;
}
