#include <iostream>
using namespace std;

bool isLeapYear(int year);


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


#ifndef MAIN
#define MAIN

int main() {
      int year;
      cout<<isLeapYear(year)<<endl;
      return 0;
}

#endif

