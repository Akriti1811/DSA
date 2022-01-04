/*
Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.

Example 1:

Input:
A = 2 
B = 3
N = 1
Output: 2
Explanation: The first term is already
given in the input as 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double termOfGP(int a,int b,int n)
    {
        if (n==1)
        return a;
        else if(n==2)
        return b;
        else
        {
            double r=(double)b/(double)a;
            return a*pow(r,n-1);
        }
    }
};

int main()
{
    int T; //testcases total
    cin>>T;//input the testcases

    for(int i=0;i<T;i++) //white testcases are not exhausted
    {
        int A,B;
        cin>>A>>B; //input first and second term of gp
        int N;
        cin>>N; //input n
        Solution ob;
        cout<<floor(ob.termOfGP(A,B,N))<<endl;
    }

    return 0;
}