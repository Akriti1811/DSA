/*
Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:
Input: head = []
Output: []
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Time Complexity: O(nlogn)
Auxillay Space: O(logn)
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid=midnode(head);
        ListNode* left=sortList(head);
        ListNode* right =sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l,ListNode* r)
    {
        ListNode * t=new ListNode();
        ListNode * temp=t;
        while(l && r)
        {
            if(l->val < r->val)
            {
                temp->next=l;
                l=l->next;
            }
            else
            {
                temp->next=r;
                r=r->next;
            }
            
            temp=temp->next;  
        }
        if(l)
            temp->next=l;
        if(r)
            temp->next=r;
        return t->next;
    }
    ListNode * midnode(ListNode* head)
    {
        ListNode *midprev=head;
        while(head->next && head->next->next)
        {
            midprev=midprev->next;
            head=head->next->next;
        }
        ListNode* mid=midprev->next;
        midprev->next=NULL;
        return mid;
    }    
};



/*
Time Complexity: O(nlogn)
Auxillay Space: O(1)
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid=midnode(head);
        ListNode* left=sortList(head);
        ListNode* right =sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l,ListNode* r)
    {
        if(l==NULL)
            return r;
        if(r==NULL)
            return l;
        ListNode *head=NULL,*tail=NULL;
        if(l->val<=r->val)
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
            if(l->val <= r->val)
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
    ListNode * midnode(ListNode* head)
    {
        ListNode *midprev=head;
        while(head->next && head->next->next)
        {
            midprev=midprev->next;
            head=head->next->next;
        }
        ListNode* mid=midprev->next;
        midprev->next=NULL;
        return mid;
    }    
};