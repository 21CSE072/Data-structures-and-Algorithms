#include<stdio.h>
#include<stdlib.h>
void enqueue(int n,int queue[],int rear,int*front)
{
    if(*front==0)
    {
        printf("queue is full");
    }
    else
    {
    printf("enter the data");
    int data;
    scanf("%d",&data);
    queue[rear]=data;
    rear=(rear+1)%n;
    }
}
int dequeue(int*front,int n)
{
    *front=(*front+1)%n;
}
void display(int n,int queue[],int *front)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",queue[(*front+i)%n]);
    }
}
void reversekth(int *k,int stack[],int *front,int queue[],int n)
{
    int n1=*k;
    int top=-1;
    for(int i=0;i<n1;i++)
    {
        stack[top+1]=queue[(*front+i)%n];
        top++;
    }
    for(int i=0;i<n1;i++)
    {
    queue[(*front+i)%n]=stack[top];
    top--;
    }
}
int main()
{
    printf("enter the size of the queue");
    int n;
    scanf("%d",&n);
    int rear=0,front=0,queue[n];
    int data;
    printf("\nenter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        queue[rear]=data;
        rear=(rear+1)%n;
    }
    int k=3,stack[k];
    int choice;
    while(1)
    {
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue(n,queue,rear,&front);
            break;
            case 2:
            dequeue(&front,n);
            break;
            case 3:
            display(n,queue,&front);
            break;
            case 4:
            reversekth(&k,stack,&front,queue,n);
            break;
            case 5:
            exit(0);
            break;
        }
    }
    return 0;
}
