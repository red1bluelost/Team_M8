/* File:   communicator.h
 * Author: Micah Weston
 * Info:   Holds class for the communication object between component
 */

#ifndef __COMMUNICATOR_H__
#define __COMMUNICATOR_H__

#include "game_protocol.h"

class Communicator {
	//current component id
	CompID CID;

	//message buffers for each component
	static message motorBuffer;
	static message gameController;
	static message userInputBuffer; //this might not be necessary
	

	Public:
	/*need functions:
	 * Send(message msg)
	 * message Retrieve()
	 * Peek()
	 */
	void Send(Protocol msg);

};


#endif
