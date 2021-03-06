/*

Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/


	int maxSubArray(vector<int>& nums) 
    {
        int m=INT_MIN;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s=max(s+nums[i],nums[i]);
            m=max(s,m);
        }
        return m1;
        
    }




    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n],m=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=nums[i]+max(dp[i-1],0);
            m=max(m,dp[i]);
        }
        return m;
        
    }