/*

Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/


    string longestPalindrome(string s) 
    {
        int l=s.size();
        vector<vector<int>>dp(l+1,vector<int>(l+1,0));
        for(int i=1;i<=l;i++)
            dp[i][i]=1;
        
        int maxlen=1,start=0;
        
        for(int i=2;i<=l;i++)
        {
            if(s[i-1]==s[i-2])
            {
                dp[i-1][i]=2;
                start=i-2;maxlen=2;
            }
        }
        for(int i=l-2 ;i>=1;i--)
        {
            for(int j=i+2;j<=l;j++)
            {
                if(s[i-1]==s[j-1] && dp[i+1][j-1]!=0)
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                    if(maxlen<dp[i][j])
                    {
                        maxlen=dp[i][j];
                        start=i-1;
                    }
                    
                }
            }
        }
        
        string ans=s.substr(start,maxlen);
        return ans;
    }