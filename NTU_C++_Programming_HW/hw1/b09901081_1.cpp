#include <iostream>
#include <iomanip>
using namespace std;
int main()
{   
    float weight,height,bmi;
    cin>>weight>>height;
    height/=100;
    bmi=weight/(height*height);
    cout<<fixed<<setprecision(1)<<bmi<<endl;

    system("pause");
    return 0;
}