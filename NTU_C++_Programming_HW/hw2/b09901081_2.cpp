#include<iostream>
using namespace std;

int main()
{   
   int v1x,v1y,v1z,v2x,v2y,v2z,a;
   cin>>v1x>>v1y>>v1z>>v2x>>v2y>>v2z>>a;
   cout<<v1x+v2x<<" "<<v1y+v2y<<" "<<v1z+v2z<<endl;
   cout<<a*v1x<<" "<<a*v1y<<" "<<a*v1z<<endl;
   cout<<a*v2x<<" "<<a*v2y<<" "<<a*v2z<<endl;
   cout<<v1x*v2x+v1y*v2y+v1z*v2z<<endl;
   cout<<v1y*v2z-v1z*v2y<<" "<<v1z*v2x-v1x*v2z<<" "<<v1x*v2y-v1y*v2x<<endl;






    system("pause");
    return 0;
}