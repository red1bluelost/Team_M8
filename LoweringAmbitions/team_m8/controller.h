/* File:   controller.h
 * Author: Micah Weston
 * Info:   Creates parent class for the different controllers
 */

#ifndef __CONTROLLERS_H__
#define __CONTROLLERS_H__


#include "game_protocol.h"
#include "communicator.h"

class controller {
  //privatize default constructor to prevent use
  controller();
  
  //available to the derived controllers
  protected:
  const CompID CID;
  Communicator Port;

  controller(CompID cid) : CID(cid) , Port(cid) {} //the way Port is initialized might not work!!!!
};

#endif
