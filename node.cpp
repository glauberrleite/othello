#include"node.h"

Node::Node(char worldMap[][8], char player, int row, int column){
  this->row = row;
  this->column = column;
  this->player = player;
  for(int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        this->worldMap[i][j] = worldMap[i][j];
}

char Node::getPlayer(){
  return player;
}

int Node::getRow(){
  return row;
}

int Node::getColumn(){
  return column;
}

bool Node::existsAnchor(Direction direction){
  char enemy = (player == 'X') ? 'O' : 'X';

  switch(direction){
    case N: {
      bool nextToEnemy = 0;
      for (int i = row - 1; i >= 0; --i){
        if (nextToEnemy && worldMap[i][column] == player){
          return 1;
        } else if (worldMap[i][column] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case S: {
      bool nextToEnemy = 0;
      for (int i = row + 1; i < 8; ++i){
        if (nextToEnemy && worldMap[i][column] == player){
          return 1;
        } else if (worldMap[i][column] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case E: {
      bool nextToEnemy = 0;
      for (int j = column + 1; j < 8; ++j){
        if (nextToEnemy && worldMap[row][j] == player){
          return 1;
        } else if (worldMap[row][j] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case W: {
      bool nextToEnemy = 0;
      for (int j = column - 1; j >= 0; --j){
        if (nextToEnemy && worldMap[row][j] == player){
          return 1;
        } else if (worldMap[row][j] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case NE: {
      bool nextToEnemy = 0;
      for (int i = row - 1, j = column + 1; i >= 0 && j < 8; --i, ++j){
        if (nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if (worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case NW: {
      bool nextToEnemy = 0;
      for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j){
        if (nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if (worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case SE: {
      bool nextToEnemy = 0;
      for (int i = row + 1, j = column + 1; i < 8 && j < 8; ++i, ++j){
        if (nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if (worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case SW: {
      bool nextToEnemy = 0;
      for (int i = row + 1, j = column - 1; i < 8 && j >= 0; ++i, --j){
        if (nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if (worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
  }

  return 0;
}

bool Node::isValid(){
    // Avoid overwriting
    if (worldMap[row][column] != '-')
      return 0;

    // Check if the move is making an anchor
    for (unsigned int i = 0; i < 8; ++i){
      if (existsAnchor(static_cast<Direction>(i))){
        // Node is valid
        return 1;
      }
    }

    return 0;
}

void Node::convertEnemies(){
  char enemy = (player == 'X') ? 'O' : 'X';

  if (existsAnchor(N)){
    for (int i = row - 1; i > 0; ++i) {
      if (worldMap[i][column] == enemy)
        worldMap[i][column] = player;
      else break;
    }
  }

  if (existsAnchor(S)){
    for (int i = row + 1; i < 8; ++i) {
      if (worldMap[i][column] == enemy)
        worldMap[i][column] = player;
      else break;
    }
  }

  if (existsAnchor(E)){
    for (int j = column + 1; j < 8; ++j) {
      if (worldMap[row][j] == enemy)
        worldMap[row][j] = player;
      else break;
    }
  }

  if (existsAnchor(W)){
    for (int j = column - 1; j > 0; ++j) {
      if (worldMap[row][j] == enemy)
        worldMap[row][j] = player;
      else break;
    }
  }

  if (existsAnchor(SE)){
    for (int i = row + 1, j = column + 1; i < 8 && j < 8; ++i, ++j){
      if (worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

  if (existsAnchor(NE)){
    for (int i = row - 1, j = column + 1; i > 0 && j < 8; ++i, ++j){
      if (worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

  if (existsAnchor(SW)){
    for (int i = row + 1, j = column - 1; i < 8 && j > 0; ++i, ++j){
      if (worldMap[i][j] == enemy)
        worldMap[i][j] = player;
      else break;
    }
  }

  if (existsAnchor(NW)){
    for (int i = row - 1, j = column - 1; i > 0 && j > 0; ++i, ++j){
      if (worldMap[i][j] == enemy)
        worldMap[i][j] = player;
      else break;
    }
  }
}

char ** Node::makeMovement(){
  worldMap[row][column] = player;

  convertEnemies();

  char ** newWorld = new char*[8];
  for (int i = 0; i < 8; i++)
    newWorld[i] = new char[8];

  for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        newWorld[i][j] = worldMap[i][j];

  return newWorld;
}

std::vector<Node *> Node::buildSuccessors(){
  std::vector<Node *> successors;

  char enemy = (player == 'X') ? 'O' : 'X';

  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++){
      Node * candidate = new Node(worldMap, enemy, i, j);
      if (candidate->isValid()){
        successors.push_back(candidate);
      }
    }

  return successors;
}
