/*
Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

	bool ispalin(string s)
    {
        cout<<s<<"\n";
        int start=0,end=s.length()-1;
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void part(string s,vector<vector<string>> &ans,vector<string> &curr,int ind)
    {
        if(ind == s.length())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = ind;i<s.length();i++)
        {
            
           if(ispalin(s.substr(ind,i+1)))
           {
            curr.push_back(s.substr(ind,i+1));
            part(s.substr(i+1),ans,curr,ind);
            curr.pop_back();    
           }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>curr;
        part(s,ans,curr,0);
        return ans;
    }