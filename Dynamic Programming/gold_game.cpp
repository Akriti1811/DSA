/*

Pots of Gold Game

Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.

Return the maximum coins X could get while playing the game. Initially, X starts the game.


Example 1:

Input:
N = 4
Q[] = {8, 15, 3, 7}
Output: 22
Explanation: Player X starts and picks 7. Player Y 
picks the pot containing 8. Player X picks the pot
containing 15. Player Y picks 3.
Total coins collected by X = 7 + 15 = 22.
Example 2:

Input:
N = 4
A[] = {2, 2, 2, 2}
Output: 4 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes an integer N and an array of size N  as input and returns the maximum coins collected by player X.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)


Constraints:
1 <= N <= 500
1 <= A[i] <= 103

*/



    int dp[500][500];
    
    int solve(vector<int> &a,int low,int high)
    {
        if(low==high)
        return a[low];
        
        if(low>high)
        return 0;
        
        if(dp[low][high]!=-1)
        return dp[low][high];
        
        return dp[low][high]=max( ( a[low]+ min( solve(a,low+1,high-1),solve(a,low+2,high) ) ) , (a[high] + min(solve(a,low+1,high-1),solve(a,low,high-2))));
        
    }
    int maxCoins(vector<int>&A,int n)
    {
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	        dp[i][j]=-1;
	   return solve(A,0,n-1);
    }