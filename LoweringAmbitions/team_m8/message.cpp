/* File:   message.cpp
   Author: Micah Weston
   Info:   Implements message class
*/

#include "message.h"

void Message::Clear() {
  sender = CompID::NULL_ID;
  receiver = CompID::NULL_ID;
  msg = Protocol::NULL_PTC;
  din = DeviceInput::NULL_DIN;
}

bool Message::IsEmpty() {
  return sender == CompID::NULL_ID;
}

void Message::SetMsg(CompID s, CompID r, Protocol m, DeviceInput d = DeviceInput::NULL_DIN) {
  sender = s;
  receiver = r;
  msg = m;
  din = d;
}
