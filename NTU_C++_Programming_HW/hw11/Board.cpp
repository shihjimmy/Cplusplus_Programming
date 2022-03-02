#include "Board.h"
#include <iostream>
#include <ctime>
using namespace std;

int flag=0;
Board::Board()
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                tiles[i][j]=' ';
            }
        }
        flag=1;
        newTile();
        newTile();
        flag=0;
    }
void Board::displayBoard()
    {
        for(int i=0;i<4;i++)
        {
            cout<<"+---";
        }
            cout<<"+"<<endl;
        for(int j=0;j<4;j++)
        {
            for(int i=0;i<4;i++)
           {  
               cout<<"| "<<tiles[j][i]<<" ";
           }
               cout<<"|"<<endl;
            for(int i=0;i<4;i++)
           {
               cout<<"+---";
           }
               cout<<"+"<<endl;
        }     
    }
void Board::newTile()
    {
        srand((unsigned)time(NULL));
        int x=0,y=0,num=0;
        while(1)
        {    
            x=rand()%4;
            y=rand()%4;
            if(flag==0) 
              num=rand()%3;
            else if(flag==1)
              num=0;
            if(tiles[x][y]==' ')
            {
                if(num==0) tiles[x][y]='A';
                else if(num==1) tiles[x][y]='B';
                else if(num==2) tiles[x][y]='C';
                return ;
            }
            else if(tiles[x][y]!=' ') continue;
        }        
    }
int Board::convert(char a)
{
    int p=(int)a-'A';
    int result=1;
    for(int i=0;i<=p;i++)
    {
        result=result*2;
    }
        return result;
}
int Board::moveSingleLine(char line[4],char new_line[4])
{   
    int num2=0;
    for(int i=0;i<4;i++)
    {
        if(line[i]!=' ')
        {
            for(int j=i+1;j<4&&i+1<4;j++)
          {
            if(line[j]==' ') continue;
            else
            {
                if(line[i]==line[j])
                {
                    line[i]=char((int)line[i]+1);
                    num2+=convert(line[i]);
                    line[j]=' ';
                    break;
                }
                else break;
            }
          }
        }
    }
    int num=0;
    for(int i=0;i<4;i++)
    {
        if(line[i]!=' ') num++;
    }
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(line[j]!=' ')
            {
                new_line[i]=line[j];
                line[j]=' ';
                break;
            }
        }
    }
    int a=4-num;
    for(int i=0;i<a;i++)
    {
       new_line[num+i]=' ';
    }
    return num2;
}
bool Board::check(char a[][4],char b[][4])
{
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             if(a[i][j]==b[i][j]) continue;
             else 
             {
                 return false;
             }
         }
     }
        return true;
}
int Board::moveBoard(Direction dir)
 {   
     char copy[4][4];
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             copy[i][j]=tiles[i][j];
         }
     }
     if(dir==LEFT)
     {   
         int score=0;
         for(int i=0;i<4;i++)
         {
             char line[4];
             char new_line[4];
             for(int j=0;j<4;j++)
             {
                 line[j]=tiles[i][j];
             }
             score+=moveSingleLine(line,new_line);
             for(int t=0;t<4;t++)
             {
                 tiles[i][t]=new_line[t];
             }
         }
         if(!check(copy,tiles))  newTile();
         return score;
     }
     else if(dir==RIGHT)
     {
        int score=0;
        for(int i=0;i<4;i++)
        {
             char line[4];
             char new_line[4];
             int k=0;
             for(int j=3;j>=0;j--)
             {
                 line[k]=tiles[i][j];
                 k++;
             }
             score+=moveSingleLine(line,new_line);
             int k2=0;
             for(int t=3;t>=0;t--)
             {
                 tiles[i][t]=new_line[k2];
                 k2++;
             }
        }
        if(!check(copy,tiles))  newTile();
             return score;
     }
     else if(dir==UP)
     {
         int score=0;
         for(int i=0;i<4;i++)
         {
             char line[4];
             char new_line[4];
             for(int j=0;j<4;j++)
             {
                 line[j]=tiles[j][i];
             }
             score+=moveSingleLine(line,new_line);
             for(int t=0;t<4;t++)
             {
                 tiles[t][i]=new_line[t];
             }
         }
         if(!check(copy,tiles))  newTile();
             return score;
     }
     else if(dir==DOWN)
     {
         int score=0;
         for(int i=0;i<4;i++)
         {
            char line[4];
            char new_line[4];
            int k=0;
            for(int j=3;j>=0;j--)
            { 
               line[k]=tiles[j][i];
               k++; 
            }
            score+=moveSingleLine(line,new_line);
            int k2=0;
            for(int t=3;t>=0;t--)
            {
               tiles[t][i]=new_line[k2];
               k2++;
            }
         }
         if(!check(copy,tiles))  newTile();
               return score;
     }
 }
int Board::movecopy(Direction dir)
{
     if(dir==LEFT)
     {   
         int score=0;
         for(int i=0;i<4;i++)
         {
             char line[4];
             char new_line[4];
             for(int j=0;j<4;j++)
             {
                 line[j]=tiles[i][j];
             }
             score+=moveSingleLine(line,new_line);
         }
         return score;
     }
     else if(dir==RIGHT)
     {
        int score=0;
        for(int i=0;i<4;i++)
        {
             char line[4];
             char new_line[4];
             int k=0;
             for(int j=3;j>=0;j--)
             {
                 line[k]=tiles[i][j];
                 k++;
             }
             score+=moveSingleLine(line,new_line);
        }
             return score;
     }
     else if(dir==UP)
     {
         int score=0;
         for(int i=0;i<4;i++)
         {
             char line[4];
             char new_line[4];
             for(int j=0;j<4;j++)
             {
                 line[j]=tiles[j][i];
             }
             score+=moveSingleLine(line,new_line);
         }
             return score;
     }
     else if(dir==DOWN)
     {
         int score=0;
         for(int i=0;i<4;i++)
         {
            char line[4];
            char new_line[4];
            int k=0;
            for(int j=3;j>=0;j--)
            { 
               line[k]=tiles[j][i];
               k++; 
            }
            score+=moveSingleLine(line,new_line);
         }
               return score;
     }
}
bool Board::checkGameOver()
{     
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             if(tiles[i][j]==' ')
             {
                 return false;
             }
         }
     }
     int check=0;
     check=movecopy(UP)+movecopy(DOWN)+movecopy(LEFT)+movecopy(RIGHT);
     if(check==0)
     {
         if(flag==0)
           displayBoard();
      return true;
     }
     else 
      return false;
}
