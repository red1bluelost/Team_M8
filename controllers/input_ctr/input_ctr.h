/* File:   input_ctr.h
 * Author: Micah Weston
 * Info:   Holds class for the input controller
 */

#ifndef __INPUT_CTR_H__
#define __INPUT_CTR_H__

#include "Arduino.h"
#include "../controller.h"

#include "../../communication/game_protocol.h"
#include "../../communication/message.h"

class InputCtr : private controller {
	short int pinb1, pinb2, pinb3, pinb4, pinb5, pinb6, pinen;

	void getNumberedInput(Message);
	void getYesNo(Message);

	public:
	InputCtr() : controller(CompID::INPUT_CTR) {}
	Setup(short int, short int, short int, short int, short int, short int, short int);
	Tick();

};

#endif