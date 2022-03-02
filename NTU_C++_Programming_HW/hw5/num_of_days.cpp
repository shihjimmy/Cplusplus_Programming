#include <iostream>
using namespace std;

bool isLeapYear(int year);

int getNumOfDaysInMonth(int year,int month);


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


#ifndef MAIN
#define MAIN

int main() {
        int year,month;
		cin>>year>>month;
		cout<<getNumOfDaysInMonth(year,month)<<endl;

        return 0;
}

#endif
