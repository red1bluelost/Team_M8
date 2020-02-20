/* File:   communicator.h
 * Author: Micah Weston
 * Info:   Holds class for the communication object between component
 */

#ifndef __COMMUNICATOR_H__
#define __COMMUNICATOR_H__


class Communicator {
	//enumerate component ids (place this into its own file)
	

	//current component id

	//message buffers for each component
	static message motorBuffer;
	static message gameController;
	static message userInputBuffer; //this might not be necessary
	
	/*Enumerate ids for each component so the call there the right buffer*/

	/*need functions:
	 * Send(message msg)
	 * message Retrieve()
	 * Peek()
	 */

};


#endif
