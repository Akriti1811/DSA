/*

Level order traversal in spiral form 

Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105

*/

vector<int> findSpiral(Node *node)
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
                    if(t->left != NULL)
                    {
                        s2.push(t->left);
                        v.push_back(t->left->data);
                    }
                    if(t->right != NULL)
                    {
                        s2.push(t->right);
                        v.push_back(t->right->data);
                    }
                }
            
                while(s2.empty()==false)
                {
                    Node *t =s2.top();
                    s2.pop();
                    
                    if(t->right != NULL)
                    {
                        s1.push(t->right);
                        v.push_back(t->right->data);
                    }
                    if(t->left != NULL)
                    {
                        s1.push(t->left);
                        v.push_back(t->left->data);
                    }
                }
            }
        
        return v;
}
