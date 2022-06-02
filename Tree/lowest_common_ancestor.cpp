/*

Lowest Common Ancestor in a Binary Tree 

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 
Your Task:
You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output. 

Expected Time Complexity:O(N).
Expected Auxiliary Space:O(Height of Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/


//Brute Force    Time Complexity:O(n^2)

	bool visit(Node* root,int n)
    {
        if(root==NULL)
        return false;
        if(root->data==n)
        return true;
        if(visit(root->left,n)||visit(root->right,n))
        return true;
        return false;
    }
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       Node* ans=root;
       while(visit(root,n1)&&visit(root,n2))
       {
           ans=root;
           if(visit(root->left,n1))
           root=root->left;
           else
           root=root->right;
       }
       return ans;
    }

// Time Complexity:O(n) 
// 2 traversal of tree and extra space for storing path

	bool path(Node* root,vector<Node*> &p,int n)
    {
        if(root==NULL)
        return false;
        p.push_back(root);
        if(root->data==n)
        return true;
        if( path(root->left,p,n) || path(root->right,p,n) )
        return true;
        p.pop_back();
        return false;
    }
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
      vector<Node*> path1,path2;
      if(path(root,path1,n1)==false || path(root,path2,n2)==false)
      return NULL;
      Node *temp;
      for(int i=0; i<path1.size() && i<path2.size() ;i++)
      {
          if(path1[i] == path2[i])
          temp= path1[i];
      }
       
      return temp;
    }

//Efficient Approach - Need only one traersal of tree (It assumes that both n1 and n2 are present on tree)
//Time Complexity: O(n)

Node* lca(Node* root ,int n1 ,int n2 )
    {
        
        if(root==NULL)
        return NULL;
        
        if(root->data==n1 || root->data==n2)
        return root;
      
      Node *lca1=lca(root->left,n1,n2);
      Node *lca2=lca(root->right,n1,n2);
      
      if(lca1!=NULL && lca2!=NULL)
      return root;
      
      if(lca1!=NULL)
      return lca1;
      else
      return lca2;
      
    }