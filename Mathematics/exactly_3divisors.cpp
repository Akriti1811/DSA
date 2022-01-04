/*
Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

 

Example 1:

Input:
N = 6
Output: 1
Explanation: The only number less than 6 with 
3 divisors is 4.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
     bool isPrime(int N)
    {
        if(N<=1) 
        return false;
        
        if(N==2 || N==3) 
        return true;
        
        for(int i=2;i*i<=N;i++)
        {
            if(N%i==0) 
            return false;
        }
        return true;
    }
    int exactly3Divisors(int n)
    {
        int c=0;
        int m=sqrt(n);
        for(int i=2;i<=m;i++)
        {
            if(isPrime(i))
            c++;
        }
        return c;
    }
};

int main()
 {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}