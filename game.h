#include<vector>
#include<iostream>
#include"node.h"

using namespace std;

class Game {
public:
  // Defining board
  static const int SIZE = 8;
  char worldMap[SIZE][SIZE];
  Game();
  bool isEnd();
  static char** convertEnemies(Node * node);
  void humanTurn();
  void computerTurn();
private:
  void computeScore();
  int black;
  int white;
  bool end;
};
