/*

Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19

*/

//concept of catalan number

    int numTrees(int n) 
    {
        if(n==1)
            return 1;
        int catalan[n+1];
        catalan[0]=1,catalan[1]=1;
        for(int i=2;i<=n;i++)
        {
            catalan[i]=0;
            for(int j=0;j<i;j++)
            {
                catalan[i]+=catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }