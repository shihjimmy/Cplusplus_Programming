#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int a,b,c,d,x,y,z;
    cin>>a>>b>>c>>d;
    cin>>x>>y>>z;
    float root;
    root=sqrt(a*a+b*b+c*c);
    int t;
    float result;
    t=abs(a*x+b*y+c*z+d);
    result=t/root;
    cout<<static_cast<int>(result*100)/100.0;

     system ("pause");
     return 0;
}