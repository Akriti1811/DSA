/*

Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/



string removeDuplicateLetters(string s) 
    {
        int n=s.size();
        vector<int>last(26,-1);
        vector<bool>visit(26,false);
        
        for(int i=0;i<n;i++)
            last[s[i]-'a']=i;
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(visit[s[i]-'a'])
                continue;
            while(!ans.empty() && ans.back()>=s[i] && last[ans.back()-'a']>i)
            {
                visit[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=s[i];
            visit[s[i]-'a']=true;
        }
        return ans;
    }
};