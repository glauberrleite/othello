#include<vector>
#include<iostream>
#include<climits>
#include"node.h"

using namespace std;

class Game {
public:
  // Defining board
  static const int SIZE = 8;
  char ** worldMap;
  Game(int difficulty = 1);
  bool isEnd();
  void humanTurn();
  void computerTurn();
  int getBlackScore();
  int getWhiteScore();
  bool isPassed();
private:
  bool pass;
  int difficulty;
  int maxValue(Node * node, int depth, int alpha, int beta);
  int minValue(Node * node, int depth, int alpha, int beta);
  Node * minimax(Node * node);
  void computeScore();
  int black;
  int white;
  bool end;
};
