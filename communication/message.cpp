/* File:   message.cpp
 * Author: Micah Weston
 * Info:   Implements message class
 */

#include "message.h"
#include "game_protocol.h"

void Message::Clear() {
	sender = Game::CompID::NULL_ID;
	msg = Game::Protocol::NULL_PTC;
}

bool Message::IsEmpty() {
	return sender == Game::CompID::NULL_ID;
}
