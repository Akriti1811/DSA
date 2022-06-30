/*

Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104

*/



//DP Memoization

    int count(int i,int n,vector<int> &sq,vector<vector<int>>&dp )
    {
        if(n==0)
            return 0;
        if(i>=sq.size()|| n<0)
            return INT_MAX-1;
        
        if(dp[i][n]!=-1)
            return dp[i][n];
        
        int res=-1;
        if(sq[i]>n)
        {
            int donttake=count(i+1,n,sq,dp);
            res=donttake;
        }
        else
        {
            int donttake=count(i+1,n,sq,dp);
            int take=1+ count(i,n-sq[i],sq,dp);
            res=min(take,donttake);
        }
        return dp[i][n]=res;
    }
    int numSquares(int n) 
    {
        int a=sqrt(n);
        vector<int>sq(a);
        
        vector<vector<int>>dp (a+1,vector<int>(10001,-1));
        
        for(int i=0;i<a;i++)
            sq[i]=(i+1)*(i+1);
        int c=count(0,n,sq,dp);
        if(c==INT_MAX-1)
            return -1;
        return c;
    }



//DP Tabulation

    int numSquares(int n) 
    {
        int a=sqrt(n);
        vector<int>sq(a);
        
        vector<vector<int>>dp (a+1,vector<int>(10001,0));
        for(int i=1;i<=n;i++)
            dp[0][i]=INT_MAX-1;
        
        for(int i=0;i<a;i++)
            sq[i]=(i+1)*(i+1);
        
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(sq[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(1+dp[i][j-sq[i-1]],dp[i-1][j]);
            }
        }
        
        int r= dp[a][n];
        return (r==INT_MAX-1)? -1 : r;
    }