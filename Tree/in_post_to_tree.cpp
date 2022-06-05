/*

Tree from Postorder and Inorder 


Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3
 

Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.
The generated output contains the preorder traversal of the constructed tree.

 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 103
1 <= in[i], post[i] <= 103

*/



//Time Comp:O(n^2)

Node *build(int in[], int post[], int start,int end,int &ind)
{
    if(start>end)
        return NULL;
        
    int val=post[ind];
    Node *temp=new Node(val);
    ind--;
    if(start==end)
    return temp;
    int j;
    for(j=start;j<=end;j++)
    {
        if(in[j]==val)
        break;
    }
    temp->right=build(in, post, j+1,end,ind);
    temp->left=build(in, post, start,j-1,ind);
    
    return temp;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) 
{
    int ind=n-1;
    return build(in,post,0,n-1,ind);
}


//Time Comp:O(n)    ---  used hash map to store the indexes of inorder traversal

Node *build(int in[], int post[], int start,int end,int &ind, unordered_map<int,int> &mp)
{
    if(start>end)
        return NULL;
        
    int val=post[ind];
    Node *temp=new Node(val);
    ind--;
    if(start==end)
    return temp;
    int j=mp[val];
    temp->right=build(in, post, j+1,end,ind,mp);
    temp->left=build(in, post, start,j-1,ind,mp);
    
    return temp;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) 
{
    int ind=n-1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    mp[in[i]]=i;
    return build(in,post,0,n-1,ind,mp);
}