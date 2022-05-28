/*

Stack using two queues 
Easy Accuracy: 40.49% Submissions: 86171 Points: 2
Implement a Stack using two queues q1 and q2.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
Example 2:

Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1

*/


//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    while(q1.empty()==false)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while(q2.empty()==false)
    {
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty())
    return -1;
    int t=q1.front();
    q1.pop();       
    return t;
}
