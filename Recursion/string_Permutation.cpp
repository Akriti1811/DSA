/*
String Permutations 

Given a string S. The task is to find all permutations of a given string.

Example 1:

Input:
S = ABC
Output: ABC ACB BAC BCA CAB CBA 
Example 2:

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
 

Your Task:
This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

Constraints:
1 ≤ size of string ≤ 5

Expected Time Complexity: O(N * N!), N = length of string.
Expected Auxiliary Space: O(1)

*/

void perm(string s, vector<string> &ans,int left,int right)
    {
        if(left==right)
        {
            ans.push_back(s);
            return;
        }
        for(int i=left;i<=right;i++)
        {
            swap(s[left],s[i]);
            perm(s,ans,left+1,right);
            swap(s[left],s[i]);
        }
    }
    vector<string> permutation(string S)
    {
        vector <string >ans;
        perm(S,ans,0,S.length()-1);
        sort(ans.begin(),ans.end());
        return ans;
    }