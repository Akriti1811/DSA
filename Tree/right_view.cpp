/*

Right View of Binary Tree 

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Your Task:
Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/


vector<int> rightView(Node *root)
    {
       vector<int>v;
       if(root==NULL)
        return v;
        
        queue<Node*>q;
        q.push(root);
        
        while(q.empty()==false)
        {
            int size=q.size();
            while(size--)
            {
                Node *t =q.front();
                if(size==0)
                v.push_back(t->data);
                q.pop();
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            
        }
        return v;
    }