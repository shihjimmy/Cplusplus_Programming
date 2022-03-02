#include <stdio.h>
#include "Direction.h"

class Board{
private:
    char tiles[4][4];
    
public:
    Board();
    int flag=0;
    void displayBoard();
    void newTile();
    int moveSingleLine(char line[4], char new_line[4]);
    int convert(char);
    int moveBoard(Direction dir);
    int movecopy(Direction dir);
    bool check(char a[][4],char b[][4]);
    bool checkGameOver();
};