#include<iostream>
using namespace std;

int* createArray(int* A, int size){
   for(int i=0;i<size;i++)
   {
       *(A+i)=i;
   }
    return A;
}

void swap(int* A, int i, int j){
   int temp=*(A+i);
   *(A+i)=*(A+j);
   *(A+j)=temp;
}

void shuffle(int* A, int size){
   for(int i=size-1;i>=1;i--)
   {
       int j=rand()%i;
       swap(A,i,j);
   }
}

void printArray(int* A, int size){
  for(int i=0;i<size;i++)
  {
      cout<<A[i]<<" ";
  }
}