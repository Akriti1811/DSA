/*

Queue Reversal 

Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6

Output: 
6 2 10 1 3 4

Explanation: 
After reversing the given
elements of the queue , the resultant
queue will be 6 2 10 1 3 4.

*/


queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(q.empty()==false)
    {
        s.push(q.front());
        q.pop();
    }
    while(s.empty()==false)
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}