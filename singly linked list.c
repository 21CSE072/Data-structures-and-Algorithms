#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void insertfirst();
void insertlast();
void insertmiddle();
void deletefirst();
void deletelast();
void deletemiddle();
void display();
  struct node
    {
        int value;
        struct node*next;
    };
    struct node*head=NULL;
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
        insertmiddle();
        break;
        case 3:
        insertlast();
        break;
        case 4:
        display();
        break;
        case 5:
        deletefirst();
        break;
        case 6:
        deletelast();
        break;
        case 7:
        deletemiddle();
        break;
        case 8:
        exit(0);
        break;
        
    }
    }
    return 0;
}
    void insertfirst()
    {
    int n,data;
    printf("enter the no of elements");
    scanf("%d",&n);
    struct node*newnode;
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
            newnode->next=head;
            head=newnode;
        }
    }
    }
    void insertlast()
    {
    int n,data;
    printf("enter the no of elements");
    scanf("%d",&n);
    struct node*newnode;
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
    void insertmiddle()
    {
        int data,data1;
        struct node*newnode;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
           struct node*p=head;
           printf("enter at which place insert the node");
           scanf("%d",&data);
           printf("enter the data");
           scanf("%d",&data1);
           newnode=(struct node*)malloc(sizeof(struct node));
           newnode->value=data1;
           newnode->next=NULL;
           while(p->value!=data)
           {
               p=p->next;
           }
           newnode->next=p->next;
           p->next=newnode;
        }
    }
    void deletefirst()
    {
        struct node*temp=head;
        head=temp->next;
        free(temp);
    }
    void deletelast()
    {
        struct node*temp;
        struct node*p=head;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=NULL;
        free(temp);
    }
    void deletemiddle()
    {
        int val;
        printf("enter the value to be deleted");
        scanf("%d",&val);
        struct node*temp;
        struct node*p=head;
        while(p->next->value!=val)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        free(temp);
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
