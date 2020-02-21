/* File:   game_ctr.h
 * Author: Micah Weston
 * Info:   Holds class for the game controller
 */

#ifndef __GAME_CTR_H__
#define __GAME_CTR_H__

#include "../controller.h"

#include "../../communication/game_protocol.h"
#include "../../communication/message.h"

class GameCtr : private controller {
	//needs vector of players
	//needs iterator to the current player

	public:
	GameCtr() : controller(CompID::GAME_CTR);

}
