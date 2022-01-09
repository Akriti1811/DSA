/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& a, int n, int k)
    {
        for(int i=0;i<n;i+=k)
        {
            int j=i,l=min(n-1,i+k-1);
            while(j<l)
               swap(a[j++],a[l--]);
        }
    }
};
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

