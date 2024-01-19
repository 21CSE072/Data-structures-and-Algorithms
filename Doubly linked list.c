#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int value;
    struct node*prev;
    struct node*next;
};
struct node*head=NULL;
int n,data;
struct node*newnode;
void insertfirst()
{
    printf("enter the no of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->value=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
}
void insertlast()
{
    printf("enter the no of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->value=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
           struct node*p=head;
           while(p->next!=NULL)
           {
               p=p->next;
           }
           p->next=newnode;
           newnode->prev=p;
        }
    }
}
void insertmiddle()
{
   struct node*p=head;
   int data1,val;
   printf("enter at which value insert the data");
   scanf("%d",&data1);
   printf("enter the value to be inserted");
   scanf("%d",&val);
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->value=val;
   newnode->next=NULL;
   newnode->prev=NULL;
   while(p->value!=data1)
   {
       p=p->next;
   }
   newnode->next=p->next;
   p->next=newnode;
   newnode->prev=p;
   newnode->next->prev=newnode;
}
void deletefirst()
{
    if(head==NULL)
    printf("no list");
    else
    {
        struct node*temp=head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
}
void deletelast()
{
    if(head==NULL)
    printf("no list");
    else
    {
        struct node*p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        struct node*temp=p;
        temp->prev->next=NULL;
        free(temp);
    }
}
void deletemiddle()
{
    if(head==NULL)
    printf("no list");
    else
    {
        int val;
        struct node*p=head;
        printf("enter the value to be deleted");
        scanf("%d",&val);
        while(p->value!=val)
        {
            p=p->next;
        }
        struct node*temp=p;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(temp);
    }
}

void display()
{
    struct node*p=head;
    while(p->next!=NULL)
    {
        printf("\t%d",p->value);
        p=p->next;
    }
     printf("\t%d",p->value);
}
int main()
{
    int choice;
    while(1)
    {
    printf("\nenter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertfirst();
        break;
        case 2:
        insertlast();
        break;
        case 3:
        insertmiddle();
        break;
        case 4:
        display();
        break;
        case 5:
        exit(0);
        break;
        case 6:
        deletefirst();
        break;
        case 7:
        deletelast();
        break;
        case 8:
        deletemiddle();
        break;
    }
    }
}