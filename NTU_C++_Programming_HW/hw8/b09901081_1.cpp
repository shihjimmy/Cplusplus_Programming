#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool palindrome(vector<char>&s);
vector<char>s;

int main()
{   
   
    string s1;
    getline(cin,s1);
    for(int i=0;i<s1.length();i++)
    {
       if(s1[i]!=' ') 
       s.push_back(s1[i]);
    }
    if(palindrome(s)) cout<<"true";
    else cout<<"false";

    return 0;
}
bool palindrome(vector<char>&s)
{  
    for(int i=0;i<s.size();i++)
    {  
      if((s[i]=='{'&&s[s.size()-1-i]!='}')||(s[i]!='{'&&s[s.size()-1-i]=='}')) return false;
      else if((s[i]=='('&&s[s.size()-1-i]!=')')||(s[i]!='('&&s[s.size()-1-i]==')')) return false;
      else if((s[i]=='['&&s[s.size()-1-i]!=']')||(s[i]!='['&&s[s.size()-1-i]==']')) return false;
      else if((s[i]=='/'&&s[s.size()-1-i]!='\\')||(s[i]!='/'&&s[s.size()-1-i]=='\\')) return false;
      else if((s[i]=='\\'&&s[s.size()-1-i]!='/')||(s[i]!='\\'&&s[s.size()-1-i]=='/')) return false;
      else if(s[i]!=s[s.size()-1-i]) return false;
      else       return true;
    }
}
    