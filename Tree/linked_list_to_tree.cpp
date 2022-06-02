/*

Make Binary Tree From Linked List 

Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 



Example 1:

Input:
N = 5
K = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Example 2:

Input:
N = 5
K = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2    1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Your Task:
The task is to complete the function convert() which takes head of linked list and root of the tree as the reference. The driver code prints the level order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

*/


void convert(Node *head, TreeNode *&root) 
{
    queue<TreeNode*>q;
    if(head==NULL)
    {
        root==NULL;
        return;
    }
    
    root=new TreeNode(head->data);
    head=head->next;
    q.push(root);
    
    while(head)
    {
        TreeNode *parent=q.front();
        q.pop();
        
        TreeNode *leftChild=NULL,*rightChild=NULL;
        leftChild=new TreeNode(head->data);
        head=head->next;
        q.push(leftChild);
        
        if(head)
        {
            rightChild=new TreeNode(head->data);
            head=head->next;
            q.push(rightChild);
        }
        parent->left=leftChild;
        parent->right=rightChild;
    }
    
}