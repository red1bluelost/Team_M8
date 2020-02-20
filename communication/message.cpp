/* File:   message.cpp
 * Author: Micah Weston
 * Info:   Implements message class
 */

#include "message.h"
#include "game_protocol.h"

void Message::Clear() {
	sender = CompID::NULL_ID;
	receiver = CompID::NULL_ID;
	msg = Protocol::NULL_PTC;
}

bool Message::IsEmpty() {
	return sender == CompID::NULL_ID;
}

void Message::SetMsg(CompID s, CompID r, Protocol m) {
	sender = s;
	receiver = r;
	msg = m;
}
