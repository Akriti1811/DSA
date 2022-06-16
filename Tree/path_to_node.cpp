/*

Path to Given Node

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]

*/


bool hasPath(TreeNode *root, vector<int>& arr, int x)
{
    if (!root)
        return false;
     
    arr.push_back(root->val);   

    if (root->val == x)   
        return true;
     
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
     
    arr.pop_back();
    return false;           
}
vector<int> Solution::solve(TreeNode* root, int x) 
{
    vector<int> arr;
     
    if (hasPath(root, arr, x))
    return arr;
    return {};
}