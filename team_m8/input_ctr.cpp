/* File:   input_ctr.cpp
 * Author: Micah Weston
 * Info:   Implements input controller class
 */

#include "input_ctr.h"


InputCtr::InputCtr(short int pb1, short int pb2, short int pb3,
    short int pb4, short int pb5, short int pb6, short int enter)
     : controller(CompID::INPUT_CTR) {
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

void InputCtr::getNumberedInput(Message req) {
  //possibly prompt the user for input
  int curInput;
  do {
    if(digitalRead(pinb1) == LOW && curInput != 1) {//this might get scream for not converting types
      curInput = 1;
    } else if(digitalRead(pinb2) == LOW && curInput != 2) {
      curInput = 2;
    } else if(digitalRead(pinb3) == LOW && curInput != 3) {
      curInput = 3;
    } else if(digitalRead(pinb4) == LOW && curInput != 4) {
      curInput = 4;
    } else if(digitalRead(pinb5) == LOW && curInput != 5) {
      curInput = 5;
    } else if(digitalRead(pinb6) == LOW && curInput != 6) {
      curInput = 6;
    }
  } while(digitalRead(pinen) == LOW); 
  //maybe return a response to the user
  

  //response to the requester
  this->Port.Send(req.SeeSender(), req.SeeReq() + 1, (DeviceInput) curInput); 
}

void InputCtr::getYesNo(Message req) {
  //possibly prompt the user for input
  DeviceInput curInput;
  do {
    if(digitalRead(pinb1) == LOW && curInput != 1) {//this might get scream for not converting types
      curInput = 7;
    } else if(digitalRead(pinb2) == LOW && curInput != 2) {
      curInput = 8;
    }
  } while(digitalRead(pinen) == LOW); 
  //maybe return a response to the user
  

  //response to the requester
  this->Port.Send(req.SeeSender(), req.SeeReq() + 1, (int) curInput);
}







void InputCtr::Tick() {
  if (!Port.Peek()) { return; }
  
  Message req = Port.Retrieve();
  switch(req.SeeReq()) {
    case Protocol::GET_ROLL: //need to set up protocols 
    case Protocol::GET_PLAYER_COUNT:
      this->getNumberedInput(req);
      return;
    case Protocol::GET_PLAYER_STATE:
      this->getYesNo(req);
      return;

  }
}
