#include<iostream>
#include<string>
using namespace std;

string s[100];
string visit;
int n;
void permutation(string s[],string visit,int x)
{
   if(x==n)
   {
       for(int i=0;i<n;i++)
       {
           cout<<s[i]<<" ";
       }
       cout<<endl;
       return;
   }
   else if(x>=n) return;
   for(int i=0;i<n;i++)
   {  
      if(visit[i]=='0')
      {
          visit[i]='1';
          s[x]=to_string(i+1);
          permutation(s,visit,x+1);
          visit[i]='0';
      }
   }
}

int main()
{  
    cin>>n;
    for(int i=0;i<100;i++)
    {
        visit.push_back('0');
    }
    permutation(s,visit,0);

   
    return 0;
}