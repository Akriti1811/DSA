/*

Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100


    */



//Recursion TLE

    int rec(vector<string>& strs,int ind ,int m,int n)
    {
        if(m < 0 || n < 0)
            return INT_MIN;
    
        if(ind==strs.size() || ( m==0 && n==0) ) return 0;
        
        int one=0,zero=0;
      
        for(int i=0;i<strs[ind].length();i++)
        {
            if(strs[ind][i]=='1') one++;
            else zero++;
        }
        
        int take= 1+rec(strs,ind+1,m-zero,n-one);
        int donttake=rec(strs,ind+1,m,n);
        
        return max(take,donttake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int ns=strs.size();
        int  ans=rec(strs,0,m,n);
        return ans;
    }


//DP Memoization 

    int dp[601][101][101];
    
    int rec(vector<string>& strs,int ind ,int m,int n)
    {
        if(m < 0 || n < 0)
            return INT_MIN;
    
        if(ind==strs.size() || ( m==0 && n==0) ) return 0;
        
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        
        int one=0,zero=0;
      
        for(int i=0;i<strs[ind].length();i++)
        {
            if(strs[ind][i]=='1') one++;
            else zero++;
        }
        
        int take= 1+rec(strs,ind+1,m-zero,n-one);
        int donttake=rec(strs,ind+1,m,n);
        
        return dp[ind][m][n]=max(take,donttake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        
        int  ans=rec(strs,0,m,n);
        return ans;
    }