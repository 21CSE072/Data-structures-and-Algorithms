#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int value;
    struct node*next;
};
struct node*head=NULL;
int n,data;
struct node*newnode;
void insertfirst()
{
    printf("enter the no of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->value=data;
        newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node*p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        newnode->next=head;
        head=newnode;
        p->next=head;
    }
    }
}
void insertlast()
{
    printf("enter the no of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->value=data;
        newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node*p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=newnode;
        newnode->next=head;
    }
    }
}
void insertmiddle()
{
        int val,data1;
        printf("enter at which value enter the data");
        scanf("%d",&data1);
        printf("enter the value to be inserted");
        scanf("%d",&val);
        struct node*p=head;
        while(p->value!=data1)
        {
            p=p->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->value=val;
        newnode->next=NULL;
        newnode->next=p->next;
        p->next=newnode;
}
void deletefirst()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("No list");
    }
    else
    {
        struct node*p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        temp=head;
        head=head->next;
        p->next=head;
        free(temp);
    }
}
void deletelast()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("No list");
    }
    else
    {
        struct node*p=head;
        while(p->next->next!=head)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=head;
        free(temp);
    }
}
void deletemiddle()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("No list");
    }
    else
    {
        int val;
        printf("enter the value to be deleted");
        scanf("%d",&val);
        struct node*p=head;
        while(p->next->value!=val)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("No list");
    }
    else
    {
    struct node*p=head;
    while(p->next!=head)
    {
        printf("\t%d",p->value);
        p=p->next;
    }
    printf("\t%d",p->value);
}
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
        display();
        break;
        case 3:
        exit(0);
        break;
        case 4:
        insertlast();
        break;
        case 5:
        insertmiddle();
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
