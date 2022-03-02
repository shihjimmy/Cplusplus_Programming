#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string s1;
    getline(cin,s1);
    for(int i=0;i<s1.length();i++)
    {
       if(s1[i]!=' ')
       {
            if(((int)s1[i]+n)>'z') 
           {  
            int k=(int)s1[i]+n;
            k=k-(int)'z'+(int)'a'-1;
            s1[i]=char(k);
           }
           else if(((int)s1[i]+n)<'a')
           {
            int k=(int)s1[i]+n;
            k=k+(int)'z'-(int)'a'+1;
            s1[i]=char(k);
           }
           else
           {
             s1[i]=char((int)s1[i]+n);
           }    
       }
    }
    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i];
    }
    
    system("pause");
    return 0;
}
