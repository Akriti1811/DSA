/*

Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/


//DP Memoization

    int dp[13][10001];
    
    int coin(vector<int>&coins, int i,int amt)
    {
        if(amt==0)
            return 0;
        if(i>=coins.size()|| amt<0)
            return INT_MAX-1;
        
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        int res=-1;
        if(coins[i]>amt)
        {
            int donttake=coin(coins,i+1,amt);
            res=donttake;
        }
        else
        {
            int donttake=coin(coins,i+1,amt);
            int take=1+ coin(coins,i,amt-coins[i]);
            res=min(take,donttake);
        }
        return dp[i][amt]=res;
            
            
            
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp,-1,sizeof(dp));
        int c=coin(coins,0,amount);
        if(c==INT_MAX-1)
            return -1;
        return c;
    }




//DP Tabulation

     int dp[13][100000];
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=(j==0)?0:INT_MAX-1;
            }          
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }
        
        int r= dp[n][amount];
        return (r==INT_MAX-1)? -1 : r;
    }