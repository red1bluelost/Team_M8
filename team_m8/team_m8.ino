/* File:   team_m8.ino
 * Author: Micah Weston
 * Info:   Main program for Team M8 board game
 */

#include "game_ctr.h"
#include "input_ctr.h"

MovePtc MoveBuffer[256]; //might need to be volatile
GameCtr GC;
InputCtr IC(3,4,5,6,7,8,9,16,15,14,13,12,11); //not gonna work until I know larger board type

void setup() {
  // put your setup code here, to run once:
  GC.StartGame();
}

void loop() {
  // put your main code here, to run repeatedly:
  GC.Tick();
  IC.Tick();
}
