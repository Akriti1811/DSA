/*

Given two numbers a and b, find the sum of a and b. Since the sum can be very large, find the sum modulo 109+7.
Example 1:

Input:
a = 9223372036854775807
b = 9223372036854775807
Output: 582344006
Explanation: 
9223372036854775807 + 9223372036854775807 
= 18446744073709551614.
18446744073709551614 mod (109+7)
= 582344006

*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
        long long c=1000000007;
        return ((a%c)+(b%c))%c;
    }
};

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    Solution ob;
	    cout<<ob.sumUnderModulo(a,b)<<endl;
	}
	return 0;
}