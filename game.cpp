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

int Game::maxValue(Node * node, int depth){
  vector<Node *> successors = node->buildSuccessors();

  if(successors.empty() || depth == MINIMAX_DEPTH)
    return node->getUtility();

  int highest = 0;

  depth++;

  for (Node * successor : successors){
    int value = minValue(successor, depth);

    if(value > highest)
      highest = value;
  }

  return highest;
}

int Game::minValue(Node * node, int depth){
  vector<Node *> successors = node->buildSuccessors();

  if(successors.empty() || depth == MINIMAX_DEPTH)
    return node->getUtility();

  int lowest = INT_MAX;

  depth++;

  for (Node * successor : successors){
    int value = maxValue(successor, depth);

    if(value < lowest)
      lowest = value;
  }

  return lowest;
}

Node * Game::minimax(Node * node){

  int depth = 1;

  int value = maxValue(node, depth);

  for (Node * successor : node->buildSuccessors())
    if(successor->getUtility() == value)
      return successor;

}

void Game::computerTurn(){
  cout << "Computer's turn: ";

  // Stating minimax algorithm
  Node * movement = minimax(new Node(worldMap));

  char** newWorld = movement->getWorldMap();

  for(int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = newWorld[i][j];

  computeScore();

  cout << static_cast<char>(movement->getColumn() + 65);
  cout << to_string(movement->getRow() + 1);
  cout << endl;

  if (movement->buildSuccessors().empty())
    end = 1;

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

    if(node->buildSuccessors().empty())
      end = 1;

  } else {
    cout << "Invalid move, try again" << endl;

    humanTurn();
  }
}

bool Game::isEnd(){
  return end;
}
