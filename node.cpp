#include"node.h"

Node::Node(int row, int column, char worldMap[][8], char player){
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

  bool nextToEnemy = 0;
  switch(direction){
    case N: {
      for(int i = row - 1; i > -1; --i){
        if(nextToEnemy && worldMap[i][column] == player){
          return 1;
        } else if(worldMap[i][column] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case S: {
      for(int i = row + 1; i < 8; ++i){
        if(nextToEnemy && worldMap[i][column] == player){
          return 1;
        } else if(worldMap[i][column] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case E: {
      for(int j = column + 1; j < 8; ++j){
        if(nextToEnemy && worldMap[row][j] == player){
          return 1;
        } else if(worldMap[row][j] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case W: {
      for(int j = column - 1; j > -1; --j){
        if(nextToEnemy && worldMap[row][j] == player){
          return 1;
        } else if(worldMap[row][j] == enemy) {
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case NE: {
      for (int i = row - 1, j = column + 1; i > -1 && j < 8; --i, ++j){
        if(nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if(worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case NW: {
      for (int i = row - 1, j = column - 1; i > -1 && j > -1; --i, --j){
        if(nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if(worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case SE: {
      for (int i = row + 1, j = column + 1; i < 8 && j < 8; ++i, ++j){
        if(nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if(worldMap[i][j] == enemy){
          nextToEnemy = 1;
          continue;
        } else break;
      }
    }
    case SW: {
      for (int i = row + 1, j = column - 1; i < 8 && j > -1; ++i, --j){
        if(nextToEnemy && worldMap[i][j] == player){
          return 1;
        } else if(worldMap[i][j] == enemy){
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
    if(worldMap[row][column] != '-')
      return 0;

    // Check if the move is making an anchor
    for(unsigned int i = 0; i < 8; ++i){
      if(existsAnchor(static_cast<Direction>(i))){
        // Node is valid
        return 1;
      }
    }

    return 0;
}

std::vector<Node *> Node::buildSuccessors(){
  std::vector<Node *> successors;

  return successors;
}
