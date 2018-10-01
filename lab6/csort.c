#include<stdio.h>
#include<stdlib.h>
//#define size 100
void main()
{
  int n;
  printf("enter the n\n");
  scanf("%d",&n);
  int a[n],i,j,max=0;
  printf("enter the elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    if(a[i]>max)
      max=a[i];
  }
  int *b=(int *)malloc(sizeof(int)*(max+1));
  for(i=0;i<n;i++)
  {
    b[a[i]]++;
  }
  for(i=1;i<max+1;i++)
  {
    b[i]=b[i]+b[i-1];
  }
  for(i=1;i<max+1;i++)
  {
    for(j=0;j<b[i]-b[i-1];j++)
      printf(" %d ",i);
  }
}
