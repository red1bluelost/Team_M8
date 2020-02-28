/* File:   chutes_and_ladders.cpp
   Author: Micah Weston
   Info:   Implements player class
*/
#include "chutes_and_ladders.h"

void Player::Reset() {
   curTile = 0;
   curPosn = {0, 0};
   motorControlled = false;
}