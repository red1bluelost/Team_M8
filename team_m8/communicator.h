/* File:   communicator.h
 * Author: Micah Weston
 *  Info:   Holds class for the communication object between component
 */

#ifndef __COMMUNICATOR_H__
#define __COMMUNICATOR_H__

#include "game_protocol.h"
#include "message.h"

class Communicator {
    //current component id
    const CompID CID;

    //message buffers for each component
    inline static Message gameBuffer = EmptyMsg();
    inline static Message motorBuffer = EmptyMsg();
    inline static Message inputBuffer = EmptyMsg();
    //this might not be able to properly send msgs
    //when input is need store the component that asked and that use that
    //for the receiver of the message


  public:
    Communicator(CompID id) : CID(id) {}
    void Send(CompID, Protocol, DeviceInput d = DeviceInput::NULL_DIN);
    Message Retrieve();
    bool Peek();
};


#endif
