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
  void humanTurn();
  void computerTurn();
  int getBlackScore();
  int getWhiteScore();
private:
  Node * minimax(Node * root);
  void computeScore();
  int black;
  int white;
  bool end;
};
