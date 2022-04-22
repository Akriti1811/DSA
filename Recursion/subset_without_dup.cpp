/*
Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

 void subset(vector<int>nums,vector<vector<int>>&ans,vector<int>curr,int ind)
    {
            ans.push_back(curr);
        
        for(int i : curr)
            cout<<i<<" ";
        cout<<"\n";
        
        for(int i = ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i-1]==nums[i])
                continue;           
             curr.push_back(nums[i]);
             subset(nums,ans,curr,i+1);
             curr.pop_back();        
        }    
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> curr;
      
        subset(nums,ans,curr,0);
        return ans;
    }