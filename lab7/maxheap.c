#include<stdio.h>
#include<stdlib.h>
#define size 10
int a[size];

void main()
{
  int n,i,j,k;
  printf("enter the size\n");
  scanf("%d",&n);
  printf("enter elem\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("temer\n");
  for(k=1;k<n;k++)
  {
     j=k;
    while(j > 0)
    {
      i=(j-1)/2;
      if(a[i]<a[j])
      {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
      j=i;
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
