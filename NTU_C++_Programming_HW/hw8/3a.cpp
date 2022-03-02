#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

void swap(int*a,int*b)
{
   int temp=*a;
   *a=*b;
   *b=temp; 
}
void randomPermArray(int data[], int n)
{  
   for(int i=n-1;i>=0;i--)
   {
       int j=rand()%n;
       swap(data[i],data[j]);
   }
}