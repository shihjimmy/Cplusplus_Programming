#include <iostream>
#include <iomanip>
using namespace std;

bool isLeapYear(int year);

int getNumOfDaysInMonth(int year,int month);

int getStartDay(int year, int month);

void printWeekTitle();

void printMonthBody(int year, int month);

void printMonthTitle(int month);

void printMonth(int year, int month);

void readInput(int &year, int &month);


bool isLeapYear(int year) {
	  if(year%4==0)
        {
             if(year%100==0) 
             {
                     if(year%400==0) return true;
                     else return false;
             }
             else return true;  
        }
        else 
        return false;
}

int getNumOfDaysInMonth(int year,int month){
	if(isLeapYear(year)==true) 
	 {
        if(month==2) return 29;
		else if(month%2==1&&month<=7) return 31;
        else if(month%2==0&&month!=2&&month<=7) return 30;
		else if(month%2==0&&month>7) return 31;
		else if(month%2==1&&month>7) return 30;

	 }
     else
	 {  
		if(month==2) return 28;
		else if(month%2==1&&month<=7) return 31;
        else if(month%2==0&&month!=2&&month<=7) return 30;
		else if(month%2==0&&month>7) return 31;
		else if(month%2==1&&month>7) return 30;

	 }

} 
	

int getStartDay(int year, int month) {
   int sum=0;
   for(int i=1;i<=year-1;i++)
   {
      if(isLeapYear(i)==true) sum+=366;
	  else                    sum+=365;
   }
   for(int i=1;i<=month-1;i++)
   {
       sum+=getNumOfDaysInMonth(year,i);
   }
   int k=(sum%7);
   if(k==6) return 0;
   else return k+1;

}

void printWeekTitle(){
    cout<<"SUN MON TUE WED THU FRI SAT"<<endl;
}

void printMonthBody(int year, int month){
	int t=getStartDay(year,month);
    for(int i=t-1;i>=0;i--)
    {    
        cout<<"    ";       
    }
    for(int i=1;i<=7-t;i++)
    {   
        cout<<"  ";
        cout<<i<<" ";
    }
        cout<<endl;
    int u=0;
    for(int i=8-t;i<=getNumOfDaysInMonth(year,month);i++)
    { 
        if(i<=9)
        {
          cout<<"  ";
          cout<<i<<" ";
		}
        else if(i>=10)
        {
          cout<<" ";
          cout<<i<<" ";
		}
        u++;
        if(u%7==0) 
        {
            u=0;
            cout<<endl;
        }
    }
}

void printMonthTitle(int month){
	if(month==1) cout<<"JAN"<<endl;
    if(month==2) cout<<"FAB"<<endl;
    if(month==3) cout<<"MAR"<<endl;
    if(month==4) cout<<"APR"<<endl;
    if(month==5) cout<<"MAY"<<endl;
    if(month==6) cout<<"JUN"<<endl;
    if(month==7) cout<<"JUL"<<endl;
    if(month==8) cout<<"AUG"<<endl;
    if(month==9) cout<<"SEP"<<endl;
    if(month==10) cout<<"OCT"<<endl;
    if(month==11) cout<<"NOV"<<endl;
    if(month==12) cout<<"DEC"<<endl;
    
}

void printMonth(int year, int month) {
    printMonthTitle(month);
    printWeekTitle();
    printMonthBody(year,month);
}

void readInput(int &year, int &month){
	 scanf("%d/%d",&year,&month);
}


#ifndef MAIN
#define MAIN

int main() {
      int year,month;
      readInput(year,month);
      printMonth(year,month);
      return 0;
}

#endif

