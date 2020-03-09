/* File:   input_ctr.cpp
 * Author: Micah Weston
 * Info:   Implements input controller class
 */

#include "input_ctr.h"

//constructor that assigns all the pin numbers and pin modes
InputCtr::InputCtr(short int pb1, short int pb2, short int pb3,
    short int pb4, short int pb5, short int pb6, short int enter,
    short int l1, short int l2, short int l3,
    short int l4, short int l5, short int l6)
     : controller(CompID::INPUT_CTR),
     pinb1(pb1),
     pinb2(pb2),
     pinb3(pb3),
     pinb4(pb4),
     pinb5(pb5),
     pinb6(pb6),
     pinen(enter),
     lcd(l1, l2, l3, l4, l5, l6) {
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  pinMode(pb4, INPUT_PULLUP);
  pinMode(pb5, INPUT_PULLUP);
  pinMode(pb6, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.clear();
}

//gets numbered input for dice rolls and number of players
void InputCtr::getNumberedInput(Message req) {
  //prompt the user for input
  lcd.clear();
  lcd.setCursor(0,1);
  if(req.SeeReq() == Protocol::GET_PLAYER_COUNT) {
    lcd.print("Enter number of");
    lcd.setCursor(1,1);
    lcd.print("players");
  } else if (req.SeeReq() == Protocol::GET_ROLL) {
    lcd.print("Spin and enter");
    lcd.setCursor(1,1);
    lcd.print("the result");
  }

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
  
  //return a response to the user
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("You entered ");
  lcd.print(curInput);

  //response to the requester
  this->Port.Send(req.SeeSender(), (Protocol) (1 + req.SeeReq()), (DeviceInput) curInput); 
}

void InputCtr::getYesNo(Message req) {
  //prompt the user for input
  lcd.clear();
  lcd.setCursor(0,1);
  if(req.SeeReq() == Protocol::GET_PLAYER_STATE) {
    lcd.print("Need Team M8?");
    lcd.setCursor(1,1);
    lcd.print("1 = Yes, 2 = No");
  } else if (req.SeeReq() == Protocol::GET_ROLL) { //modify for replay
    lcd.print("1 = Yes, 2 = No");
    lcd.setCursor(1,1);
    lcd.print("the result");
  }

  int curInput;
  do {
    if(digitalRead(pinb1) == LOW && curInput != 1) {//this might get scream for not converting types
      curInput = 7;
    } else if(digitalRead(pinb2) == LOW && curInput != 2) {
      curInput = 8;
    }
  } while(digitalRead(pinen) == LOW); 

  //return a response to the user
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("You entered ");
  lcd.print(curInput == 7 ? "Yes" : "No");  

  //response to the requester
  Port.Send(req.SeeSender(), (Protocol) (1 + req.SeeReq()), (DeviceInput) curInput);
}







//checks port, execute msg if one is there
void InputCtr::Tick() {
  if (!Port.Peek()) {return;}
  
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
