/*

Coin Change 2

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

*/




//Dp Memoization 

    int dp[301][5001];
    int ways(vector<int>&coins,int i,int amt)
    {
        if(amt==0)
            return 1;
        if(amt<0 || i>=coins.size())
            return 0;
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        int res=0;
        if(coins[i]>amt)
        {
            res=ways(coins,i+1,amt);
        }
        else
        {
            res=ways(coins,i+1,amt)+ ways(coins,i,amt-coins[i]);
        }
        return dp[i][amt]=res;
    }
    int change(int amount, vector<int>& coins) 
    {
        memset(dp,-1,sizeof(dp));
        int c=ways(coins,0,amount);
        return c;
    }




//DP Tabulation

    int dp[301][5001];
   
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=(i==0)?0:1;
            }          
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }
        }
        
        
        return dp[n][amount]; 
    }