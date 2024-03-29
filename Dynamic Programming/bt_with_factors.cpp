/*

Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.

*/



 int numFactoredBinaryTrees(vector<int>& a) 
    {
        int m=1e9 +7;
        int n=a.size();
        sort(a.begin(),a.end());
        vector<long>dp(n,1);
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[a[i]]=i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]%a[j]==0)
                {
                    int right=a[i]/a[j];
                    if(mp.find(right)!=mp.end())
                    {
                        dp[i]=(dp[i]+dp[j]*dp[mp[right]])%m;
                    }
                }
            }
        }
        long ans=0;
        for(long x:dp)
        {
            ans=(ans+x)%m;
        }
        return (int)(ans%m);
    }