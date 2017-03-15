#include"direction.h"
#include<vector>

class Node {
public:
  Node(char worldMap[][8], int row = 0, int column = 0, char player = 'O');
  char worldMap[8][8];
  char getPlayer();
  int getColumn();
  int getRow();
  bool isValid();
  std::vector<Node *> buildSuccessors();
  bool existsAnchor(Direction direction);
private:
  int minimax;
  char player;
  int row;
  int column;
  int depth;
};
