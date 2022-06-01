	

/*

Check for Balanced Tree 
  
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 106

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree


*/


//Brute Force Time Comp: O(n^2)



	int height(Node *root)
    {
        if(root==NULL)
        return 0;
        else
        return 1+max(height(root->left),height(root->right));
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL )
        return true;
        if(abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) &&isBalanced(root->right))
        return true;
        else return false;
    }


//Efficient Approach   Time Comp: O(n)


	bool balance(Node *root,int *height)
    {
        int lh=0,rh=0;
        if(root==NULL)
        {
            height=0;
            return 1;
        }
        
        int l=balance(root->left,&lh);
        int r=balance(root->right,&rh);
        
        *height=max(lh,rh)+1;
        
        if(abs(lh-rh)>1)
        return false;
        else
        return (l&&r);
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        int height=0;
        return balance(root,&height);
    }