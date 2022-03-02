#include<iostream>
using namespace std;

int partitionArray(int data[],int left,int right)
{
   int idxleft=left,idxright=right;
   int pivot=data[left];
   while(1)
   {
      int i=0,j=0;
      for(i=idxleft;i<=right;i++)
      {
          if(data[i]>=pivot)
          {
              break;
          }
      }
      for(j=idxright;j>=idxleft;j--)
      {
          if(data[j]<=pivot)
          {
              break;
          }
      }
      if(i>=j) break;
      swap(data[i],data[j]);
   }
      int k=0;
      for(int i=left;i<=right;i++)
      {
          if(data[i]==pivot)
          {   
              k=i;
              break;
          }
      }
      return k;
}
int selectRank(int data[], int left, int right, int rank)
{   
   if(left<=right&&rank>0)
   {
      int t=partitionArray(data,left,right);
      if(t==rank-1)  return data[t];
      else if(t<rank-1) selectRank(data,t+1,right,rank);
      else if(t>rank-1) selectRank(data,left,t-1,rank);
   }  
}
int selectRank(int data[], int n, int rank)
{   
    int y=selectRank(data,0,n-1,rank);
    return y;
}
