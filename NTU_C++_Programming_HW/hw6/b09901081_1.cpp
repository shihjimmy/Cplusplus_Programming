#include <iostream>
using namespace std;

int recurrence(int,int,int,int,int,int);

int main(){
    int a,b,c,x0,x1,n;
    cin>>a>>b>>c>>x0>>x1>>n;
    cout<<recurrence(a,b,c,x0,x1,n)<<endl;


    return 0;
}
int recurrence(int a,int b, int c,int x0,int x1,int n)
{
    if(n==0) return x0;
    else if (n==1) return x1;
    else if(n>=2) 
    {
       return a*recurrence(a,b,c,x0,x1,n-1)+b*recurrence(a,b,c,x0,x1,n-2)+c;
    }
}