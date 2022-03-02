#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{   
    string color[7]={"red","orange","yellow","green","blue","indigo","violet"};
    float w,h,vx,vy;
    float t;
    cin>>w>>h>>vx>>vy>>t;
    int num=0;
    float tx=w/vx,ty=h/vy;
    int x=t/tx,y=t/ty;
    num=(x+y)%7;
    cout<<color[num]<<endl;

    system("pause");
    return 0;
}
