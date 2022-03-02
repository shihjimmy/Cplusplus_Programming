#include<iostream>
#include<cmath>
using namespace std;

class Node
{
  public:
     string item;
     int value;
     string time;
     Node* next;
     Node()
     {
         value=0;
         next=NULL;
     }
     Node(string _item,int _value,string _time)
     {
         item=_item;
         value=_value;
         time=_time;
         next=NULL;
     } 
};
//////////////////////
void swapnum1(Node *a,Node *b)
{
    int temp=a->value;
    a->value=b->value;
    b->value=temp;
}
////////////////////
void swapstrtime(Node *a,Node *b)
{
    string temp=a->time;
    a->time=b->time;
    b->time=temp;
}
void swapstritem(Node *a,Node *b)
{
    string temp=a->item;
    a->item=b->item;
    b->item=temp;
}
////////////////////////
enum Mode
{
    DEFAULT= 0,
    ITEM = 1,
    VALUE = 2,
    TIME = 3
};
class Account
{
    public:
      Node* first;
      Mode mode;
      ///////////////////////////////
      Account()
      {
          first=NULL;
          mode=DEFAULT;
      }
      ///////////////////////////////////////
     int convert(string a)
     {
      return ((int)a[6]-'0')*100000+((int)a[7]-'0')*10000+((int)a[3]-'0')*1000+((int)a[4]-'0')*100+((int)a[0]-'0')*10+((int)a[1]-'0')*1;
     }
    ////////////////////////////////////////
    bool judge(string s1,string s2)
   {
    int* num1=new int[s1.length()];
    int* num2=new int[s2.length()];
    for(int i=0;i<s1.length();i++)
    {
        num1[i]=(int)s1[i];
    }
    for(int i=0;i<s2.length();i++)
    {
        num2[i]=(int)s2[i];
    }
    for(int i=0;i<min(s1.length(),s2.length());i++)
    {
        if(num1[i]>num2[i]) 
        {
           return true;
        }
        else if(num1[i]==num2[i]) 
        {
           continue;
        }
        else if(num1[i]<num2[i])
        {
            return false;
        }
    }
    if(s1.length()>s2.length())
    {
       return true;
    }
    else 
       return false;
    delete []num1;
    delete []num2;
   }
   /////////////////////////////////////////////
     void insert(string _item,int _value,string _time)
     {
        if(first==NULL)
        {
            first=new Node(_item,_value,_time);
        }
        else
        {
            if(mode==DEFAULT)
            {
                Node* newnode=new Node(_item,_value,_time);
                newnode->next=first;
                first=newnode;
            }
            else if(mode==ITEM)
            {
                 Node* newnode=new Node(_item,_value,_time);
                 Node* previous=NULL;
                 Node* current=first;
                 while(current!=NULL)
                 {
                     if(judge(previous->item,newnode->item)&&judge(newnode->item,current->item))
                     {
                          previous->next=newnode;
                          newnode->next=current;
                          break;
                     }
                     else 
                      {
                          previous=current;
                          current=current->next;
                      }
                 }
            }
            else if(mode==VALUE)
            {
                 Node* newnode=new Node(_item,_value,_time);
                 Node* previous=NULL;
                 Node* current=first;
                 while(current!=NULL)
                 {  
                    if(previous->value<=newnode->value&&current->value>newnode->value)
                      {
                          previous->next=newnode;
                          newnode->next=current;
                          break;
                      }
                    else 
                      {
                          previous=current;
                          current=current->next;
                      }
                 }
            }
            else if(mode==TIME)
            {
                 Node* newnode=new Node(_item,_value,_time);
                 Node* previous=NULL;
                 Node* current=first;
                 while(current!=NULL)
                 {
                    if(convert(previous->time)<=convert(newnode->time)&&convert(current->time)>convert(newnode->time))
                    {
                          previous->next=newnode;
                          newnode->next=current;
                          break;
                    }
                    else 
                    {
                          previous=current;
                          current=current->next;
                    }
                 }
            }
        }
     }
     ///////////////////////////////////
     void display()
     {
         Node* current=first;
         while(current!=NULL)
         {
             cout<<current->item<<" "<<current->value<<" "<<current->time<<endl;
             current=current->next;
         }
     }
     /////////////////////////////////
     void erase()
     {  
        first=first->next;
     }
     ////////////////////////////////////
     void clearAll()
     {
         while(first!=NULL)
         {
             first=first->next;
         }
     }
     ////////////////////////////////////
     int getlength()
     {
         Node* current=first;
         int num=0;
         while(current!=NULL)
         {
             num++;
             current=current->next;
         }
          return num;
     }
     void sort(Mode  _mode)
     {
         if(_mode==DEFAULT) return;
         else if(_mode==VALUE)
         {
            Node* copy[1000];
            Node* current=first;
            int i=0;
            while(current!=NULL)
            {
                copy[i]=current;
                i++;
                current=current->next;
                
            }
            for(int i=0;i<getlength();i++)
            {
                for(int j=i+1;j<getlength();j++)
                {
                    if(copy[i]->value>copy[j]->value)
                    {   
                     swapnum1(copy[i],copy[j]);
                     swapstrtime(copy[i],copy[j]);
                     swapstritem(copy[i],copy[j]);
                    }
                }
            }
            first=copy[0];
         }
         else if(_mode==ITEM)
         {
            Node* copy[1000];
            Node* current=first;
            int i=0;
            while(current!=NULL)
            {
                copy[i]=current;
                i++;
                current=current->next;
            }
            for(int i=0;i<getlength();i++)
            {
                for(int j=i+1;j<getlength();j++)
                {
                    if(judge(copy[i]->item,copy[j]->item))
                    {
                     swapnum1(copy[i],copy[j]);
                     swapstrtime(copy[i],copy[j]);
                     swapstritem(copy[i],copy[j]);
                    }
                }
            }
            first=copy[0];
         }
         else if(_mode==TIME)
         {
            Node* copy[1000];
            Node* current=first;
            int i=0;
            while(current!=NULL)
            {
                copy[i]=current;
                i++;
                current=current->next;
            }
            for(int i=0;i<getlength();i++)
            {
                for(int j=i+1;j<getlength();j++)
                {
                    if(convert(copy[i]->time)>convert(copy[j]->time))
                    {
                     swapnum1(copy[i],copy[j]);
                     swapstrtime(copy[i],copy[j]);
                     swapstritem(copy[i],copy[j]);
                    }
                }
            }
            first=copy[0];
         }
     }
     ///////////////////////////////////////////
     void summary()
     {
         double sum=0;
         int num=0;
         Node* current=first;
         while(current!=NULL)
         {  
            num++;
            sum+=current->value;
            current=current->next;
         }
         double mean=sum/num;
         cout<<mean<<endl;
         double sum2=0;
         Node* current2=first;
         while(current2!=NULL)
         {
            sum2+=(current2->value-mean)*(current2->value-mean);
            current2=current2->next;
         }
         double std=sqrt(sum2/num);
         cout<<std<<endl;
     }
     //////////////////////////////////////////////
};
/*
int main()
{    
     Account account;
     account.insert("Apple", 100, "09/09/21");
     account.insert("Carrot", 30, "09/09/22");
     account.insert("Box", 80, "09/09/23");
     account.insert("Erasers", 1000, "09/09/24");
     account.display(); cout << endl;
     account.summary();
     account.erase();
     account.display(); cout << endl;
     account.summary();
     cout<<endl;
     account.sort(VALUE);
     account.display();
     cout<<endl;
     account.clearAll();
     account.insert("Erasers", 1000, "09/09/24");
     account.display(); cout << endl;
     
     system("pause");
     return 0;
}*/