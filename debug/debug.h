/* File:   debug.h
 * Author: Micah Weston
 * Info:   Defines debugging tools for terminal and serial port
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "Arduino.h"
#include "iostream"

//defines debugging for serial port
#if __DEBUGGING__ == 1
  //Start serial port on arduino
  #define DEBUG_BEGIN(X)   Serial.begin(X);
  //Debug print line
  #define DEBUG_PRINTLN(X) Serial.println(X);
  //End serial port debugging
  #define DEBUG_END        Serial.end();
//defines debugging for computer terminal
#elif __DEBUGGING__ > 1
  //Start debug (no serial port)
  #define DEBUG_BEGIN(X)   ;
  //Debug print line
  #define DEBUG_PRINTLN(X) cout << X << endl;
  //Ends debugging (no serial port)
  #define DEBUG_END        ;
#else
  //Start debug (disable)
  #define DEBUG_BEGIN(X)   ;
  //Debug print line (disable)
  #define DEBUG_PRINTLN(X) ;
  //Ends debugging (disable)
  #define DEBUG_END        ;
#endif

#endif
