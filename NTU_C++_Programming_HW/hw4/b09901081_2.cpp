#include <iostream>
#include <vector>
using namespace std;

int main()
{   
   vector<int>divisors;
   int num;
   int sum=0;
   cin>>num;
   for(int i=1;i<num;i++)
   {
       if(num%i==0)
       {
           divisors.push_back(i);
       }
   }
   for(int i=0;i<divisors.size();i++)
   {
       sum+=divisors[i];
   }
   if(sum==num) cout<<"perfect number"<<endl;
   else         cout<<"imperfect number"<<endl;

    system("pause");
    return 0;
}
