#include<iostream>
#include<string>
#include"game.h"

using namespace std;

void printWorldMap(Game* game){

  cout << endl << "     A B C D E F G H" << endl;
  cout << "  = = = = = = = = = = =" << endl;

  for (int i = 0; i < Game::SIZE; i++){
    cout << to_string(i + 1) + " || ";
    for (int j = 0; j < Game::SIZE; j++){
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

    if (!game->isPassed())
      printWorldMap(game);

    if (!game->isEnd()){
      game->computerTurn();

      if (!game->isPassed())
        printWorldMap(game);
    }
  }

  if(game->getBlackScore() > game->getWhiteScore())
    cout << "Human Wins!" << endl;
  else if (game->getWhiteScore() > game->getBlackScore())
    cout << "Computer Wins!" << endl;
  else cout << "Draw game" << endl;

  cout << "Game Over" << endl;
  return 0;
}
