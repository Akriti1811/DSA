/*
Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

	void comb(vector<int> nums,vector<vector<int>>&ans,vector<int>curr,int ind,int target)
    {
         if(target==0)
        ans.push_back(curr);
        
        if(ind >= nums.size()||target < 0)
            return;
        
       for(int i = ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i-1]==nums[i])
                continue;    
            curr.push_back(nums[i]);
            comb(nums,ans,curr,i+1,target-nums[i]);
            curr.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        vector<int>curr;
        
        sort(nums.begin(),nums.end());
        comb(nums,ans,curr,0,target);
        return ans;   
    }