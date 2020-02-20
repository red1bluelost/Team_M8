/* File:   message.h
 * Author: Micah Weston
 * Info:   Holds message class
 */

#ifndef __MESSAGE_H__
#define __MESSAGE_H__


#include "game_protocol.h"

class Message {
	//message elements
	CompID sender = NULL_ID;
	CompID receiver = NULL_ID;
	Protocol msg = NULL_PTC;

	public:
	//constructor
	Message(CompID s = NULL_ID, CompID r = NULL_ID, Protocol m = NULL_PTC) : sender(s), receiver(r), msg(m) {};

	//clear the message
	void Clear();
	//checks if empty
	bool IsEmpty();
	//set message (sender, message)
	void SetMsg(CompID s, CompID r, Protocol m);
};


#endif
