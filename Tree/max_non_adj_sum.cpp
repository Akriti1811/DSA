/*

Maximum sum of Non-adjacent nodes 

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000

*/




// The first of the pair indicates maximum sum when the data of a node is included and the second indicates maximum sum when the data of a particular node is not included. 


pair<int,int> maxSum(Node *root)
  {
      
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    
    pair<int, int> sum1 = maxSum(root->left);
    pair<int, int> sum2 = maxSum(root->right);
    pair<int, int> sum;
 
    sum.first = sum1.second + sum2.second + root->data;
 
    sum.second = max(sum1.first, sum1.second) +
                 max(sum2.first, sum2.second);
 
    return sum;
  }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> res = maxSum(root);
        return max(res.first, res.second);
    }