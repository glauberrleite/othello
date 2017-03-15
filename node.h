#include"direction.h"
#include<vector>

class Node {
public:
  Node(char worldMap[][8], char player = 'O', int row = 0, int column = 0);
  char getPlayer();
  int getColumn();
  int getRow();
  bool isValid();
  std::vector<Node *> buildSuccessors();
  bool existsAnchor(Direction direction);
  char ** makeMovement();
private:
  void convertEnemies();
  char worldMap[8][8];
  int minimax;
  char player;
  int row;
  int column;
  int depth;
};
