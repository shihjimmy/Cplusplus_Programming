#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#define EPSILON 0.00000000000001
using namespace std;

double function(double x)
{
   return (exp(x)-(x*x*x));
}
double line(double left,double right)
{  
   if(right!=left)
   {
   double m=(function(right)-function(left)/(right-left));
   left=-(function(left)/m)+left;
   return left;
   }
}
double bisection(double left,double right)
{   
    double a,b,c;
    do
     {  
       a=abs(function(left)-0);
       if(a<=EPSILON) return left;
       b=abs(function(right)-0);
       if(b<=EPSILON) return right;
       c=function((left+right)/2);
       if(a*c>0)
       {
          left=(left+right)/2;
          right=right;
       }
       else if(a*c<0)
       {
          right=(right+left)/2;
          left=left;
       }
    }
    while(a>EPSILON&&b>EPSILON);
 
}
double false_position(double left,double right)
{
    double a,b;
    do
    {
       a=abs(function(left)-0);
       if(a<=EPSILON) return left;
       b=abs(function(right)-0);
       if(b<=EPSILON) return right;
       right=right;
       left=line(left,right);
    }
    while(a>EPSILON&&b>EPSILON);
   
}

int main()
{   
    cout<<fixed<<setprecision(13)<<bisection(0,4)<<endl;
    cout<<fixed<<setprecision(13)<<false_position(0,4)<<endl;


    return 0;
}
