#include<iostream>
using namespace std;

void mergeInplace(int* A,int front,int mid,int end){
        int front2=mid+1;
        while(front2<=end&&front<=mid)
        {  
           if(A[front2]>=A[mid]) return;
           else
           {
               int idx=0;
               for(int i=front;i<=mid;i++)
              {
                 if(A[i]>=A[front2])
                {
                  idx=i;
                  break;
                }
              }  
              int value=A[idx];
              swap(A,idx,front2);
              for(int i=front2;i>idx;i--)
             {
               A[i]=A[i-1];
             }
               A[idx+1]=value;
               front2++;
               mid++;
           }
        }
}
void MERGEplace(int*A,int front,int end)
{   
    int mid=(front+end)/2;
    if(front<end)
    {
        MERGEplace(A,front,mid);
        MERGEplace(A,mid+1,end);
        mergeInplace(A,front,mid,end);
    }
}
void mergeSortInplace(int* A, int size){
    MERGEplace(A,0,size-1);
} 

