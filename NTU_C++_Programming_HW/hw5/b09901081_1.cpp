#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void rational(unsigned int nu,unsigned int de)
{   
    vector<int>num;
    num.clear();
    unsigned int a=nu,b=de;
    if(a==b) 
    {
        cout<<1<<endl;
        return ;
    }
    else if(a==0) 
    {
        cout<<0<<endl;
        return;
    }
    else 
    {
       do
       {
          num.push_back(a/b);
          a=a-(a/b)*b;
          swap(a,b);
          if(a%b==0)
          {
              num.push_back(a/b);
              break;
          }
       } while (a%b!=0);
       for(int i=0;i<num.size();i++)
       {   
           if(num[i]==0&&i!=0) break;
           cout<<num[i]<<" ";
       }
       cout<<endl;
    }
}
void real(long double x,unsigned int n)
{
    vector<int>num;
    num.clear();
    num.push_back((unsigned int)x);
    if(n==1) cout<<(unsigned int)x<<endl;
    else
    {   
       n--;
       while(n--)
       {
           x-=(unsigned int)x;
           x=(1.0/x);
           num.push_back((unsigned int)(x));
       }
        for(int i=0;i<num.size();i++)
       {
           cout<<num[i]<<" ";
       }
       cout<<endl;
    }
}

int main()
{
    unsigned int a,b;
    cin>>a>>b;
    rational(a,b);
    long double x;
    unsigned int n;
    cin>>x>>n;
    real(x,n);

    
    return 0;
}
