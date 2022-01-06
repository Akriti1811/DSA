/*
You are given two numbers a and b. You need to find the multiplication of a and b under modulo M (M as 109+7).

Example 1:

Input:
a = 92233720368547758
b = 92233720368547758
Output: 484266119
Explanation: Multiplication of a and b 
under modulo M will be 484266119.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int multiplicationUnderModulo(long long a,long long b)
    {
        long long c=1000000007;
        return ((a%c)*(b%c))%c;
    }
};

int main() 
{
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    Solution ob;
	    cout<<ob.multiplicationUnderModulo(a,b)<<endl;
	}
	return 0;
} 