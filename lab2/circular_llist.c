//circular linked list involving create,insert,display,delete and few other operations 

#include<stdio.h>
#include<stdlib.h>

//circular node declaration
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;

//req func declarations
void create();
void insert();
void display();
void delete(int);

void main()
{
    printf("Create node\n");
    create();
    printf("enter 1-insert 2-delete 3-display 4-create\n");
    int s;
    scanf("%d",&s);
    switch(s)
    {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            int key;
            printf("enter the key to delete\n");
            scanf("%d",&key);
            delete(key);
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            create();
            break;
        }
        default : exit(1);
    }

}

void create()
{
    while(1)  //loop for repeated node creation
   {
        printf("enter data to continue or -1 to stop\n");
    int val;
    scanf("%d",&val);
    if(val == -1)
        break;
    struct node *ptr=( struct node *)malloc(sizeof( struct node));
    if(ptr == NULL) //checking the whether memory is allocated or not
    {
        printf("Memory not found\n");
        break;
    }

    ptr->data=val; //storing data into node

    if(head == NULL) //for first node
    {
        head=ptr;
        tail=ptr;
        ptr->next=head;
    }
    else //for other than first node
    {
        tail->next=ptr;
        ptr->next=head;
        tail=ptr;
    }
   }
   display();
}

void display()
{
    struct node *temp=head;
    if(head == NULL)
        {
            printf("list empty\n");
            return;
        }
    while(1)
    {
        printf("%d-%p  ",temp->data,(void *)temp->next);
        if(temp->next == head)
            break;
        temp=temp->next;
    }
}

void delete(int key)
{

        struct node *temp=head,*temp1=NULL,*prev=NULL;
        if(head->data == key)
        {
            head=head->next;
            free(temp);
            tail->next=head;
        }
        else
        {
        while(1)
        {
            if(temp->data == key)
                break;
            prev = temp;
            temp=temp->next;
        }

        temp1=prev->next;
        prev->next=temp1->next;
        free(temp1);
        }
        display();
}

void insert()
{
    printf("to append at last enter -1 or enter the position after which to insert\n");
    int pos;
    scanf("%d",&pos);
    if(pos == -1)
    {
        create();
        return;
    }
    else{
        if(pos == 0)
        {
            printf("enter the data of new node\n");
            int val;
            scanf("%d",&val);
            struct node *ptr=( struct node *)malloc(sizeof( struct node));
            if(ptr == NULL) //checking the whether memory is allocated or not
            {
                printf("Memory not found\n");
                return;
            }
            ptr->data=val;
            ptr->next=head;
            head=ptr;
            tail->next=head;
        }
        else if(pos > 0)
        {
            printf("enter the data of previous node\n");
            int val,key;
            scanf("%d",&key);
            printf("enter the data of new node\n");
            scanf("%d",&val);
            struct node *ptr=( struct node *)malloc(sizeof( struct node)),*temp=head,*prev=NULL;
            if(ptr == NULL) //checking the whether memory is allocated or not
            {
                printf("Memory not found\n");
                return;
            }
            ptr->data=val;
            while(1)
            {
                if(temp->data == key)
                    break;
                temp=temp->next;
            }
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
    display();
}
