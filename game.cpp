#include"game.h"

Game::Game(){
  // Initializing worldMap
  worldMap = new char*[SIZE];
  for (int i = 0; i < SIZE; i++)
    worldMap[i] = new char[SIZE];

  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = '-';

    worldMap[SIZE/2 - 1][SIZE/2 - 1] = worldMap[SIZE/2][SIZE/2] = 'O';
    worldMap[SIZE/2 - 1][SIZE/2] = worldMap[SIZE/2][SIZE/2 - 1] = 'X';
    black = white = 2;

    end = 0;
    pass = 0;
}

int Game::getBlackScore(){
  return black;
}

int Game::getWhiteScore(){
  return white;
}

bool Game::isPassed(){
  return pass;
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

int Game::maxValue(Node * node, int depth, int alpha, int beta){
  vector<Node *> successors = node->buildSuccessors();

  if(successors.empty() || depth == MINIMAX_DEPTH)
    return node->getUtility();

  int highest = INT_MIN;

  depth++;

  for (Node * successor : successors){
    int value = minValue(successor, depth, alpha, beta);

    if(value > highest)
      highest = value;

    if (highest >= beta)
      return highest;

    alpha = (alpha >= highest) ? alpha : highest;
  }

  return highest;
}

int Game::minValue(Node * node, int depth, int alpha, int beta){
  vector<Node *> successors = node->buildSuccessors();

  if(successors.empty() || depth == MINIMAX_DEPTH)
    return node->getUtility();

  int lowest = INT_MAX;

  depth++;

  for (Node * successor : successors){
    int value = maxValue(successor, depth, alpha, beta);

    if(value < lowest)
      lowest = value;

    if (lowest <= alpha)
      return lowest;

    beta = (beta <= lowest) ? beta : lowest;
  }

  return lowest;
}

Node * Game::minimax(Node * node){

  int depth = 0;

  int value = maxValue(node, depth, INT_MIN, INT_MAX);

  for (Node * successor : node->buildSuccessors())
    if(successor->getUtility() == value)
      return successor;

}

void Game::computerTurn(){
  if((new Node(worldMap, 'X'))->buildSuccessors().empty() == 0){
    pass = 0;
    cout << "Computer's turn: ";

    // Stating minimax algorithm
    Node * movement = minimax(new Node(worldMap));

    worldMap = movement->getWorldMap();

    computeScore();

    cout << static_cast<char>(movement->getColumn() + 65);
    cout << to_string(movement->getRow() + 1);
    cout << endl;
  } else {
    if (pass == 1){
      end = 1;
    } else {
      pass = 1;
      cout << "Computer passed" << endl;
    }
  }

}

void Game::humanTurn(){
  if((new Node(worldMap, 'O'))->buildSuccessors().empty() == 0){
    pass = 0;

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

      worldMap = node->makeMovement();

      computeScore();

    } else {
      cout << "Invalid move, try again" << endl;

      humanTurn();
    }
  } else {
    if (pass == 1) {
      end = 1;
    }
    else {
      pass = 1;

      cout << "Human passed" << endl;
    }
  }
}

bool Game::isEnd(){
  return end;
}
