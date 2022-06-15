/*

Morris Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/




//we have used the concept of threaded binary tree
//Time Complexity:O(n)  Auxiliary Space:O(1)

vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>pre;
        TreeNode *curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left ==NULL)
            {
                pre.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode *prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    pre.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return pre;   
    }