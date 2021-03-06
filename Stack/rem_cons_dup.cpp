/*
 Removing consecutive duplicates 
Easy Accuracy: 72.28% Submissions: 8693 Points: 2
You are given string str. You need to remove the consecutive duplicates from the given string using a Stack.
 

Example 1:

Input: 
aaaaaabaabccccccc

Output: 
ababc

Explanation: 
Removing all consecutive duplicates, 
we have no duplicates consecutively.
Example 2:

Input: 
abbccbcd

Output: 
abcbcd

Explanation: 
Removing all the consecutive duplicates, 
we have the output as abcbcd.

Your Task:
This is a function problem. You need to complete the function removeConsecutiveDuplicates() that takes a string as a parameter and returns the modified string. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

*/

string removeConsecutiveDuplicates(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==st.top())
            continue;
            else
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }