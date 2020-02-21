/* File:   communicator.h
 * Author: Micah Weston
 * Info:   Holds class for the communication object between component
 */

#ifndef __COMMUNICATOR_H__
#define __COMMUNICATOR_H__

#include "game_protocol.h"
#include "message.h"

class Communicator {
	//current component id
	const CompID CID;

	//message buffers for each component
	static Message gameController;
	static Message motorBuffer;
	static Message inputBuffer; //this might not be necessary
	//this might not be able to properly send msgs
	//when input is need store the component that asked and that use that
	//for the receiver of the message
	

	Public:
	void Send(CompID r, Protocol msg);
	Message Retrieve();
	bool Peek();
};


#endif
