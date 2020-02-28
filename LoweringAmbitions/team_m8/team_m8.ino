/* File:   team_m8.ino
   Author: Micah Weston
   Info:   Main program for Team M8 board game
*/

#include "game_ctr.h"
#include "input_ctr.h"


GameCtr GC;
InputCtr IC(3,4,5,6,7,8,9);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  GC.Tick();
  IC.Tick();
}
