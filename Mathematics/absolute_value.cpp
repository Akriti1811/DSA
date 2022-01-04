/*
You are given an interger I, find the absolute value of the interger I.

Example 1:

Input:
I = -32
Output: 32
Explanation: 
The absolute value of -32 is 32.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int absolute(int I) {
            return abs(I);
    }

};

int main() {
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--) {
        int I;
        cin >> I;
        Solution ob;
        cout << ob.absolute(I) << endl; // print the output
    }
    return 0;
} 