#include <iostream>
using namespace std;

bool isLeapYear(int year);

int getNumOfDaysInMonth(int year,int month);

int getStartDay(int year, int month);


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


#ifndef MAIN
#define MAIN

int main() {
    int year,month;
	cin>>year>>month;
	cout<<getStartDay(year,month)<<endl; 
    

    return 0;
}

#endif
