#include"direction.h"
#include<vector>

class Node {
public:
  Node(int row, int column, char worldMap[][8], char player = 'O');
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
