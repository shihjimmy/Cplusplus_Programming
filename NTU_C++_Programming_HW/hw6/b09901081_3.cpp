#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int n,money,t=0;
int time2=0;
long long int value[1000000]={0};
vector<int>s;
set<int>visit;

int pow(int a,int b)
{
   int sum=1;
   for(int i=0;i<b;i++)
   {
      sum*=a;
   }
   return sum;
}
bool compare(int a,int b)
{  
    return a>b;
}
int _sort(vector<int>s)
{  
   sort(s.begin(),s.end(),compare);
   int mag=0;
   int k=0;
   for(int i=s.size()-1;i>=0;i--)
   {  
      mag+=(s[i])*pow(10,k);
      k++;
   }
   return mag;
}
bool check(vector<int>s)
{  
   bool k=true;
   for(int i=0;i<s.size()-1;i++)
   {
      if(s[i]<s[i+1])
      k=false;
   }
   return k;
}


void change(vector<int>s,int x)
{   
   if((x==money))//&&visit.find(_sort(s))==visit.end())
   {   
      time2++;
      //visit.insert(_sort(s));
      for(int i=0;i<s.size();i++)
      {  
         cout<<s[i]<<" ";
      }
      s.clear();
      cout<<endl;
      return;
   }
   else if(x>money) return;
   for(int i=0;i<n;i++)
   {     
       s.push_back(value[i]);
       if(check(s))
       {
         change(s,x+value[i]);
       }
       s.pop_back();
   }
}

int main()
{   
   cin>>n>>money;
   for(int i=n-1;i>=0;i--)
   {
      cin>>value[i];
   }
   change(s,0);
   cout<<time2<<endl;

    return 0;
}