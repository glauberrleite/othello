#include<iostream>
#include<string>
#include"game.h"

using namespace std;

void printWorldMap(Game* game){

  cout << endl << "     A B C D E F G H" << endl;
  cout << "  = = = = = = = = = = =" << endl;

  for (int i = 0; i < 8; i++){
    cout << to_string(i + 1) + " || ";
    for (int j = 0; j < 8; j++){
      cout << game->worldMap[i][j];
      cout << " ";
    }
    cout << "|| " + to_string(i + 1) << endl;
  }

  cout << "  = = = = = = = = = = =" << endl;
  cout << "     A B C D E F G H" << endl << endl;

  cout << "    X(" + to_string(game->getBlackScore()) + ")          ";
  cout << "O(" + to_string(game->getWhiteScore()) + ")" << endl << endl;

}

// Human turn
void humanTurn(){

}

int main(){
  cout << "Othello Game" << endl;

  Game * game = new Game();

  printWorldMap(game);

  while (!game->isEnd()){

    game->humanTurn();

    printWorldMap(game);

    if (!game->isEnd()){
      game->computerTurn();

      printWorldMap(game);
    }
  }

  cout << "Game Over" << endl;
  return 0;
}
