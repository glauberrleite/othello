#include<iostream>
#include<string>

using namespace std;

// Game score, black is X and white is O
int black, white;

// Defining board
const int SIZE = 8;
char worldMap[SIZE][SIZE];

void printWorldMap(){

  cout << "     A B C D E F G H" << endl;
  cout << "  = = = = = = = = = = =" << endl;

  for(int i = 0; i < SIZE; i++){
    cout << to_string(i + 1) + " || ";
    for (int j = 0; j < SIZE; j++){
      cout << worldMap[i][j];
      cout << " ";
    }
    cout << "|| " + to_string(i + 1) << endl;
  }

  cout << "  = = = = = = = = = = =" << endl;
  cout << "     A B C D E F G H" << endl << endl;

  cout << "    X(" + to_string(black) + ")          ";
  cout << "O(" + to_string(white) + ")" << endl;

}

void computeScore(){

  black = white = 0;

  for(int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++)
        if(worldMap[i][j] == 'X')
          ++black;
        else if(worldMap[i][j] == 'O')
          ++white;
}

bool isValid(int row, int column, char player) {
  // Avoid overwriting
  if(worldMap[row][column] != '-')
    return 0;

  // Force move to be next to the enemy
  bool next = 0;
  char enemy = (player == 'X') ? 'O' : 'X';
  if((row > 0 && row < SIZE) && (column > 0 && column < SIZE)) {
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

void convertEnemies(int row, int column, char player){

  char enemy = (player == 'X') ? 'O' : 'X';

  // Checking if there's an anchor down
  bool down = 0;
  for(int i = row + 1; i < SIZE; ++i){
    if(worldMap[i][column] == player){
      down = 1;
      break;
    }
  }
  if(down){
    for(int i = row + 1; i < SIZE; ++i) {
      if(worldMap[i][column] == enemy)
        worldMap[i][column] = player;
      else break;
    }
  }

  // Checking if there's an anchor up
  bool up = 0;
  for(int i = row - 1; i > 0; ++i){
    if(worldMap[i][column] == player){
      up = 1;
      break;
    }
  }
  if(up){
    for(int i = row - 1; i > 0; ++i) {
      if(worldMap[i][column] == enemy){
        worldMap[i][column] = player;}
      else break;
    }
  }

  // Checking if there's an anchor right
  bool right = 0;
  for(int j = column + 1; j < SIZE; ++j){
    if(worldMap[row][j] == player){
      right = 1;
      break;
    }
  }
  if(right){
    for(int j = column + 1; j < SIZE; ++j) {
      if(worldMap[row][j] == enemy)
        worldMap[row][j] = player;
      else break;
    }
  }

  // Checking if there's an anchor left
  bool left = 0;
  for(int j = column - 1; j > 0; ++j){
    if(worldMap[row][j] == player){
      left = 1;
      break;
    }
  }
  if(left){
    for(int j = column - 1; j > 0; ++j) {
      if(worldMap[row][j] == enemy)
        worldMap[row][j] = player;
      else break;
    }
  }

  // Checking diagonal down-right
  bool down_right = 0;
  for (int i = row + 1, j = column + 1; i < SIZE && j < SIZE; ++i, ++j){
    if(worldMap[i][j] == player){
      down_right = 1;
      break;
    }
  }
  if(down_right){
    for(int i = row + 1, j = column + 1; i < SIZE && j < SIZE; ++i, ++j){
      if(worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

  // Checking diagonal up-right
  bool up_right = 0;
  for (int i = row - 1, j = column + 1; i > 0 && j < SIZE; ++i, ++j){
    if(worldMap[i][j] == player){
      up_right = 1;
      break;
    }
  }
  if(up_right){
    for(int i = row - 1, j = column + 1; i > 0 && j < SIZE; ++i, ++j){
      if(worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

  // Checking diagonal down-left
  bool down_left = 0;
  for (int i = row + 1, j = column - 1; i < SIZE && j > 0; ++i, ++j){
    if(worldMap[i][j] == player){
      down_left = 1;
      break;
    }
  }
  if(down_left){
    for(int i = row + 1, j = column - 1; i < SIZE && j > 0; ++i, ++j){
      if(worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

  // Checking diagonal up-left
  bool up_left = 0;
  for (int i = row - 1, j = column - 1; i > 0 && j > 0; ++i, ++j){
    if(worldMap[i][j] == player){
      up_left = 1;
      break;
    }
  }
  if(up_left){
    for(int i = row - 1, j = column - 1; i > 0 && j > 0; ++i, ++j){
      if(worldMap[i][j] == enemy)
        worldMap[i][j] = player;
        else break;
    }
  }

}

// Human turn
void proccessInput(){
  cout << "It's your turn: ";

  string input;
  getline(cin, input);

  int column = (int)input[0] - 97;
  // Become non case-sensitive
  if(column < 0)
    column = (int)(input[0]) - 65;

  int row = (int)(input[1]) - 49;

  if(isValid(row, column, 'X')){

    worldMap[row][column] = 'X';

    convertEnemies(row, column, 'X');

    computeScore();

    printWorldMap();

  } else {
    cout << "Invalid move, try again" << endl;

    proccessInput();
  }
}

int main(){
  cout << "Othello Game" << endl << endl;

  // Initializing worldMap
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = '-';

  worldMap[SIZE/2 - 1][SIZE/2 - 1] = worldMap[SIZE/2][SIZE/2] = 'O';
  worldMap[SIZE/2 - 1][SIZE/2] = worldMap[SIZE/2][SIZE/2 - 1] = 'X';
  black = white = 2;

  printWorldMap();

  proccessInput();

  return 0;
}
