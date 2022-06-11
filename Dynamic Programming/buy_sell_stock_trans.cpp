/*

Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

*/



// Top Down DP (Memoization)

	int dp[100000][2];
    int rec(vector<int> &n,int i,int cond,int fees)
    {
        if(i == n.size())
            return 0;
        if(dp[i][cond]!=-1)
            return dp[i][cond];
        
        int x=INT_MIN,y=INT_MIN;
        
        if(cond == 0)
        {
            x = max(-n[i] + rec(n,i+1,1,fees),rec(n,i+1,0,fees));
        }
        else
        {
            y = max(n[i] -fees+ rec(n,i+1,0,fees),rec(n,i+1,1,fees));
        }
        return dp[i][cond]=max(x,y);
    }
     
    int maxProfit(vector<int>& prices, int fee) 
    {
        for(int i=0;i<prices.size();i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return rec(prices,0,0,fee);
    }




// Bottom Up DP Tabulation

    int maxProfit(vector<int>& prices, int fee) 
    {
        int dp[100000][2],n=prices.size();
        for(int i=0;i<prices.size();i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]); 
    }