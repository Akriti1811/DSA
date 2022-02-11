/*
Count total set bits 
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
Example 1:
Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
Example 2:
Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), 
the total number of set bits is 35.
Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).
Constraints:
1 ≤ N ≤ 108
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        n++;
        int pow=2;
        int res=n/2;
        while(pow<=n)
        {
            int totpair=n/pow;
            res+=(totpair/2) *pow;
            res+=(totpair&1)?(n%pow):0;
            pow=pow<<1;
        }
        return res;
    }
};
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}