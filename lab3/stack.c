//Implementing Stack Data Structure using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{                          //Declaring List
    int data;
    struct nodee *next;
};
struct node *head=NULL;

void push();                          // Function declaration
void pop();
void display();

void main()
{
    int c;
    while (1)
    {
        printf("enter 1-push\t2-pop\t3-display\t4-exit\n");
        scanf("%d", &c);

        if(c==4)
            break;

        switch (c)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        }
    }
}

void push()                 //push function
{
    int val;
    printf("enter the value\n");
    scanf("%d",&val);
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=head;
    head=ptr;
}

void pop()                  //pop function
{
    struct node *temp=head;
     if(head == NULL)
        {
            printf("the stack is empty\n");
            return;
        }
    head=head->next;
    free(temp);
}

void display()              //display fucnction
{
     struct node *temp=head;
     if(head == NULL)
        {
            printf("the stack is empty\n");
            return;
        }
     while(1)
     {
        printf("%d-%p\t",temp->data,temp->next);
         if(temp->next == NULL)
            break;
        temp=temp->next;
     }
     puts("\n");
}
