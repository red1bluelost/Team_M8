/* File:   message.h
 * Author: Micah Weston
 * Info:   Holds message class
 */

#ifndef __MESSAGE_H__
#define __MESSAGE_H__


#include "game_protocol.h"

class Message {
	//message elements
	//sender [using id type]
	Game::CompID sender = Game::NULL_ID;
	//msg
	Game::Protocol msg = Game::NULL_PTC;
	//receiver (MAYBE)

	public:
	//constructor
	Message(Game::CompID s = Game::NULL_ID, Game::Protocol m = Game::NULL_PTC) : sender(s), msg(m) {};

	//clear the message
	void Clear();
	//checks if empty
	bool IsEmpty();
	//set message (sender, message)
	void SetMsg(Game::CompID s, Game::Protocol m);
};


#endif
