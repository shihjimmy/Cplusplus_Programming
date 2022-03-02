#include<iostream>
#include<vector>
using namespace std;

void merge(int* A,int front,int mid,int end){
   int n1=mid-front+1;
   int n2=end-mid;
   int n3=end-front+1;
   int *left=new int[n1];
   int *right=new int[n2];
   int *copy=new int[n3];
   for(int i=0;i<n1;i++)
   {
       left[i]=A[front+i];
   }
   for(int i=0;i<n2;i++)
   {
       right[i]=A[mid+i+1];
   }
   left[n1]=2147483647;
   right[n2]=2147483647;
   int idxleft=0,idxright=0;
   for(int i=0;i<n3;i++)
   {
      if(left[idxleft]>=right[idxright])
      {
          copy[i]=right[idxright];
          idxright++;
      }
      else if(left[idxleft]<=right[idxright])
      {  
         copy[i]=left[idxleft];
         idxleft++;
      }
   }
   int t=0;
   for(int i=front;i<=end;i++)
   {  
      A[i]=copy[t];
      t++;
   }
}
void MERGE(int*A,int front,int end)
{   
    int mid=(front+end)/2;
    if(front<end)
    {
        MERGE(A,front,mid);
        MERGE(A,mid+1,end);
        merge(A,front,mid,end);
    }
}
void mergeSort(int* A, int size){   
   MERGE(A,0,size-1);
}




