/*

Operations on Queue 

Given a queue of integers and Q queries. The task is to perform operations on queue according to the query. 

Queries are as:

i x : (adds element x in the queue from rear).

r : (Removes the front element of queue).

h : (Returns the front element).

f y : (check if the element y is present or not in the queue). Return "Yes" if present, else "No".

Example 1:

Input:
Q = 6
Queries = i 2 i 4 i 3 i 5 h f 8
Output:
2
No
Explanation: Inserting 2, 4, 3, and 5
onto the queue: 2 4 3 5. h means front
So front is 2. f is find. 8 is not in
queue so No.

*/


void enqueue(queue<int> &q,int x)
    {
       q.push(x);
    }
     
    //Function to remove front element from queue.
    void dequeue(queue<int> &q)
    {
        q.pop();
    }
    
    //Function to find the front element of queue.
    int front(queue<int> &q)
    {
        int f= q.front();
        return f;
    }
    
    //Function to find an element in the queue.
    string find(queue<int> q, int x)
    {
        while(q.empty()==false)
        {
            if(q.front()==x)
            return "Yes";
            q.pop();
        }
        return "No";
    }