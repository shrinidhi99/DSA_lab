#include<stdio.h>
#include<stdlib.h>
#define size 10
int a[size];
int b[size];
int f=-1,r=-1;
void heapify(int j)
{
  int k=j,i;
  while(k > f)
  {
    i=(k-1)/2;
    if(b[i]<b[k])
    {
      int t=a[i];
      a[i]=a[k];
      a[k]=t;
      int t2=b[i];
      b[i]=b[k];
      b[k]=t2;
    }
    k=i;
  }
}
void enqueue()
{
  if(r == size)
  {
    printf("overflow\n");
    return;
  }
  if(r==-1 && f==-1)
  {
    f++;
    r++;
  }
  printf("enter ele and its priority\n");
  scanf("%d %d",&a[r],&b[r]);
  int f=r;
  r++;
  heapify(f);
  //r++;
  //printf("heapifed\n");
//  r++;
}
void dequeue()
{
  int j;
  if(f==-1 || f==r)
    return;
  f++;
  for(j=f+1;j<=r;j++)
  {
    heapify(j);
  }
}
void display()
{
  int i;
  if(f ==-1 || r== -1)
    return;
  for(i=f;i<r;i++)
  {
    printf("%d  ",a[i]);
  }
//  printf("sdfsa\n");
}
void main()
{
  int c,i;
  //printf("%d %d\n",f,r);
while(1)
{
  printf("enter 1- enq 2-deq 3- dis 4-exit\n");
  scanf("%d",&c);
    switch(c)
    {
      case 1:
            enqueue();
            break;
      case 2:
            dequeue();
            break;
      case 3:
            display();
            break;
      case 4:exit(1);
    }
  }
}
