/*
Minimum adjacent difference in a circular array 
Given an array Arr of n integers arranged in a circular fashion. Your task is to find the minimum absolute difference between adjacent elements.

Example 1:

Input:
n = 7
Arr[] = {8,-8,9,-9,10,-11,12}
Output: 4
Explanation: The absolute difference 
between adjacent elements in the given 
array are as such: 16 17 18  19 21 23 4
(first and last). Among the calculated 
absolute difference the minimum is 4.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minAdjDiff(int a[], int n)
    {    
        int d=abs(a[0]-a[n-1]);
        for(int i=0;i<n-1;i++)
        {
            int s=abs(a[i]-a[i+1]);
            d=min(d,s);
        }
        return d;
    }
};
int main()
{
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n]; 
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; 
        }
        Solution ob;
        cout << ob.minAdjDiff(arr, n) << endl;
    }
    return 0;
} 