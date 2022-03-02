#include <iostream>
using namespace std;

int main()
{   
   int year;
   cin>>year;
   if(year%4==0)
   {
       if(year%100==0) 
       {
           if(year%400==0)  cout<<"leap year"<<endl;
           else             cout<<"common year"<<endl;
       }
       else cout<<"leap year"<<endl;
   }
   else cout<<"common year"<<endl;

    system("pause");
    return 0;
}