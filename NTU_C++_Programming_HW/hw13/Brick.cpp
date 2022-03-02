#include "Brick_abs.cpp"
#include<iostream>
#include<ctime>
using namespace std;

const char backgroud_x_length = 7;
const char backgroud_y_length = 16;
const char start_x_position   = backgroud_x_length / 2 - 1;
const char start_y_position   = 0;

const char brick_kind_count = 7;

const int shapeList[brick_kind_count][4] = {
{0xc400,0x4c00,	0x8c00,0xc800},//Shape B
{0x4840,0x4a00,	0x8480,0xa400},//Shape T
{0xcc00,0xcc00,	0xcc00,0xcc00},//Shape O 
{0xf00, 0x4444,	0xf00 ,0x4444},//Shape I 
{0xe800,0xc440,	0x2e00,0x88c0},//Shape L
{0x8e00,0xc880,	0xe200,0x44c0},//Shape J 
{0xc600,0x4c80,	0xc600,0x4c80} //Shape Z 
}; 

/* TO DO */
class Brick: public Brick_abs
{
public:
     char kind;
     char direction;
     char x;
     char y;
     Brick(){}
     ~Brick(){}
     int get_shape() const
     {
        return shapeList[kind][direction];
     }
     void random_set_brick()
     {
        direction=rand()%4;
        kind=rand()%7;
        x=start_x_position;
        y=start_y_position;
     }
}; 