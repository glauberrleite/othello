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

  for (int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        if (worldMap[i][j] == 'X')
          ++black;
        else if(worldMap[i][j] == 'O')
          ++white;
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

  Node * node = new Node(worldMap, 'X', row, column);

  if(node->isValid()){

    char** newWorld = node->makeMovement();

    for (int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        worldMap[i][j] = newWorld[i][j];

    computeScore();

    if(node->buildSuccessors().empty()){
      end = 1;
    }

  } else {
    cout << "Invalid move, try again" << endl;

    humanTurn();
  }
}

Node * Game::minimax(Node * root){
  return root;
}

void Game::computerTurn(){
  cout << "Computer's turn: ";

  Node * movement = minimax(new Node(worldMap, 'O'));

  char** newWorld = movement->makeMovement();

  for(int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = newWorld[i][j];

  computeScore();

  cout << static_cast<char>(movement->getColumn() + 65);
  cout << to_string(movement->getRow() + 1);
  cout << endl;
}

bool Game::isEnd(){
  return end;
}
