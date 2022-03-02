#include <iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a,b,c;
   c=n%10;
   b=(n/10)%10;
   a=(n/100)%10;
   if(n==(a*a*a+b*b*b+c*c*c))  cout<<"yes"<<endl;
   else     cout<<"no"<<endl;
    
    system("pause");
    return 0;
}