/* File:   message.h
   Author: Micah Weston
   Info:   Holds message class
*/

#ifndef __MESSAGE_H__
#define __MESSAGE_H__


#include "game_protocol.h"

class Message {
    //message elements
    CompID sender;
    CompID receiver;
    Protocol msg;
    DeviceInput din;

  public:
    //constructor
    Message(CompID s = NULL_ID, CompID r = NULL_ID, Protocol m = NULL_PTC, DeviceInput d = NULL_DIN)
      : sender(s), receiver(r), msg(m), din(d) {}

    //clear the message
    void Clear();
    //checks if empty
    bool IsEmpty();
    //set message (sender, receiver, message)
    void SetMsg(CompID s, CompID r, Protocol m);
    void SetMsg(CompID s, CompID r, Protocol m, DeviceInput d);
    //Extract message
    Protocol SeeReq() {
      return msg;
    }
    //Extract device input
    DeviceInput SeeDin() {
      return din;
    }
    //Extract sender
    CompID SeeSender() {
      return sender;
    }
};

Message EmptyMsg();

#endif
