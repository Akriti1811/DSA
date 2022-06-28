/*

Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

*/



    int dp[500][500];
    int  rec(string &a,string &b,int i,int j)
    {
        
        if(i == a.length() && j == b.length())
            return 0;
        
        if(i == a.length())
            return b.length()-j;
        if(j == b.length())
            return a.length()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
     
        int count = 0;
        if(a[i] == b[j])
            count  = 0 + rec(a,b,i+1,j+1);
        else{
          count =1+ min(rec(a,b,i+1,j),min(rec(a,b,i+1,j+1),rec(a,b,i,j+1)));
        }
        
        return dp[i][j] =  count;
        
    }
      
    int minDistance(string word1, string word2) {
        
        for(int i = 0;i<500;i++)
        {
            for(int j = 0;j<500;j++)
                dp[i][j] = -1;
        }
        
        return rec(word1,word2,0,0);
        
    }