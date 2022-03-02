#include<iostream>
#include"3a.cpp"
using namespace std;

double mean,var;
void testRandomPermArray(int n, double p, double& mean, double& var)
{
    int test[10000];
    for(int i=0;i<10000*p;i++)
    {
        test[i]=1;
    }
    for(int i=10000*p;i<10000;i++)
    {
        test[i]=0;
    }
    double time1[10000]={0};
    for(int i=0;i<n;i++)
    {
       randomPermArray(test,10000);
       for(int i=0;i<10000;i++)
       {
           if(test[i]==1) 
           {
               time1[i]++;
           }
       }
    }
    for(int i=0;i<10000;i++)
    {
      time1[i]/=n;
    }
    double sum=0;
    for(int i=0;i<10000;i++)
    {
        sum+=time1[i];
    }
    mean=sum/10000;
    double sum2=0;
    for(int i=0;i<10000;i++)
    {
       sum2+=(time1[i]-mean)*(time1[i]-mean);
    }
    var=sum2/10000;
}
