#include<iostream>
#include<string>
using namespace std;

int MAXnum(int a,int b)
{
    if(a>b) return a;
    else if(b>a) return b;
    else if(a==b) return a;
}
void reset(int num1[],int num2[],int ans[],int size)
{
    for(int i=0;i<size;i++)
    {
        num1[i]=0;
        num2[i]=0; 
        ans[i]=0;
    }
    return;
}
void setnumber(string s1,string s2,int num1[],int num2[])
{
   int t1=0,t2=0;
   for(int i=s1.length()-1;i>=0;i--)
   {
       num1[t1]=(int)s1[i]-'0';
       t1++;
   }
   for(int i=s2.length()-1;i>=0;i--)
   {
       num2[t2]=(int)s2[i]-'0';
       t2++;
   }
   return;
}
void printarray(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
       cout<<endl;
}
int judge(string s1,string s2)
{  
   int len1=s1.length();
   int len2=s2.length();
   if(len1>len2) return 1;
   else if(len1==len2)
   {
       for(int i=0;i<=len2-1;i++)
       {
           if(s1[i]==s2[i]) continue;
           else if(s1[i]>s2[i]) return 1;
           else if(s1[i]<s2[i]) return -1;
       }
   }
   else if(len1<len2) return -1;
}
bool samestr(string s1,string s2)
{   
    if(s1.length()==s2.length())
    {
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[i]) continue;
            else return false;
        }
           return true;
    }
    else return false;
}
string add(string s1,string s2)
{   
    int a=s1.length(),b=s2.length();
    int *num1=new int[MAXnum(a,b)+1];
    int *num2=new int[MAXnum(a,b)+1];
    int *ans=new int[MAXnum(a,b)+1];
    reset(num1,num2,ans,MAXnum(a,b)+1);
    setnumber(s1,s2,num1,num2);
    string str;
    str.clear();
    int carry=0;
    for(int i=0;i<MAXnum(a,b)+1;i++)
    {     
        ans[i]=num1[i]+num2[i]+carry;
        if(ans[i]>=10)
        {
            carry=1;
            ans[i]-=10;
        }
        else carry=0;
    }
    int pos=0;
    for(int i=MAXnum(a,b);i>=0;i--)
    {   
        if(ans[i]!=0)
        {
           pos=i;
           break;
        }
    }
    for(int i=pos;i>=0;i--)
    {   
        str.push_back((char)ans[i]+'0');
    }
     delete []num1;
     delete []num2;
     delete []ans;

     return str; 
}
string multiply(string s1,string s2)
{  
    int a=s1.length(),b=s2.length();
    int *num3=new int[a];
    int *num4=new int[b];
    int *ans2=new int[2*MAXnum(a,b)];
    for(int i=0;i<2*MAXnum(a,b);i++)
    {
        ans2[i]=0;
    }
   int t1=0,t2=0;
   for(int i=s1.length()-1;i>=0;i--)
   {
       num3[t1]=(int)s1[i]-'0';
       t1++;
   }
   for(int i=s2.length()-1;i>=0;i--)
   {
       num4[t2]=(int)s2[i]-'0';
       t2++;
   }
    string str;
    str.clear();
   for(int i=0;i<a;i++)
   { 
      for(int j=0;j<b;j++)
      {
          ans2[i+j]+=num3[i]*num4[j];
          if(ans2[i+j]>=10)
          {
              ans2[i+j+1]+=ans2[i+j]/10;
              ans2[i+j]%=10;
          }
      }
   }
    int pos=0;
    for(int i=2*MAXnum(a,b)-1;i>=0;i--)
    {   
        if(ans2[i]!=0)
        {
           pos=i;
           break;
        }
    }
    for(int i=pos;i>=0;i--)
    {
        str.push_back((char)ans2[i]+'0');
    }

     delete []num3;
     delete []num4;
     delete []ans2; 

     return str; 
}
string subtract(string s1,string s2)
{   
    if(samestr(s1,s2))
    {
        return "0";
    }
    int a=s1.length(),b=s2.length();
    judge(s1,s2);
    int *num5=new int[MAXnum(a,b)];
    int *num6=new int[MAXnum(a,b)];
    int *ans3=new int[MAXnum(a,b)];
   reset(num5,num6,ans3,MAXnum(a,b));
   setnumber(s1,s2,num5,num6);
   string str;
   str.clear();
   int borrow=0;
   for(int i=0;i<MAXnum(a,b);i++)
   {  
      if(judge(s1,s2)==1)
      {
        ans3[i]+=num5[i]-num6[i];
        if(ans3[i]<0)
       {
         ans3[i]+=10;
         ans3[i+1]-=1;
       }
         else borrow=0;
      }
      else if(judge(s1,s2)==-1)
      {
          ans3[i]+=num6[i]-num5[i];
          if(ans3[i]<0)
         {
           ans3[i]+=10;
           ans3[i+1]-=1;
         }
           else borrow=0;
      }
   }
    int pos=0;
    for(int i=MAXnum(a,b)-1;i>=0;i--)
    {   
        if(ans3[i]!=0)
        {
           pos=i;
           break;
        }
    }
        if(judge(s1,s2)==-1)
        {
            str.push_back('-');
            for(int i=pos;i>=0;i--)
            {
                str.push_back((char)ans3[i]+'0');
            }
        }
        else if(judge(s1,s2)==1)
        {
            for(int i=pos;i>=0;i--)
            {
                str.push_back((char)ans3[i]+'0');
            }
        }   

     delete[]num5;
     delete[]num6;
     delete[]ans3;

     return str; 
}
string strans1,strans2;
string divide(string s1,string s2)
{   
    strans1.clear();
    strans2.clear();
    int a=s1.length(),b=s2.length();
    string s2copy=s2;
    string s1copy=s1;
    if(samestr(s1,s2))
    {   
        strans2="0";
        return "1";
    }
    if(judge(s1,s2)==1)
    {   
        int  checktime=0;
        for(int j=0;j<=abs(a-b);j++)
        {   
            s2copy=s2;
            int len=s1.length()-s2.length();
            for(int i=0;(i<len-checktime);i++)
            {
                s2copy.push_back(0);
            }
            if(judge(s1copy,s2copy)==1)
            {   
                 checktime++;
                 for(int i=0;i<=10;i++)
               {   
                 int k;
                 string a;
                 a.push_back((char)i+'0');
                 string str=multiply(s2copy,a);
                 string str2=subtract(s1copy,str);
                 if(str2[0]=='-')
                {
                  k=i-1;
                  strans1.push_back((char)k+'0');
                  string b;
                  b.push_back((char)k+'0');
                  string str3=multiply(s2copy,b);
                  s1copy=subtract(s1copy,str3);
                  break;
                }
              }
            }
            else 
            {
                checktime++;
                if(j==abs(a-b))
                {
                    strans1.push_back('0');
                }
                else if(checktime!=1&&judge(s1copy,s2copy)==-1)
                {
                     strans1.push_back('0');
                }
            }
        }
        strans2=subtract(s1,multiply(strans1,s2));
        return strans1;
    }
    else if(judge(s1,s2)==-1)
    {
        strans1="0";
        for(int i=a-1;i>=0;i--)
        {
            strans2=s1;
        }
      return strans1;
    }
}
string modulo(string s1,string s2)
{
     divide(s1,s2);
     return strans2;
}
/*
int main()
{   
    string s1,s2;
    cin>>s1>>s2;
    cout<<add(s1,s2)<<endl;
    cout<<subtract(s1,s2)<<endl;
    cout<<multiply(s1,s2)<<endl;
    cout<<divide(s1,s2)<<endl;
    cout<<modulo(s1,s2)<<endl;

    return 0;
}*/