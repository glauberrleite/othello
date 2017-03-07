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

void proccessInput(string& input){

  int column = (int)input[0] - 97;
  // Become non case-sensitive
  if(column < 0)
    column = (int)(input[0]) - 65;

  int row = (int)(input[1]) - 49;

  worldMap[row][column] = 'X';

  computeScore();

  printWorldMap();
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

  // First turn
  cout << "It's your turn: ";

  string input;
  getline(cin, input);

  proccessInput(input);

  return 0;
}
