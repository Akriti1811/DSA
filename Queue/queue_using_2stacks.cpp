/*

Queue using two Stacks 

Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Example 1:

Input:
5
1 2 1 3 2 1 4 2

Output: 
2 3

Explanation: 
In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue 
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

*/

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty())
    return -1;
    while(s1.empty()==false)
    {
        s2.push(s1.top());
        s1.pop();
    }
    int t=s2.top();
    s2.pop();
    while(s2.empty()==false)
    {
        s1.push(s2.top());
        s2.pop();
    }
    return t;
}
