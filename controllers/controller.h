/* File:   controller.h
 * Author: Micah Weston
 * Info:   Creates parent class for the different controllers
 */

#ifndef __CONTROLLERS_H__
#define __CONTROLLERS_H__


#include "../communication/game_protocol.h"

class controller {
	//privatize default constructor to prevent use
	controller();
	
	//available to the derived controllers
	protected:
	const CompID CID;
	controller(CompID cid) : CID(cid);
}

#endif
