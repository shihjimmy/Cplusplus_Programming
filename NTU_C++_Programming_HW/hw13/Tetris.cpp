#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h>
#include "Brick.cpp"

using namespace std;

HANDLE hStdOut;
int score = 0;
bool is_update_score= false;

void print_content(COORD coord, std::string str);

void print_brick(const Brick &target, std::string printChar, short x, short y);

void show_background(COORD coord);


void read_input();

void start();

void clear_line();

bool is_feasible(const Brick &target);


void fixed_position(const Brick &target);

bool move(Brick &A, char XOffset, char YOffset);


bool rotate(Brick &A);




bool is_update_brick_region = true;                
bool is_update_background = true;              
bool is_game_over      = false;            
int background[backgroud_x_length+100][backgroud_y_length] = {0};
int  speed = 400;


Brick thisBrick, nextBrick;

void gameover()
{  
   for(int i=0;i<backgroud_x_length;i++)
   {
   	   if(background[i][0]==1)
   	   {  
          if(background[i][1]==1)
   	   	    is_game_over=true;
   	   }
   }
}

void clear_line()
{
	/* TO DO */
	while(true){

		bool check=true;
		for(int i=backgroud_y_length-1;i>=0;i--)
		{
			for(int j=0;j<backgroud_x_length;j++)
			{	
				
				if(background[j][i]!=1) check=false;
			}
			if(check)
			{
			
				for(int j=0;j<backgroud_x_length;j++)
				{
					if(background[j][i]==1)
					{  
					// if(i!=backgroud_y_length-1)
					//     background[j][i+1]=1;
					background[j][i]=0;

					is_update_background = true;
					}

				}

			int row = i;

				for (int i = row; i >=0; i--)
				{
					for (int j = 0; j<backgroud_x_length; j++)
					{
						int temp = 0;
						temp = background[j][i];
						if((i==0)){
							break;
						}
						background[j][i] = background[j][i-1];
						is_update_background = true;
					}
					
				}
			}
			else check=true;
		}
		is_update_background = true;
		int proceed = 1;

		for (int i = backgroud_y_length; i >=0; i--)
		{
			int count = 0;
			for (int j = 0; j <backgroud_x_length; j++)
			{
				if (background[j][i]==1)
				{
					count += 1;
			//		cout<<"""count is"<<count<<endl;
				}
			}

			if (count == 7)
			{
				break;
			}
			if (i == 0 && count!= 7)
			{
				proceed = 0;
			}
		}

		if (proceed  == 0)
		{
			break;
		}

	}
}

bool is_feasible(const Brick &target)
{   
	/*
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(target.get_shape() & (0x8000 >> (i*4 + j)))
			{

                 if(target.x+j<0 || target.x+j>=backgroud_x_length || target.y+i>=backgroud_y_length )
                 {
                            return false;
                 }
                 if( background[target.x+j][target.y+i]==1 )
                 {
                 	        return false;
                 }
                
			}
		}
	}
	return true;
	*/
    int num=target.get_shape();
    int a=0;
    for(int i=target.y+3;i>=target.y;i--)
    {
    	for(int j=target.x+3;j>=target.x;j--)
    	{   
    		a = num%2;
    		num = num/2;
    		if(a==1)
    		{
    		   if(background[j][i]==1)
    			  return false;
    		   if (i>=16 || j>6 || j<0) 
    		      return false;
    	    }
    	}
    }
    return true;
}
  
void fixed_position(const Brick &target)
{
    for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{

			if(target.x+j<0 || target.x+j>=backgroud_x_length || target.y+i>=backgroud_y_length )
             {
                     continue;
             }
			if(target.get_shape() & (0x8000 >> (i*4 + j)))
			{

                background[target.x+j][target.y+i]=1;    
			}
		}
	}
	/*
	int num=target.get_shape();
    int a=0;
    for(int i=target.y+3;i>=target.y;i--)
    {
    	for(int j=target.x+3;j>=target.x;j--)
    	{   
    		a = num%2;
    		num = num/2;
    		background[j][i]=a;
    	}
    }
    */
}

bool move(Brick &A, char XOffset, char YOffset)
{   
	char oldX = A.x, oldY = A.y;
	print_brick(A, "  ",0,0);
	A.x += XOffset, A.y += YOffset;
	if(!is_feasible(A))
	{
	    /* TO DO */
	    A.x=oldX;
	    A.y=oldY;
	    print_brick(A, "#",0,0);
	    if(YOffset>0)   //cannot move downward,which means it is time to stop
	    {
	    	fixed_position(A);
    		clear_line();
    		gameover();
	    	A=nextBrick;
	    	is_update_brick_region=true;
	    }
		return false;
	}
	print_brick(A, "#",0,0);
	return true;
}

