#include<iostream>
using namespace std;

int chess[8][8];
int x,y;
void printchess(int queensolution[])
{   
    for(int i=0;i<8;i++)
    {  
        int k=queensolution[i];
        for(int j=0;j<8;j++)
        {
           if(j==k)
           cout<<"Q"<<" ";
           else
           cout<<"#"<<" ";
        }
        cout<<endl;
    }
}
bool check(int x,int y,int queensolution[])
{
    if(queensolution[x]==y)
    return true;
    else
    return false;
}
void placequeen(int i,int queensolution[])
{
   if(i==8)
   {   
       if(check(x,y,queensolution))
       {
        printchess(queensolution);
        cout<<endl;
       }
      
       return;
   } 
  for(int k=0;k<8;k++)
  {   
      bool conflict=false;
      queensolution[i]=k;
      for(int j=0;j<i&&(!conflict);j++)
      {
          if(queensolution[j]==k||abs(queensolution[j]-queensolution[i])==abs(i-j))
          conflict=true;
      }
      if(!conflict)
      { 
          queensolution[i]=k;
          placequeen(i+1,queensolution);
      }
  }
}

int main()
{   
   cin>>x>>y;
   int queensolution[8];
   placequeen(0,queensolution);

    return 0;
}