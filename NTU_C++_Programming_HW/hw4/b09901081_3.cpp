#include <iostream>
using namespace std;

int main()
{   
   int a,b,c,d,e,f;
   int add=0,sub=0,new1=0,new2=0,new3=0;
   while((scanf("%d:%d:%d~%d:%d:%d",&a,&b,&c,&d,&e,&f))!=EOF)
   {    
   	  if((d<a)||((d==a)&&(e<b))||((d==a)&&(e==b)&&(f<c)))
   	  {
   	    int time1=0,time2=0;
   	        time1=86400-3600*a-60*b-c;
   	        time2=3600*d+60*e+f;
   	        add+=time1+time2;
	  }
   	  else 
   	  {
   	    int time1=0,time2=0;
		    time1=3600*a+60*b+c;
			time2=3600*d+60*e+f;
			sub+=time2-time1;
	  } 	  
   }
  	new3=(add+sub)%60;
	new2=((add+sub)/60)%60;
	new1=((add+sub)/3600)%24;
	printf("%02d:%02d:%02d",new1,new2,new3);

    system("pause");
    return 0;
}
