/*

Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/


	vector<vector<int>> dp;
    
    int palind(string &s,int l,int r)
    {
        if(l>r)
            return dp[l][r] = 0;
        
        if(l==r)
            return dp[l][r] = 1;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        if(s[l]==s[r])
            dp[l][r]= 2+palind(s,l+1,r-1);
        else
            dp[l][r]= max(palind(s,l+1,r),palind(s,l,r-1));
        return dp[l][r];
    }
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
         dp.resize(n,vector<int>(n,-1));
        return palind(s,0,n-1);   
    }