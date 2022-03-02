#include<iostream>
#include<string>
#include<vector>
#include<memory.h> 
using namespace std;

string s;
int start=0,final=0,time=0,first=0,time2=0;
bool checkC[500],checkV[500],checkS=false,checkL[500],checkR[500];
bool cursor[500];
int ltime=0,rtime=0;
vector<char>v2;
vector<char>copyleft;
vector<char>v2left;
void Sscapital(int start,int final)
{  
    for(int i=start;i<=final;i++)
    {
        if(s[i]!='\\'&&s[i-1]!='\\'&&s[i]!=' ') 
        s[i]=s[i]-'a'+'A';
    }
}
void Lrecord(bool checkL[],int bstart,int bfinal)
{   
    time=0;
    for(int i=bstart;i<=bfinal;i++)
    {
       if(checkL[i])
       {
          time++;
       }
    }
}
void Rrecord(bool checkR[],int bstart,int bfinal)
{
   time2=0;
   for(int i=bstart;i<=bfinal;i++)
   {
     if(checkR[i])
     {
       time2++;
     }
   }
}
void cursormoveL(vector<char>&v2)
{
   cursor[v2.size()-1-ltime]=0;
   cursor[v2.size()-1-ltime-1]=1;
   ltime++;
}
void cursormoveR(vector<char>&v2,bool cursor[])
{ 
     int k=0;
     for(int i=0;i<500;i++)
     {
       if(cursor[i]) k=i;
     } 
     cursor[k]=0;
     cursor[k+1]=1;
}
void texteditor(vector<char>&v2,string s)
{  
   for(int i=0;i<s.length();i++)
   {
       if(s[i-1]=='\\')
       {   
           switch(s[i])
           {
               case 'b':
               {
                 v2.pop_back();
                 break;
               }
               case 'n':
               {
                 cout<<endl;
                 break;
               }
               case 'S':
               {
                 start=i;
                 checkS=true;
                 break;
               }
               case 's':
               {
                 checkS=false;
                 final=i;
                 break;
               }
               case 'l':
               {
                 checkL[i]=true;
                 cursormoveL(v2);
                 break;
               }
               case 'r':
               {
                 checkR[i]=true;
                 cursormoveR(v2,cursor);
                 break;
               }
               case 'c':
               {
                 checkC[i]=true;
                 break;
               }
               case 'v':
               {
                 checkV[i]=true;
                 break;
               }
           }
           if(start!=0&&final!=0)
           {   
               v2left.clear();
               copyleft.clear();
               Sscapital(start,final);
               Lrecord(checkL,start,final);
               Rrecord(checkR,start,final);
               for(int i=first;i<=time;i++)
               {
                   v2left.push_back(v2[i]);
               }
                   first+=time;
               if(checkC[i])
               {
                   for(int i=0;i<v2left.size();i++)
                  {
                      copyleft.push_back(v2left[i]);
                  }
               } 
           }
           if(checkV[i])
           {
              for(int i=0;i<copyleft.size();i++)
              {
                  v2.push_back(copyleft[i]);
              }
           }
       }
       else if(s[i]!='\\'&&s[i-1]!='\\')
       {
          v2.push_back(s[i]);
       }
   }
}
void printarray(vector<char>&v2)
{
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i];
    }
}

int main()
{   
   memset(checkL,0,500);
   memset(checkC,0,500);
   memset(checkR,0,500);
   memset(checkV,0,500);
   memset(cursor,0,500);
   getline(cin,s);
   texteditor(v2,s);
   printarray(v2);

    return 0;
}



