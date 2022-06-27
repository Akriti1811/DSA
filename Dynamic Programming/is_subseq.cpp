/*

Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

*/


//Brute Force

    bool isSubsequence(string s, string t) 
    {
        int l1=s.size(),l2=t.size();
        if(l1==1 &&l2==1 && s!=t)
            return false;
        int i=0,j=0;
        while(i<l1 && j<l2)
        {
            while(j<l2 && s[i]!=t[j])
                j++;
            if(s[i]==t[j])
            i++,j++;
        }
        if(i==l1)
            return true;
        return false;
        
    }




//Recursion

    bool isSubs(string& s, string& t, int m, int n)
    {
        if(m == 0)
            return true;
        if(n == 0)
            return false;
        
        if (s[m - 1] == t[n - 1])
            return isSubs(s, t, m - 1, n - 1);
 
        return isSubs(s, t, m, n - 1);
    }
    
    
    bool isSubsequence(string s, string t) 
    {
        
       if( isSubs(s,t,s.length(),t.length()))
           return true;
        
        return false;
        
    }



//DP Memoization

     int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(s1[i-1] == s2[j-1])
            return t[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t);
        else
            return t[i][j] = isSubs(s1,s2,i,j-1,t);
    }
    
    
    bool isSubsequence(string s1, string s2) 
    {
        int m = s1.length();
        int n = s2.length();
        if(m >  n)
            return false;
        
        vector<vector<int>> t(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s1,s2,m,n,t) == m)
            return true;
        return false;
    }