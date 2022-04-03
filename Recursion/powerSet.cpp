/*
 Power Set Using Recursion 
 
You are given a string. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.

Example 1:

Input:
s = a
Output: a
Explanation: empty string and a 
are only sets.
Example 2:

Input:
s = abc
Output: a ab abc ac b bc c
Explanation: empty string, 
a, ab, abc, ac, b, bc, c 
are the sets.
Your Task:
You don't need to read input or print anything. You only need to complete the function powerSet that takes string s as parameter and returns a list of subsets. The lexicographic-sorting and printing is done automatically by the driver code.

Expected Time Complexity: O(2|s|).
Expected Auxiliary Space: O(|s|). 

Constraints:
1 <= |s| <= 10
*/

void strSet(string s,vector <string> &ans,string curr,int ind)
{
    if(ind==s.length())
    {
        ans.push_back(curr);
        return;
    }
    strSet(s,ans,curr,ind+1);
    strSet(s,ans,curr+s[ind],ind+1);
}

//Function to return the lexicographically sorted power-set of the string.
vector <string> powerSet(string s)
{
   vector <string> ans;
   string curr="";
   strSet(s,ans,curr,0);
    return ans;
}