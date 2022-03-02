#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{ 
    board=new Board;
    score=0;
}   
Game::~Game()
{
    delete board;
}
Direction Game::read_input()
{
   char press;
   cin>>press;
   if(press=='e')
   {    
     return UP;
   }
   else if(press=='d')
   {
       return DOWN;
   }
   else if(press=='s')
   {
       return LEFT;
   }
   else if(press=='f')
   {  
       return RIGHT;
   }
   else
   {
       return INVALID;
   }
}
void Game::printScore()
{
   cout<<score<<endl;
}
int Game::getScore()
{
    return score;
}
void Game::autoPlay()
{  
   int num=0;
   board->flag=1;
   while(!(board->checkGameOver()))
   {  
      if(num>3) num=0;
      Direction dir;
      dir=(Direction)num;
      score+=board->moveBoard(dir);
      num++;
   }
}
void Game::start()
{ 
   while(! (board->checkGameOver() ) )
   {  
      printScore();   
      board->displayBoard();   
      score+=board->moveBoard(read_input());
      cout<<endl;
   }
}