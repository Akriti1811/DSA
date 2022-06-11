/*

Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/


	int dp[100000][2];
    int rec(vector<int> &n,int i,int cond)
    {
        if(i >= n.size())
            return 0;
        
        if(dp[i][cond]!=-1)
            return dp[i][cond];
        
        int x=INT_MIN,y=INT_MIN;
        if(cond == 0)
        {
            x = max(-n[i] + rec(n,i+1,1),rec(n,i+1,0));
        }
        else
        {
            y = max(n[i] + rec(n,i+2,0),rec(n,i+1,1));
        }
        return dp[i][cond]=max(x,y);
    }
    int maxProfit(vector<int>& prices) 
    {
        for(int i=0;i<prices.size();i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return rec(prices,0,0);   
    }