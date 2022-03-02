#include<iostream>
using namespace std;

int main()
{   
    int size;
    cin>>size;
    int *num=new int[size];
    int *time=new int[size];
    for(int i=0;i<size;i++)
    {
        *(time+i)=0;
    }
    for(int i=0;i<size;i++)
    {
        cin>>*(num+i);
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(num[i]==num[j])
            time[i]++;
        }
    }
    for(int i=0;i<size;i++)
    {   
        if(time[i]==1)
        cout<<num[i]<<endl;
    }
    delete []num;

    return 0;
}