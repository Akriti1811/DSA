/*

Morris Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
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

	vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>in;
        TreeNode *curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left ==NULL)
            {
                in.push_back(curr->val);
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
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    in.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return in;
    }