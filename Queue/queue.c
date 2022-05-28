/***************************************************************************
 QUEUE USING ARRAY
*******************************************************************************/


#include <stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX];
int rear = -1;
int front = -1;
void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();


void push(int item)
{
    if(isFull())
    {printf("Queue is Full\n"); return; }
    if(front == -1)
    {
        front = 0;
    }
    queue[++rear] = item;
    
}

int del()
{
    if(isEmpty())
    {printf("Queue is empty\n"); return -1;}
    else
    {
        return queue[front++];
    }
}
int peek()
{0
    if(isEmpty())
    printf("Stack is empty\n");
    else
    {
        return queue[front];
    }
}

int isEmpty()
{
    if(front == -1 || front == rear + 1)
    return 1;
    return 0;
    
}

int isFull()
{
    if(rear == MAX-1)
    return 1;
    return 0;
    
}




int main()
{
    while(1){
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY TOP\n");
    printf("4. isEmpty\n");
    printf("5. isFull\n");
    int i;
    int x; scanf("%d",&x);
    switch(x)
    {
        case 1:
        scanf("%d",&i);
        push(i);
        break;
        case 2:
        printf("%d",del());
        break;
        case 3:
        printf("%d",peek());
        break;
        case 4:
        printf("%d",isEmpty());
        break;
        case 5:
        printf("%d",isFull());
        break;
    }
    }
    

    return 0;
}



/******************************************************************************
QUEUE using linked list
*******************************************************************************/


#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
    
};
struct node *front = NULL,*rear = NULL;
void insert(int item);
int del();
int peek();
void display();
int isEmpty();



void insert(int item)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   if(temp == NULL)
   {
       printf("Stackoverflow\n");
       //return -1;
   }
   
   temp -> info = item;
   temp -> link = NULL;
   
   if(front == NULL)
   {
       front = temp;
   }
   else
   rear -> link = temp;
   rear = temp;
}

int del()
{
    struct node *temp;
    int item;
    if(isEmpty())
    {printf("Queue is empty\n"); return -1;}
    else
    {
        temp = front;
        item = front -> info;
        front = front -> link;
        free(temp);
        return item;
    }
}
int peek()
{
    if(isEmpty())
    printf("Stack is empty\n");
    else
    {
        return front -> info;
    }
}

int isEmpty()
{
    if(front == NULL)
    return 1;
    return 0;
    
}


int main()
{
    while(1){
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY TOP\n");
    printf("4. isEmpty\n");
    int i;
    int x; scanf("%d",&x);
    switch(x)
    {
        case 1:
        scanf("%d",&i);
        insert(i);
        break;
        case 2:
        printf("%d",del());
        break;
        case 3:
        printf("%d",peek());
        break;
        case 4:
        printf("%d",isEmpty());
        break;
    }
    }
    

    return 0;
}
