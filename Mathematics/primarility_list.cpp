/*
A prime number is a number which is only divisible by 1 and itself.
Given number N check if it is prime or not.

Example 1:

Input:
N = 5
Output: Yes
Explanation: 5 is only divisible by 1 
and itself. So, 5 is a prime number.
 
*/

#include<bits/stdc++.h>
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

};

int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        Solution ob;
        if(ob.isPrime(N)) 
            cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}