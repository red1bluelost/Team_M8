/* File:   message.h
 * Author: Micah Weston
 * Info:   Holds class for message class
 */

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "Arduino.h"
#include "../debug/debug.h"

#include "game_protocol.h"

class Message {
	//message elements
	//sender [using id type]
	game::CompID senderID;
	//msg
	game::Protocol msg;
	//receiver (MAYBE)

	public:
	//constructor
	Message() : sender(game::EMPTY), msg(game::EMPTY) {};

	
}


#endif
