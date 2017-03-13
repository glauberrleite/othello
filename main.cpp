#include<iostream>
#include<string>
#include"game.h"

using namespace std;

void printWorldMap(Game* game){

  cout << "     A B C D E F G H" << endl;
  cout << "  = = = = = = = = = = =" << endl;

  for(int i = 0; i < 8; i++){
    cout << to_string(i + 1) + " || ";
    for (int j = 0; j < 8; j++){
      cout << game->worldMap[i][j];
      cout << " ";
    }
    cout << "|| " + to_string(i + 1) << endl;
  }

  cout << "  = = = = = = = = = = =" << endl;
  cout << "     A B C D E F G H" << endl << endl;

  //cout << "    X(" + to_string(black) + ")          ";
  //cout << "O(" + to_string(white) + ")" << endl;

}

// Human turn
void humanTurn(){

}

int main(){
  cout << "Othello Game" << endl << endl;

  Game * game = new Game();

  while(!game->isEnd()){
    printWorldMap(game);

    game->humanTurn();

    printWorldMap(game);

    if(!game->isEnd())
      game->computerTurn();
  }

  cout << "Game Over";
  return 0;
}
