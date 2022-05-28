/******************************************************************************
STACK USING ARRAY
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();



void push(int item)
{
    if(isFull())
    printf("Stack is Full\n");
    else
    {
        stack[++top] = item;
    }
}

int pop()
{
    if(isEmpty())
    printf("Stack is empty\n");
    else
    {
        return stack[top--];
    }
}
int peek()
{
    if(isEmpty())
    printf("Stack is empty\n");
    else
    {
        return stack[top];
    }
}

int isEmpty()
{
    if(top == -1)
    return 1;
    return 0;
    
}

int isFull()
{
    if(top == MAX-1)
    return 1;
    return 0;
    
}




int main()
{
    while(1){
    printf("1. PUSH");
    printf("1. POP");
    printf("1. DISPLAY TOP");
    printf("1. isEmpty");
    printf("1. isFull");
    int i;
    int x; scanf("%d",&x);
    switch(x)
    {
        case 1:
        scanf("%d",&i);
        push(i);
        break;
        case 2:
        printf("%d",pop());
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
STACK USING LINKED LIST
*******************************************************************************/


#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
    
};
struct node *top = NULL;
void push(int item);
int pop();
int peek();
int isEmpty();


void push(int item)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   if(temp == NULL)
   {
       printf("Stackoverflow\n");
       //return -1;
   }
   temp -> info = item;
   temp -> link = top;
   top = temp;
}

int pop()
{
    struct node *temp;
    int item;
    if(isEmpty())
    {printf("stack is mpty\n"); return -1;}
    else
    {
        temp = top;
        item = top -> info;
        top = top -> link;
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
        return top -> info;
    }
}

int isEmpty()
{
    if(top == NULL)
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
        push(i);
        break;
        case 2:
        printf("%d",pop());
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
