/* File:   input_ctr.cpp
 * Author: Micah Weston
 * Info:   Implements input controller class
 */

#include "input_ctr.h"


InputCtr::Setup(short int pb1, short int pb2, short int pb3,
		short int pb4, short int pb5, short int pb6, short int enter) {
	pinb1 = pb1;
	pinb2 = pb2;
	pinb3 = pb3;
	pinb4 = pb4;
	pinb5 = pb5;
	pinb6 = pb6;
	pinen = enter;
	pinMode(pb1, INPUT_PULLUP);
	pinMode(pb2, INPUT_PULLUP);
	pinMode(pb3, INPUT_PULLUP);
	pinMode(pb4, INPUT_PULLUP);
	pinMode(pb5, INPUT_PULLUP);
	pinMode(pb6, INPUT_PULLUP);
	pinMode(enter, INPUT_PULLUP);
}

InputCtr::Tick() {
	if (!Port.Peek()) { return }
	

	Message req = Port.Retrieve();
	switch(req.SeeReq()) {
		case Protocol:://need to set up protocols 

	}
}
