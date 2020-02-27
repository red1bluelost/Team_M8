/* File:   game_ctr.h
 * Author: Micah Weston
 * Info:   Holds class for the game controller
 */

#ifndef __GAME_CTR_H__
#define __GAME_CTR_H__

#include <vector>
#include <memory>
#include <iterator>

#include "chutes_and_ladders.h"

#include "../controller.h"

#include "../../communication/game_protocol.h"
#include "../../communication/communicator.h"
#include "../../communication/message.h"

class GameCtr : private controller {
	typedef std::vector<std::shared_ptr<Player>> ptrPlayerVector;

	//needs vector of players
	//needs iterator to the current player
	ptrPlayerVector           players;
	ptrPlayerVector::iterator curPlayer; 

	bool checkPlayerEnd();

	void resetGame(Message);
	void declarePlayerCount(Message);

	public:
	GameCtr() : controller(CompID::GAME_CTR);
	void Tick();
}

#endif
