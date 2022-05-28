/*

Implement Queue using Linked List 

Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.


*/


//Function to push an element into the queue.
void MyQueue:: push(int x)
{
       QueueNode *temp=new QueueNode(x);
       if(front==NULL)
       {
           front=temp;
           rear=temp;
           return;
       }
       rear->next=temp;
       rear=temp;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL)
    return -1;
    QueueNode *temp=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    int ans= temp->data;
    delete(temp);
    return ans;
}
