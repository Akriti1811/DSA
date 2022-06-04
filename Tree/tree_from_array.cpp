/*

Construct Binary Tree from Parent Array 

Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. 


Example 1:

Input:
N = 7
parent[] = {-1,0,0,1,1,3,5}
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
Example 2:

Input:
N = 3
parent[] = {2, 0, -1}
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
               2
             /   
            0      
          /   
         1     

Your Task:
You don't need to read input or print anything. The task is to complete the function createTree() which takes 2 arguments parent[] and N and returns the root node of the constructed tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103

*/


// METHOD 1    Time Complexity:O(n)

	void createNode(int parent[],int i,Node *created[], Node **root)
  {
      if(created[i]!=NULL)
      return;
      
      created[i]=new Node(i);
      
      if (parent[i] == -1)
      {
           *root = created[i];
            return;
      }
      
      if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);
        
      Node *p = created[parent[i]];
      
      if (p->left == NULL)
        p->left = created[i];
      else
        p->right = created[i];
  }
  
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int n)
    {
        Node *root=NULL;
        Node* created[n];
        for(int i=0;i<n;i++)
        created[i]=NULL;
        
        for(int i=0;i<n;i++)
            createNode(parent,i,created,&root);
        
        return root;
    }



// METHOD 2           Time Complexity:O(n)

    Node *createTree(int parent[], int n)
    {
        vector<Node*> ref;
        Node* root = new Node(-1);
 
        for (int i = 0; i < n; i++) 
        {
            Node* temp = new Node(i);
            ref.push_back(temp);
        }
     
        for (int i = 0; i < n; i++) 
        {
     
            if (parent[i] == -1) 
            {
                root = ref[i];
            }
            else 
            {
                if (ref[parent[i]]->left == NULL)
                    ref[parent[i]]->left = ref[i];
                else
                    ref[parent[i]]->right = ref[i];
            }
        }
        return root;
    }