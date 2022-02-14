/*
Power of 2
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
Example 1:
Input: N = 1
Output: YES
Explanation:1 is equal to 2 
raised to 0 (20 = 1).
Example 2:
Input: N = 98
Output: NO
Explanation: 98 cannot be obtained
by any power of 2.
Your Task:Your task is to complete the function isPowerofTwo() which takes n as a parameter and returns true or false by checking if the given number can be represented as a power of two or not.
Expected Time Complexity:O(log N).
Expected Auxiliary Space:O(1).
Constraints:
0 ≤N ≤1018
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long x)
    {
        if(x && !(x &(x-1)))   
        return true;
        else
        return false;
    }
};
int main()
{
    int t;
    cin>>t;//testcases
    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }
    return 0;
}