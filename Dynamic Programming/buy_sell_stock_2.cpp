/*


Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

*/


// Time Complexity:O(n), Auxiliary Space:O(1)

    int maxProfit(vector<int>& prices) 
    {
        int buy,sell,n=prices.size(),ans=0,i=0;
        if(n==1)
            return 0;
        while(i<n)
        {
            while(i<n-1 && prices[i+1]<prices[i])
                i++;
            buy=prices[i];
            while(i<n-1 && prices[i+1]>prices[i])
                i++;
            sell=prices[i];
            if(buy==sell)
                i++;
            ans+=sell-buy;
        }
        return ans;
    }





// Time Complexity:O(n), Auxiliary Space:O(1)

    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size(),ans=0,i=0;
        while(i<n-1)
        {
            ans+=max(prices[i+1]-prices[i],0);
            i++;
        }
        return ans;
    }




// Time Complexity:O(n), Auxiliary Space:O(1)  DP (bottom up dp + iteration)

    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size(),currbuy=INT_MIN,currsell=0;
        for(int i=0;i<n;i++)
        {
            int prevbuy=currbuy,prevsell=currsell;
            
            currbuy=max(prevbuy, prevsell-prices[i]);
            
            currsell=max(prevsell, prices[i]+currbuy);
        }
        return currsell;
    }


// Time Complexity:O(n), Auxiliary Space:O(n)  DP (top down dp)

    int dp[100000][2];
    int rec(vector<int> &n,int i,int cond)
    {
        if(i == n.size())
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
            y = max(n[i] + rec(n,i+1,0),rec(n,i+1,1));
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



// Time Complexity:O(n), Auxiliary Space:O(n)  DP (bottom up dp , tabulation)

 	int maxProfit(vector<int>& prices) 
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
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);   
    }