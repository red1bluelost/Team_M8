/* File:   communicator.cpp
 * Author: Micah Weston
 * Info:   Implements communicator class
 */

#include "communicator.h"

void Communicator::Send(CompID r, Protocol msg, DeviceInput din = DeviceInput::NULL_DIN) {
	switch(r) {
		case CompID::GAME_CTR:
			gameBuffer.SetMsg(CID, r, msg, din);
			break;
		case CompID::MOTOR_CTR:
			motorBuffer.SetMsg(CID, r, msg, din);
			break;
		case CompID::INPUT_CTR:
			inputBuffer.SetMsg(CID, r, msg);
			break;
	}
}

Message Communicator::Retrieve() {
	Message m;
	switch(CID) {
		case CompID::GAME_CTR:
			m = gameBuffer;
			gameBuffer.clear();
			return m;
		case CompID::MOTOR_CTR:
			m = motorBuffer;
			motorBuffer.clear();
			return m;
		case CompID::INPUT_CTR:
			m = inputBuffer;
			inputBuffer.clear();
			return m;
	}
}

bool Communicator::Peek() {
	switch(CID) {
		case CompID::GAME_CTR:
			return !gameBuffer.IsEmpty();
		case CompID::MOTOR_CTR:
			return !motorBuffer.IsEmpty();
		case CompID::INPUT_CTR:
			return !inputBuffer.IsEmpty();
	}
}
