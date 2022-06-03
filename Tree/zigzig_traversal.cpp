/*

ZigZag Tree Traversal 


Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 <= N <= 104

*/

vector <int> zigZagTraversal(Node* node)
    {
    	vector<int>v;
        if(node==NULL)
        return v;
        
        stack<Node*>s1,s2;
        s1.push(node);
        v.push_back(node->data);
        
        
        while(!s1.empty() || !s2.empty())
        {
                while(s1.empty()==false)
                {
                    Node *t =s1.top();
                    s1.pop();
                    if(t->right != NULL)
                    {
                        s2.push(t->right);
                        v.push_back(t->right->data);
                    }
                    if(t->left != NULL)
                    {
                        s2.push(t->left);
                        v.push_back(t->left->data);
                    }
                    
                }
            
                while(s2.empty()==false)
                {
                    Node *t =s2.top();
                    s2.pop();
                    
                    if(t->left != NULL)
                    {
                        s1.push(t->left);
                        v.push_back(t->left->data);
                    }
                    
                    if(t->right != NULL)
                    {
                        s1.push(t->right);
                        v.push_back(t->right->data);
                    }
                }
            }
        
        return v;
    }