bool rotate(Brick &A)
{
	/* TO DO */
    int newdir=rand()%4;
    int odddir=A.direction;
    print_brick(A, "  ",0,0);
    A.direction=newdir;
    if(is_feasible(A))
    {
       print_brick(A, "#",0,0);
       return true;
    }
    else 
    {
    	A.direction=odddir;
    	print_brick(A, "  ",0,0);
    	return false;
    }
}

void restart()
{
	for(int i = 0; i < backgroud_x_length; ++i)
		for(int j = 0; j < backgroud_y_length; ++j)
			background[i][j] = 0;
	is_update_background     = true;
	thisBrick.random_set_brick();
	is_update_brick_region = true;
	speed = 500;
	is_game_over = false;
	score = 0;
	print_content({30, 5}, "Score:");
	printf("%d",score);
}

void print_content(COORD coord, std::string str)
{
	SetConsoleCursorPosition(hStdOut, coord);
	WriteConsole(hStdOut, str.c_str(), str.length(), NULL, NULL);
}


void print_brick(const Brick &target, std::string printChar, short x, short y)
{
	short posX = x? x : target.x * 2 + 2;  
	                                   
	short posY = y? y:target.y;
	
	for(short YOffset = 0; YOffset < 4; ++YOffset)
	{
		for(short XOffset = 0; XOffset < 4; ++XOffset)
		{

			if(posX + XOffset < 0 || posY + YOffset < 0)
				continue;
				
			if(target.get_shape() & (0x8000 >> (YOffset*4 + XOffset)))
				print_content({(short)(posX + XOffset*2),(short)(posY + YOffset)}, printChar);
		}
	}
}

void show_background(short _x, short _y)
{   int j = 0;
	for(short x = 0; x <= backgroud_x_length+1; ++x)
	{
		print_content({(short)(_x + x*2), (short)(_y + backgroud_y_length)},"");
		printf("%d",j);
		j++;
	}
	int i = 0;
	for(short y = 0; y < backgroud_y_length; ++y)
	{
		print_content({_x, (short)(_y + y)},"");
		
		if(i>=10){
		printf("%d",i);}
		else{
		printf("0%d",i);	
		}
		
		print_content({(short)(_x + backgroud_x_length * 2 + 2), (short)(_y + y)}, "");
		if(i>=10){
		printf("%d",i);}
		else{
		printf("0%d",i);	
		}
		i++;
		
		for(short x = 0; x < backgroud_x_length; ++x)
		{
			print_content({(short)(_x + 2 + x*2), (short)(_y + y)}, (background[x][y] ? "#" :" "));
		}
	}
}

void read_input()
{
	char tempPos = 0;
	switch(getch())
	{
	case 'o':
	case 'O':
		rotate(thisBrick);
		break;
	case 'i':
	case 'I':
		move(thisBrick, -1, 0);
		break;
	case 'p':
	case 'P':
		move(thisBrick, 1, 0);
		break;
	case 'j':
	case 'J':
		move(thisBrick, 0, 1);
		break;
	case ' ':
		while(move(thisBrick, 0, 1));
		break;
	case 'r':
	case 'R':
		restart();
		break;
	case 'q':
	case 'Q':
		exit(1);
		break;
	}
}

void start()
{
	thisBrick.random_set_brick();
	nextBrick.random_set_brick(); 
	system("cls");
	
	print_content({30, 6}, "O: Rotate");
	print_content({30, 7}, "J: Down");
	print_content({30, 8}, "I: Left P: Right");
	print_content({30, 10}, "                 ");
	print_content({30, 11},"SPACE: Drop");
	print_content({30, 13},"R: Restart ");
	print_content({30, 14},"Q: Exit");
	
	while(!is_game_over)
	{
		if(is_update_background)
		{
			show_background(0, 0);
			is_update_background = false;
		}
		if(is_update_brick_region)
		{
			print_content({30, 0}, "NEXT:");
			print_content({30, 5}, "Score:");
		    printf("%d",score);
			print_brick(nextBrick,"  ", 30, 1);
			nextBrick.random_set_brick();
			print_brick(nextBrick, "#", 30, 1);
			is_update_brick_region = false;
		}
		
		print_brick(thisBrick, "#", 0,0);
		
		move(thisBrick, 0, 1);
		
		while(kbhit())
			read_input();
		
		if(is_game_over)
		{
			print_content({6, 10}, "Game Over~");
			print_content({4, 11}, "Restart: Type S");
			char ch = getch();
			if(ch == 's' || ch == 'S')
				restart();
		}
	
		Sleep(speed);
	}
}
