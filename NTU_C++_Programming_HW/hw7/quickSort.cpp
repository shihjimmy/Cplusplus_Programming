#include<iostream>
using namespace std;
int partition(int* A, int l, int r){

   int pivot=A[l];
   int idxleft=l,idxright=r;
   while(1)
   {  
      int i=0,j=0;
      for(i=idxleft;i<=r;i++)
      {
         if(A[i]>=pivot)
         {
            break;
         }
      }
      for(j=idxright;j>=l;j--)
      {
         if(A[j]<=pivot)
         {
            break;
         }
      }
      if(i>=j) break;
      swap(A,i,j);
   }
   int k=0;
   for(int i=l;i<=r;i++)
   {
      if(A[i]==pivot) 
      {
         k=i;
         break;
      }
   }
   return k;
}

void quickSort(int* A, int l, int r){
   if(l<r)
   {
      int pivot=partition(A,l,r);
      quickSort(A,pivot+1,r);
      quickSort(A,l,pivot-1);
   }
}
