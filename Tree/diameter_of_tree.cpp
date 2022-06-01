/*

Diameter of a Binary Tree 

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000

*/


//Time Complexity: O(n)


    int treeDiameter(Node *root,int *height)
  {
      int lh=0,rh=0;
      
      if(root==NULL)
      {
          *height=0;
          return 0;
      }
      
      int ld=treeDiameter(root->left,&lh);
      int rd=treeDiameter(root->right,&rh);
      
      *height=max(lh,rh)+1;
      
      return max(max(ld,rd),1+lh+rh);
  }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) 
    {
        int height=0;
        return treeDiameter(root, &height);
    }

//Brute Force Time Complexity: O(n^2)

int height(Node *root)
  {
      if(root==NULL)
      return 0;
      else
      return 1+max(height(root->left),height(root->right));
  }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) 
    {
        int d=0;
        while(root!=NULL)
        {
            int ht=1+height(root->left)+height(root->right);
            if(d>ht)
            break;
            d=max(d,ht);
            if(height(root->left)>height(root->right))
                root=root->left;
            else
                root=root->right;
        }
        return d;
    }
