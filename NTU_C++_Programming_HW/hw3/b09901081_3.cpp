#include <iostream>
using namespace std;

int main()
{  
   int x1,y1,x2,y2,x3,y3,x4,y4;
   int k=0;
   cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
   if(x1>x2)
   {
       int num=0;
       num=x1;
       x1=x2;
       x2=num;
   }
   if(y1>y2)
   {
       int num2=0;
       num2=y1;
       y1=y2;
       y2=num2;
   } 
   if(x3>x4)
   {
       int num3=0;
       num3=x3;
       x3=x4;
       x4=num3;
   }
   if(y3>y4)
   {
       int num4=0;
       num4=y3;
       y3=y4;
       y4=num4;
   }
   for(int i=x3;i<=x4;i++)
   {   
       for(int j=y3;j<=y4;j++)
       {
           if(i<x2&&i>x1&&j<y2&&j>y1)  k++;
       }
   }
   if(k!=0) cout<<"overlap"<<endl;
   else     cout<<"no overlap"<<endl;

    system("pause");
    return 0;
}