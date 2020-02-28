/* File:   game_protocol.h
   Author: Micah Weston
   Info:   Enumerates game command protocols
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
  RESET_GAME,
  ZERO_XY,
  GET_PLAYER_COUNT,
  PROCESS_PLAYER_COUNT,
  GET_PLAYER_STATE,
  PROCESS_PLAYER_STATE,
  GET_ROLL,
  PROCESS_ROLL,
};

enum DeviceInput {
  NULL_DIN,
  BUT1,
  BUT2,
  BUT3,
  BUT4,
  BUT5,
  BUT6,
  YES,
  NO,
};

#endif
