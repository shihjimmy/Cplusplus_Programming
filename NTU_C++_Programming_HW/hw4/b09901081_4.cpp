#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long int pow1(long long int a,int b)
{
   long long int sum2=1;
   if(b==0) 
     return 1;
   else
   {
      for(int i=0;i<b;i++)
    {
      sum2*=a;
    }
     return sum2;
   } 
}

int main()
{   
   int n1,n2;
   cin>>n1>>n2;
   cin.ignore();
   string str1;
   cin>>str1;
   vector<long long int>vecstr;
   int k=0;
   long long int sum=0;
   for(long long int i=str1.length()-1;i>=0;i--)
   {    
      if(str1[i]>='0'&&str1[i]<='9')
      {
         sum+=((long long int)str1[i]-'0')*pow1(n1,k);
         k++;
      }
      else if(str1[i]>='A'&&str1[i]<='Z')
      {
         sum+=((long long int)str1[i]-'0'-7)*pow1(n1,k);
         k++;
      }
      else if(str1[i]>='a'&&str1[i]<='z')
      {
         sum+=((long long int)str1[i]-'0'-13)*pow1(n1,k);
         k++;
      }
   }

   while(sum)
   {
      vecstr.push_back(sum%n2);
      sum/=n2; 
   }
   
   for(long long int i=vecstr.size()-1;i>=0;i--)
   {   
       if(vecstr[i]>=10&&vecstr[i]<=35)
          cout<<(char)(vecstr[i]-10+(int)'A');
       else if(vecstr[i]>=36&&vecstr[i]<=61)
          cout<<(char)(vecstr[i]-36+(int)'a');
       else if(vecstr[i]>=0&&vecstr[i]<=9)
          cout<<(char)(vecstr[i]+(int)'0');     
   }

    system("pause");
    return 0;
}
