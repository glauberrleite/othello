#include"direction.h"
#include<vector>

class Node {
public:
  Node(char ** worldMap, char player = 'X', int row = 0, int column = 0);
  char getPlayer();
  int getColumn();
  int getRow();
  bool isValid();
  std::vector<Node *> buildSuccessors();
  bool existsAnchor(Direction direction);
  char ** getWorldMap();
  char ** makeMovement();
  int computeScore();
  int getUtility();
private:
  void convertEnemies();
  std::vector<Node *> successors;
  char ** worldMap;
  int utility;
  char player;
  int row;
  int column;
  int depth;
};
