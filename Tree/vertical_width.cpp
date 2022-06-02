/*

Vertical Width of a Binary Tree 

Given a Binary Tree of N nodes. Find the vertical width of the tree.

Example 1:

Input:
          1
       /    \
      2      3
     / \    / \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
 

Example 2:

Input:
      1
    /  \
   2    3
Output: 3
 

Your Task:

You don't have to read input or print anything. Your task is to complete the function verticalWidth() which takes root as the only parameter, and returns the vertical width of the binary tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

*/


void width(Node *root,int &mini,int &maxi,int curr=0)
{
    if(root==NULL)
    return ;
    width(root->left,mini,maxi,curr-1);
    if(mini>curr)
    mini=curr;
    if(maxi<curr)
    maxi=curr;
    width(root->right,mini,maxi,curr+1);
    
}
//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(root==NULL)
    return 0;
    int maximum = 0, minimum = 0;
    width(root, minimum,maximum, 0);
    return (abs(minimum) + maximum) + 1;
}