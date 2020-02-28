/* File:   chutes_and_ladders.h
 * Author: Micah Weston
 * Info:   Contains board info, coordinates, and player class
 */

#ifndef __CHUTES_AND_LADDERS_H__
#define __CHUTES_AND_LADDERS_H__


struct posn {
  short int x, y;
};

struct gameTile {
  posn Position;
  bool IsPipe;
  int Drain;
};
          /*posn probably need changed*/
//std::array<gameTile, 101> CAL_Tiles = { { { 0, 0}, false,  0 } // 0
//                                   { { 2, 2}, true,   18} // 1
//           { { 4, 2}, false,  2 } // 2
//           { { 6, 2}, false,  3 } // 3
//           { { 8, 2}, true,  14 } // 4
//           { {10, 2}, false,  5 } // 5
//           { {12, 2}, false,  6 } // 6
//           { {14, 2}, false,  7 } // 7
//           { {16, 2}, false,  8 } // 8
//           { {18, 2}, true,  31 } // 9
//           { {20, 2}, false, 10 } //10
//           { {20, 4}, false, 11 } //11
//           { {10, 2}, false, 12 } //12
//           { {10, 2}, false, 13 } //13
//           { {10, 2}, false, 14 } //14
//           { {10, 2}, false, 15 } //15
//           { {10, 2}, true,   6 } //16
//           { {10, 2}, false, 17 } //17
//           { {10, 2}, false, 18 } //18
//           { {10, 2}, false, 19 } //19
//           { {10, 2}, false, 20 } //20
//           { {10, 2}, true,  42 } //21
//           { {10, 2}, false, 22 } //22
//           { {10, 2}, false, 23 } //23
//           { {10, 2}, false, 24 } //24
//           { {10, 2}, false, 25 } //25
//           { {10, 2}, false, 26 } //26
//           { {10, 2}, false, 27 } //27
//           { {10, 2}, true,  84 } //28
//           { {10, 2}, false, 29 } //29
//           { {10, 2}, false, 30 } //30
//           { {10, 2}, false, 31 } //31
//           { {10, 2}, false, 32 } //32
//           { {10, 2}, false, 33 } //33
//           { {10, 2}, false, 34 } //34
//           { {10, 2}, false, 35 } //35
//           { {10, 2}, true,  44 } //36
//           { {10, 2}, false, 37 } //37
//           { {10, 2}, false, 38 } //38
//           { {10, 2}, false, 39 } //39
//           { {10, 2}, false, 40 } //40
//           { {10, 2}, false, 41 } //41
//           { {10, 2}, false, 42 } //42
//           { {10, 2}, false, 43 } //43
//           { {10, 2}, false, 44 } //44
//           { {10, 2}, false, 45 } //45
//           { {10, 2}, false, 46 } //46
//           { {10, 2}, false, 47 } //47
//           { {10, 2}, true,  26 } //48
//           { {10, 2}, true,  11 } //49
//           { {10, 2}, false, 50 } //50
//           { { 6, 2}, true,  67 } //51
//           { { 6, 2}, false, 52 } //52
//           { { 6, 2}, false, 53 } //53
//           { { 6, 2}, false, 54 } //54
//           { { 6, 2}, false, 55 } //55
//           { { 6, 2}, true,  53 } //56
//           { { 6, 2}, false, 57 } //57
//           { { 6, 2}, false, 58 } //58
//           { { 6, 2}, false, 59 } //59
//           { { 6, 2}, false, 60 } //60
//           { { 6, 2}, false, 61 } //61
//           { { 6, 2}, true,  19 } //62
//           { { 6, 2}, false, 63 } //63
//           { { 6, 2}, true,  60 } //64
//           { { 6, 2}, false, 65 } //65
//           { { 6, 2}, false, 66 } //66
//           { { 6, 2}, false, 67 } //67
//           { { 6, 2}, false, 68 } //68
//           { { 6, 2}, false, 69 } //69
//           { { 6, 2}, false, 70 } //70
//           { { 6, 2}, true,  91 } //71
//           { { 6, 2}, false, 72 } //72
//           { { 6, 2}, false, 73 } //73
//           { { 6, 2}, false, 74 } //74
//           { { 6, 2}, false, 75 } //75
//           { { 6, 2}, false, 76 } //76
//           { { 6, 2}, false, 77 } //77
//           { { 6, 2}, false, 78 } //78
//           { { 6, 2}, false, 79 } //79
//           { { 6, 2}, true,  100} //80
//           { { 6, 2}, false, 81 } //81
//           { { 6, 2}, false, 82 } //82
//           { { 6, 2}, false, 83 } //83
//           { { 6, 2}, false, 84 } //84
//           { { 6, 2}, false, 85 } //85
//           { { 6, 2}, false, 86 } //86
//           { { 6, 2}, true,  24 } //87
//           { { 6, 2}, false, 88 } //88
//           { { 6, 2}, false, 89 } //89
//           { { 6, 2}, false, 80 } //90
//           { { 6, 2}, false, 91 } //91
//           { { 6, 2}, false, 92 } //92
//           { { 6, 2}, true,  73 } //93
//           { { 6, 2}, false, 94 } //94
//           { { 6, 2}, true,  75 } //95
//           { { 6, 2}, false, 96 } //96
//           { { 6, 2}, false, 97 } //97
//           { { 6, 2}, true,  78 } //98
//           { { 6, 2}, false, 99 } //99
//           { { 6, 2}, false, 100} } //100


class Player {
  static int playerCount = 0;
  int turnNum;
  int curTile = 0;
  posn curPosn = {0, 0} ;
  bool motorControlled = false;

  public:
  Player() { turnNum = ++playerCount; }

  //set fields
  void SetTile(int t)       {curTile = t}
  void SetPosn(posn p)      {curPosn = p}
  void SetIfControl(bool b) {motorControlled = b}

  //get fields
  int GetTile()    {return curTile;}
  posn GetPosn()   {return curPosn;}
  bool IsMotored() {return motorControlled;}
  int TurnNum()    {return turnNum;}

};

#endif //__CHUTES_AND_LADDERS_H__
