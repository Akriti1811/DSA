/*

Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

*/


    TreeNode * build(vector<int>& num,int low,int high)
    {
        if (low > high)
            return NULL;
        
        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = build(num, low, mid - 1);
        node->right = build(num, mid + 1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return build(nums,0,nums.size()-1);
    }