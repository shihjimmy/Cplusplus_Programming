#include <iostream>
#include <iomanip>
using namespace std;
int main()
{   
    int c;
    cin>>c;
    float f;
    f=1.8*c+32;
    cout<<fixed<<setprecision(2)<<f<<endl;

    system("pause");
    return 0;
}