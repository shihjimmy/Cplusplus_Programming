#include<iostream>
using namespace std;

int a,b,c,d,e,f;
int x0,y0,i,j;
int recurrence_x(int,int,int);
int recurrence_y(int,int,int);
int main()
{   
 
    cin>>a>>b>>c>>d>>e>>f;
    cin>>x0>>y0>>i>>j;
    cout<<recurrence_x(x0,y0,i)<<" "<<recurrence_y(x0,y0,j)<<endl;


    return 0;
}
int recurrence_x(int x0,int y0,int i)
{
    if(i==0) return x0;
    else if(i>=1)
    {
        return a*recurrence_x(x0,y0,i-1)+b*recurrence_y(x0,y0,i-1)+c*i;
    }
}
int recurrence_y(int x0,int y0,int j)
{
    if(j==0) return y0;
    else if(j>=1)
    {
       return d*(e-recurrence_y(x0,y0,j-1))+f*recurrence_x(x0,y0,j-1);
    }
}