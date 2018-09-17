#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root=NULL;
void create(struct node *root)
{
  printf("enter data\n")
  int val,c;
  scanf("%d",&val);

  struct node *ptr=(struct node*)malloc(sizeof(struct node));
  ptr->data=val;
  printf("enter 11- leftnode and rightnode\n10-leftnode\n01 - rightnode\n00-NOnode\n");
  if(c==11)
  {
    root->left=ptr;
  }


}
void createleft(struct node *root)
{
  root
}
void main()
{
  printf("create bintree\n");
  create();
}
