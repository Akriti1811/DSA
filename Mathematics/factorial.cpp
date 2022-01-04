/*
Given a positive integer N. The task is to find factorial of N.

Example 1:

Input:
N = 4
Output: 24
Explanation: 4! = 4 * 3 * 2 * 1 = 24
*/

#include <bits/stdc++.h>
using namespace std;
long long factorial(int);

class Solution{
    public:
    long long factorial(int n) 
    {
        if(n==0||n==1)
        return 1;
        return n*factorial(n-1);
    }

};
int main() {
    int T, N;
    cin >> T; // input number of testcases
    while (T--) {
        cin >> N; // input n
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0;
}