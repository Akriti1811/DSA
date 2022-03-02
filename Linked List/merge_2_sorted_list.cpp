/*
Merge two sorted linked lists 
Medium Accuracy: 49.26% Submissions: 87546 Points: 4
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105
*/

Node* sortedMerge(Node* l, Node* r)  
{  
        if(l==NULL)
            return r;
        if(r==NULL)
            return l;
        Node *head=NULL,*tail=NULL;
        if(l->data<=r->data)
        {
            head=tail=l;
            l=l->next;
        }
        else
        {
            head=tail=r;
            r=r->next;
        }
        while(l && r)
        {
            if(l->data <= r->data)
            {
                tail->next=l;
                tail=l;
                l=l->next;
            }
            else
            {
                tail->next =r;
                tail=r;
                r=r->next;
            }  
        }
        if(l)
            tail->next=l;
        if(r)
            tail->next=r;
        return head;
}  