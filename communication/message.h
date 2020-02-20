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
	CompID sender = NULL_ID;
	//msg
	Protocol msg = NULL_PTC;
	//receiver (MAYBE)

	public:
	//constructor
	Message(CompID s = NULL_ID, Protocol m = NULL_PTC) : sender(s), msg(m) {};

	//clear the message
	void Clear();
	//checks if empty
	bool IsEmpty();
	//set message (sender, message)
	void SetMsg(CompID s, Protocol m);
};


#endif
