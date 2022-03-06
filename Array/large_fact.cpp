/*
Factorials of large numbers 
Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)


Constraints:
1 ≤ N ≤ 1000
*/

//Time Complexity: O(n log(n!))
//Space Complexity: O(log(n!))

	vector<int> factorial(int n)
    {
        vector<int>ans;
        ans.push_back(1);
        int mul;
        for(int x=2;x<=n;x++)
        {
            int carry=0;
            for(int i=0;i<ans.size();i++)
            {
                mul=x*ans[i]+carry;
                ans[i]=mul%10;
                carry=mul/10;
            }
            while(carry)
            {
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    /