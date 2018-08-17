#include<stdio.h>
#include<stdlib.h>
struct slist{
int data;
struct slist *adr;
}node;
static int cntnodes;
struct slist *head=NULL,*last =NULL;
void push()
{
    int val;
    while(1)
    {
        printf("enter data val or -1 to stop\n");
        scanf("%d",&val);
        if(val == -1 )
            break;
        struct slist *ptr=(struct slist *)malloc(sizeof(struct slist));
        ptr->data=val;
        if(cntnodes == 0)
        {
            head=ptr;
            last=ptr;
            ptr->adr=NULL;
        }
        else
        {
            last->adr=ptr;
            ptr->adr=NULL;
            last=ptr;
        }
        cntnodes++;
    }
        display(head);
}
void display(struct slist *ptr)
{
    printf("the nodes are :\n");
    int c=cntnodes;
   while(c--)
    {
        printf("%d - %d ->",ptr->data,ptr->adr);
        ptr=ptr->adr;
    }
    puts('\n');
}
void deletenode();
void insert();
void findmidnode();
void main()
{
    printf("create nodes\n");
    push();
    printf("enter 1-deletenode or 2-insert or 3-push or 4-display or other value to exit\n");
    int s;
    scanf("%d",&s);
    switch(s)
    {
        case 1: deletenode();
                break;
        case 2:insert();
                break;
        case 3:push();
                break;
        case 4:display(head);
                break;
        default : exit(1);
    }
}
void deletenode()
{
    printf("enter the pos\n");
    int pos;
    struct slist *ptr=head,*ptr2=NULL;
    scanf("%d",&pos);
    for(;pos>2;pos--)
    {
        ptr=ptr->adr;
    }
    if(pos==1)
    {
        ptr=ptr->adr;
        head=ptr;
        cntnodes--;
    }
    else
    {
        ptr2=ptr;
        ptr2=ptr2->adr->adr;
        ptr->adr=ptr2;
        cntnodes--;
    }
    display(head);
}
void insert()
{
    printf("enter the pos and val\n");
    int pos,p1,p2,val;
    scanf("%d %d",&pos,&val);p1=pos;p2=pos;
    struct slist *ptr=(struct slist *)malloc(sizeof(struct slist)),*ptr2=head,*ptr3=head;
    ptr->data=val;
    if(pos==1)
    {
        ptr->adr=head;
        head=ptr;
        cntnodes++;
    }
    else
    {
         for(;p1>1;p1--)
        {
            ptr2=ptr2->adr;
        }
         for(;p2>2;p2--)
        {
            ptr3=ptr3->adr;
        }
        ptr3->adr=ptr;
        ptr->adr=ptr2;
    }
    display(head);
}
