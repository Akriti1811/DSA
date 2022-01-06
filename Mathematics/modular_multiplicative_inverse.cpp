/*
Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.

Example 1:

Input:
a = 3
m = 11
Output: 4
Explanation: Since (4*3) mod 11 = 1, 4 
is modulo inverse of 3. One might think,
15 also as a valid output as "(15*3)
mod 11"  is also 1, but 15 is not in 
ring {0, 1, 2, ... 10}, so not valid.
 
*/


#include<iostream>
using namespace std;
class Solution{
    public:
    int modInverse(int a, int m)
    {
        int ans = -1;
        for(int i=1;i<m;i++)
        {
            if((i*a)%m == 1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,m;
		cin>>a>>m;
		Solution ob;
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
} 