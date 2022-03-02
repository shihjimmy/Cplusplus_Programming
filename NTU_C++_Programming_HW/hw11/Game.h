#include <stdio.h>
#include"Board.cpp"

class Game
{
private:
	Board* board;
	int score;
public:
	Game();
	~Game();
	Direction read_input();
	void printScore();
	void start();
	int getScore();
	void autoPlay();
};
