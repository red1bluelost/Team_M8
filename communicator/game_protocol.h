/* File:   game_protocol.h
 * Author: Micah Weston
 * Info:   Enumerates game command protocols
 */

#ifndef __GAME_PROTOCOL_H__
#define __GAME_PROTOCOL_H__

namespace Game {
	//Identification for each component
	enum CompID {
		GAME_CTR,
		MOTOR_CTR,
		INPUT_CTR,
	}

	//Protocol codes for send communication between components
	enum Protocol {
		EMPTY,
		
	}


#endif
