/* File:   input_ctr.h
 * Author: Micah Weston
 * Info:   Holds class for the input controller
 */

#ifndef __INPUT_CTR_H__
#define __INPUT_CTR_H__

#include <LiquidCrystal.h>
#include "Arduino.h"

#include "controller.h"

#include "game_protocol.h"
#include "communicator.h"
#include "message.h"

class InputCtr : private controller {
    //pins for buttons
    short int pinb1, pinb2, pinb3, pinb4, pinb5, pinb6, pinen;
    //lcd display for prompts


    //gets numbered input for dice rolls and number of players
    void getNumberedInput(Message); //used for die rolls and number of players and more
    void getYesNo(Message);

  public:
    //constructor that assigns all the pin numbers and pin modes
    InputCtr(short int, short int, short int, short int, short int, short int, short int);
    //checks port, execute msg if one is there
    void Tick();

};

#endif
