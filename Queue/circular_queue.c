/******************************************************************************
CIRCULAR QUEUE
*******************************************************************************/


#include <stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void insert(item);
int del();
int peek();
int isEmpty();
int isFull();




void insert(int item)
{
      if(isFull())
      {
          printf("Queue is Full\n");
          return;
      }
      if(front ==  -1)
      front = 0;
      if(rear == MAX - 1)
      rear = -1;
      queue[++rear] = item;
}

int del()
{
   if(isEmpty())
   {
       printf("Queue is empty\n");
       return -1;
   }
   int item = queue[front];
   if(front == rear)
   {
       front = -1;
       rear = -1;
       return item;
   }
   if(front == MAX - 1)
   front = 0;
   else
   front++;
   return item;
   
}
int peek()
{
    if(isEmpty())
    {
        printf("Empty Queue\n");
        return -1;
    }
    return queue[front];
    
}

int isFull()
{
    if((front == 0 && rear == MAX -1 )|| front ==rear + 1)
    return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1)
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
