#include<iostream>

using namespace std;

// The board needs to be 8
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
  cout << "     A B C D E F G H" << endl;

}

int main(){
  cout << "Othello Game" << endl << endl;

  // Initializing worldMap
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      worldMap[i][j] = '-';

  worldMap[SIZE/2 - 1][SIZE/2 - 1] = worldMap[SIZE/2][SIZE/2] = 'O';
  worldMap[SIZE/2 - 1][SIZE/2] = worldMap[SIZE/2][SIZE/2 - 1] = 'X';

  printWorldMap();

  return 0;
}
