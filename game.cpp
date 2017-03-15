#include"game.h"

Game::Game(){
  // Initializing worldMap
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = '-';

    worldMap[SIZE/2 - 1][SIZE/2 - 1] = worldMap[SIZE/2][SIZE/2] = 'O';
    worldMap[SIZE/2 - 1][SIZE/2] = worldMap[SIZE/2][SIZE/2 - 1] = 'X';
    black = white = 2;

    end = 0;
}

int Game::getBlackScore(){
  return black;
}

int Game::getWhiteScore(){
  return white;
}

void Game::computeScore(){

  black = white = 0;

  for(int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        if(worldMap[i][j] == 'X')
          ++black;
        else if(worldMap[i][j] == 'O')
          ++white;
}

char** Game::convertEnemies(Node * node){

  char enemy = (node->getPlayer() == 'X') ? 'O' : 'X';

  char ** newWorld = new char*[8];
  for(int i = 0; i < SIZE; i++)
    newWorld[i] = new char[8];

  for(int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        newWorld[i][j] = node->worldMap[i][j];


  if(node->existsAnchor(N)){
    for(int i = node->getRow() - 1; i > 0; ++i) {
      if(node->worldMap[i][node->getColumn()] == enemy){
        newWorld[i][node->getColumn()] = node->getPlayer();
      }
      else break;
    }
  }

  if(node->existsAnchor(S)){
    for(int i = node->getRow() + 1; i < SIZE; ++i) {
      if(node->worldMap[i][node->getColumn()] == enemy)
        newWorld[i][node->getColumn()] = node->getPlayer();
      else break;
    }
  }

  if(node->existsAnchor(E)){
    for(int j = node->getColumn() + 1; j < SIZE; ++j) {
      if(node->worldMap[node->getRow()][j] == enemy)
        newWorld[node->getRow()][j] = node->getPlayer();
      else break;
    }
  }

  if(node->existsAnchor(W)){
    for(int j = node->getColumn() - 1; j > 0; ++j) {
      if(node->worldMap[node->getRow()][j] == enemy)
        newWorld[node->getRow()][j] = node->getPlayer();
      else break;
    }
  }

  if(node->existsAnchor(SE)){
    for(int i = node->getRow() + 1, j = node->getColumn() + 1; i < SIZE && j < SIZE; ++i, ++j){
      if(node->worldMap[i][j] == enemy)
        newWorld[i][j] = node->getPlayer();
        else break;
    }
  }

  if(node->existsAnchor(NE)){
    for(int i = node->getRow() - 1, j = node->getColumn() + 1; i > 0 && j < SIZE; ++i, ++j){
      if(node->worldMap[i][j] == enemy)
        newWorld[i][j] = node->getPlayer();
        else break;
    }
  }

  if(node->existsAnchor(SW)){
    for(int i = node->getRow() + 1, j = node->getColumn() - 1; i < SIZE && j > 0; ++i, ++j){
      if(node->worldMap[i][j] == enemy)
        newWorld[i][j] = node->getPlayer();
        else break;
    }
  }

  if(node->existsAnchor(NW)){
    for(int i = node->getRow() - 1, j = node->getColumn() - 1; i > 0 && j > 0; ++i, ++j){
      if(node->worldMap[i][j] == enemy)
        newWorld[i][j] = node->getPlayer();
        else break;
    }
  }


  return newWorld;

}

void Game::humanTurn(){
  cout << "It's your turn: ";

  string input;
  getline(cin, input);

  int column = (int)input[0] - 97;
  // Become non case-sensitive
  if(column < 0)
    column = (int)(input[0]) - 65;

  int row = (int)(input[1]) - 49;

  Node * node = new Node(worldMap, row, column, 'X');

  if(node->isValid()){

    char** newWorld = convertEnemies(node);

    for(int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        worldMap[i][j] = newWorld[i][j];

    worldMap[row][column] = 'X';

    computeScore();

  } else {
    cout << "Invalid move, try again" << endl;

    humanTurn();
  }
}

Node * Game::minimax(Node * root){

}

void Game::computerTurn(){
  cout << "Computer's turn: ";

  Node * movement = minimax(new Node(worldMap));

  char** newWorld = convertEnemies(movement);

  for(int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = newWorld[i][j];

  worldMap[movement->getRow()][movement->getColumn()] = 'O';

  computeScore();

  cout << static_cast<char>(movement->getColumn() + 65);
  cout << to_string(movement->getRow() + 1);
  cout << endl;
}

bool Game::isEnd(){
  return end;
}
