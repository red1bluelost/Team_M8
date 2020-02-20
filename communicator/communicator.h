/* File:   communicator.h
 * Author: Micah Weston
 * Info:   Holds class for the communication object between component
 */

#ifndef __COMMUNICATOR_H__
#define __COMMUNICATOR_H__

#include "Arduino.h"
#include "../debug/debug.h"

class Communicator {
	//message buffers for each component
	message motorBuffer;
	message gameController;
	message userInputBuffer; //this might not be necessary
	
	/*Enumerate ids for each component so the call there the right buffer*/

	/*need functions:
	 * Send(message msg)
	 * Retrieve(id id)
	 * Peek(id id)
	 */

}


#endif
