/*

Integer Break

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58

*/


int dp[10000];
    int rec(int n,int sum)
    {
        if(sum>n)
            return 0;
        if(sum==n)
            return 1;
        if(dp[sum]!=-1)
            return dp[sum];
        int count=INT_MIN;
        for(int i=1;i<n;i++)
            count=max(count,i*rec(n,sum+i));
        return dp[sum]=count;
    }
    int integerBreak(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return rec(n,0);
    }