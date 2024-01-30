#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node
{
    int value;
    struct node*next;
};
int n,data;
struct node*head=NULL;
struct node*newnode;
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
        }
        else
        {
            struct node*p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
        }
        
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
void rev()
{
    struct node*prevnode=NULL;
    struct node*currnode=head;
    struct node*nextnode=head;
    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;
}
int main()
{
    int choice;
    while(1)
    {
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertlast();
        break;
        case 2:
        display();
        break;
        case 3:
        exit(0);
        break;
        case 4:
        rev();
        break;
    }
    printf("\n");
    }
}


