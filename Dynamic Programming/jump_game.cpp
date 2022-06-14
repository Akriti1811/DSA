/*


Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/

	bool canJump(vector<int>& A) 
    {
        int n=A.size();
        int last=n-1,i,j;
        for(i=n-2;i>=0;i--)
        {
            if(i+A[i]>=last)last=i;
        }
        return last==0;

    }




Recursive
class Solution {
    public:
    bool canJump(vector<int>& nums) {
              return solve(0,nums); 
    }
    bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true;
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
                  if(solve(k,nums)){
                return true;
            }      
        }
        return false;
    }
};


Recursive+Memoization
class Solution {
    vector<int> memo;
     public:
     bool canJump(vector<int>& nums) {
          memo.assign(nums.size(),-1);
          return solve(0,nums);   
     }
     bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true;
        if(memo[i]!=-1) return memo[i];
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
             if(solve(k,nums)){
                return memo[i]=true;
             } 
        }
        return memo[i]=false;
    }
}



DP (Updated)
class Solution {
    vector<int> memo;
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=true;
        
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
  }
};
