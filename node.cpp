#include"node.h"

Node::Node(int row, int column, char worldMap[][8], char player){
  this->row = row;
  this->column = column;
  this->player = player;
  for(int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        this->worldMap[i][j] = worldMap[i][j];
  // calculate minimax
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
  Node * node = this;
  switch(direction){
    case N: {
      for(int i = node->getRow() - 1; i > 0; ++i){
        if(node->worldMap[i][node->getColumn()] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case S: {
      for(int i = node->getRow() + 1; i < 8; ++i){
        if(node->worldMap[i][node->getColumn()] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case E: {
      for(int j = node->getColumn() + 1; j < 8; ++j){
        if(node->worldMap[node->getRow()][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case W: {
      for(int j = node->getColumn() - 1; j > 0; ++j){
        if(node->worldMap[node->getRow()][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case NE: {
      for (int i = node->getRow() - 1, j = node->getColumn() + 1; i > 0 && j < 8; ++i, ++j){
        if(node->worldMap[i][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case NW: {
      for (int i = node->getRow() - 1, j = node->getColumn() - 1; i > 0 && j > 0; ++i, ++j){
        if(node->worldMap[i][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case SE: {
      for (int i = node->getRow() + 1, j = node->getColumn() + 1; i < 8 && j < 8; ++i, ++j){
        if(node->worldMap[i][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
    case SW: {
      for (int i = node->getRow() + 1, j = node->getColumn() - 1; i < 8 && j > 0; ++i, ++j){
        if(node->worldMap[i][j] == node->getPlayer()){
          return 1;
        }
      }
      break;
    }
  }

  return 0;
}

bool Node::isValid(){
    // Avoid overwriting
    if(worldMap[row][column] != '-')
      return 0;

    // Force move to be next to the enemy
    bool next = 0;
    char enemy = (player == 'X') ? 'O' : 'X';
    if((row > 0 && row < 8) && (column > 0 && column < 8)) {
      if(worldMap[row + 1][column] == enemy) next = 1;
      else if(worldMap[row][column + 1] == enemy) next = 1;
      else if(worldMap[row - 1][column] == enemy) next = 1;
      else if(worldMap[row][column - 1] == enemy) next = 1;
    } else {
      if (row == 0){
        if (worldMap[row + 1][column] == enemy) next = 1;
      } else if (worldMap[row - 1][column] == enemy) next = 1;

      if(column == 0){
        if (worldMap[row][column + 1] == enemy) next = 1;
      } else if (worldMap[row][column - 1] == enemy) next == 1;
    }

    if(!next) return 0;

    return 1;
}

std::vector<Node *> Node::buildSuccessors(){
  std::vector<Node *> successors;

  return successors;
}
