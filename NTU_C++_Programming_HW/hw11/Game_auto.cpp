#include<iostream>
#include"Game_auto.h"
using namespace std;

int main()
{
    int acc_score = 0;
    for( int i = 0 ; i < 1000 ; i ++)
    {
      Game *game = new Game();
      game->autoPlay();
      acc_score += game->getScore();
      delete game;
    }
     cout << "Average score: " << (double)acc_score/1000 <<endl;
     return 0;
}
