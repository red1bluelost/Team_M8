/* File:   game_protocol.h
 * Author: Micah Weston
 * Info:   Enumerates game command protocols
 */

#ifndef __GAME_PROTOCOL_H__
#define __GAME_PROTOCOL_H__

//Identification for each component
enum CompID {
	NULL_ID,
	GAME_CTR,
	MOTOR_CTR,
	INPUT_CTR,
};

//Protocol codes for send communication between components
enum Protocol {
	NULL_PTC,
	BUTTON1,
	BUTTON2,
	GET_ROLL,
	PROCESS_ROLL,
};

enum DeviceInput {
	NULL_DIN,
	B1,
	B2,
	B3,
	B4,
	B5,
	B6,
};

#endif
